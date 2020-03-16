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

void Jsprite::initSprite(unsigned char* bmpsrc)
{
	//sprites location in world
	fLoc.x = 110;  
	fLoc.y = 50; 
	fLoc.z = 0;

	//sprite dimensions
	fWidth = 64;
	fHeight = 64;

	//whether the sprite is visible or not
	fVisibility = true;

	//current direction		(unit velocity)
	fDir.x = 0;
	fDir.y = 0;
	fDir.z = 0;

	//speed sprite is travelling
	fSpeed = 0;

	//number of frames of animation
	fFramesOfAnim = 0;

	//current frame of animation
	fTextureIndex = 7;

	fBmpArray = bmpsrc;

	//sprite index for this sprite
	//Does this mean 1-128? i think so
	fSprite[0] = ham_CreateObj((void*)bmpsrc,//ptr to sprite
									0,						//sprite shape
									3,	//64x64				//sprite size
									OBJ_MODE_NORMAL,		//display sprite normal(nofx)
									1,	//256 pal			//color/palette mode
									0,						//palette index if mode 0
									0,						//support mosaic (0 = off)
									0,						//horiz flip on/off
									0,						//vert flip on/off
									0,						//priority(0-high, 3-low)
									0,						//doublesize on/off
									fLoc.x,					//x screen coord
									fLoc.y	);				//y screen coord

									//me thinks the screen coords should be fixed...
									//if map will be rotated and moving about, not sprite
}

ImpSprAttr(8, Width)
ImpSprAttr(8, Height)
ImpSprAttr(8, Speed)
ImpSprAttr(8, FramesOfAnim)
ImpSprAttr(8, TextureIndex)

ImpSpr3DAttr(16,Loc)
ImpSpr3DAttr(8, Dir)


void Jsprite::changeTexture()
{
	//change the planes texture
	ham_UpdateObjGfx(fSprite[0],(void*)(fBmpArray+(4096*fTextureIndex)));
	
	//send updated sprite to hardware
	ham_CopyObjToOAM();
}
















