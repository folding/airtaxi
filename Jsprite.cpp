#include "Jsprite.h"

Jsprite::Jsprite(const unsigned char bmpArr)
{
	//sprites location in world
	fLoc.x = 0;  
	fLoc.y = 0; 
	fLoc.z = 0;

	//sprite dimensions
	fWidth = 0;
	fHeight = 0;

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
	fTextureIndex = 0;

	fBmpArray = &bmpArr;

	//sprite index for this sprite
	//Does this mean 1-128? i think so
	fSprite[0] = ham_CreateObj((void*)fBmpArray,			//ptr to sprite
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

void Jsprite::changeTexture()
{
	//change the planes texture
	ham_UpdateObjGfx(fSprite[0],(void*)&bmpArray[4096*fTextureIndex]);

	//send updated sprite to hardware
	ham_CopyObjToOAM();
}