//  Filename:		Jsprite.cpp
//	Author:			John Carlson
//	Description:	This is my class to encapsulate the business of dealing with sprites
//	
//	Changelog:		started 1-30-2003
//

#include "Jsprite.h"


Jsprite::Jsprite()
{
	//hmm.. do nothing


}

//here are the implementations of get and sets
ImpSprAttr(8, SpriteNum)
ImpSprAttr(8, Width)
ImpSprAttr(8, Height)
ImpSprAttr(8, Speed)
ImpSprAttr(8, FramesOfAnim)
ImpSprAttr(8, TextureIndex)

ImpSprAttr(16, RotationAngle)
ImpSprAttr(8,  RotationSet)

ImpSpr3DAttr(16,Loc)
ImpSpr3DAttr(8, Dir)




void Jsprite::initSprite(unsigned char* bmpsrc,	//ptr to bmp array
						u8 fxmode,				//display sprite normal(nofx)
						u8 palmode,				//color/palette mode
						u8 palindex,			//palette index if mode 0
						u8 mosaic,				//support mosaic (0 = off)
						u8 hflip,				//horiz flip on/off
						u8 vflip,				//vert flip on/off
						u8 prio,				//priority(0-high, 3-low)
						u8 dblsize,				//doublesize on/off
						u16 xscreen,			//x screen coord
						u16 yscreen,			//y screen coord
						u8 height,				//sprite height
						u8 width,				//sprite width
						u8 numtexts,			//number of textures
						u8 tindex,				//starting texture
						bool rotable,			//is sprite rotateable
						u8 rotSet				//what rotation set does it work with
						)
{
	//sprites location in world
	fLoc.x = xscreen;  
	fLoc.y = yscreen; 
	fLoc.z = 0;

	//sprite dimensions
	fWidth = width;
	fHeight = height;

	//whether the sprite is visible or not
	fVisibility = true;

	//current direction		(unit velocity)
	fDir.x = 0;
	fDir.y = 1;
	fDir.z = 0;

	//speed sprite is travelling
	fSpeed = 0;

	//number of frames of animation
	fFramesOfAnim = numtexts;

	//current frame of animation
	fTextureIndex = tindex;

	fRotationAngle = 0;
	fRotationSet = rotSet;

	fBmpArray = bmpsrc;

	u8 sprShape,sprSize;

	if (fHeight == fWidth)
		sprShape = 0;
	else if(fHeight > fWidth)
		sprShape = 1;
	else
		sprShape = 2;


	if(fHeight * fWidth < 256)
		sprSize = 0;
	else if(fHeight * fWidth == 256)
		sprSize = 1;
	else if(fHeight * fWidth > 1024)
		sprSize = 3;
	else
		sprSize = 2;
		
	fSpriteNum = ham_CreateObj((void*)fBmpArray,			//ptr to sprite
									sprShape,				//sprite shape (depends on size)
									sprSize,				//sprite size
									fxmode,					//display sprite normal(nofx)
									palmode,				//color/palette mode
									palindex,				//palette index if mode 0
									mosaic,					//support mosaic (0 = off)
									hflip,					//horiz flip on/off
									vflip,					//vert flip on/off
									prio,					//priority(0-high, 3-low)
									dblsize,				//doublesize on/off
									fLoc.x,					//x screen coord
									fLoc.y);				//y screen coord

									//me thinks the screen coords should be fixed...
									//if map will be rotated and moving about, not sprite

	if(rotable == true)
	{	
		ham_SetObjRotEnable(fSpriteNum,	   //sprite number
							1);			   //0-off 1-on
	
		ham_SetObjRotSetSelect(fSpriteNum, //sprite number
							   rotSet);	   //which rotation set to use
	}


	
}

void Jsprite::changeTexture()
{
	//change the planes texture
	ham_UpdateObjGfx(fSpriteNum,(void*)(fBmpArray+(4096*fTextureIndex)));
	
	//send updated sprite to hardware
	//ham_CopyObjToOAM();
}


void Jsprite::updateLocation()
{
	fLoc.x = fLoc.x+fDir.x*fSpeed;	//location + direction*speed
	fLoc.y = fLoc.y+fDir.y*fSpeed;
	ham_SetObjXY(fSpriteNum,			//this sprites' handle
				 fLoc.x,
				 fLoc.y);	//location + direction*speed

	ham_DrawText(10,10,"YLoc:%3d",fLoc.y);
	ham_DrawText(10,9,"YLoc:%3d",fLoc.y%160);
}


unsigned char* Jsprite::getBitmapArray()
{
	return fBmpArray;
}

void Jsprite::rotateLeft()
{
	fRotationAngle--;
	
	ham_RotObjDefineSet(fRotationSet,	//rotation set (0-31)
						fRotationAngle,	//rotation angle
						0x100,			//x zoom
						0x100);			//y zoom
}

void Jsprite::rotateRight()
{
	fRotationAngle++;

	ham_RotObjDefineSet(fRotationSet,	//rotation set (0-31)
						fRotationAngle,	//rotation angle
						0x100,			//x zoom
						0x100);			//y zoom
}

bool Jsprite::getVisibility()
{
	return fVisibility;
}

void Jsprite::enableVisibility()
{
	ham_SetObjVisible(  fSpriteNum, 1	);
	fVisibility = true;

}

void Jsprite::disableVisibility()
{
	ham_SetObjVisible(  fSpriteNum, 0	);
	fVisibility = false;
}

void Jsprite::toggleVisibility()
{
	if (fVisibility) {
		disableVisibility();
	}
	else
	{
		enableVisibility();
	}
}







