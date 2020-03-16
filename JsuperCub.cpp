//  Filename:		JsuperCub.h
//	Author:			John Carlson
//	Description:	This is my class to abstract supercubs it inherits from Jsprite...
//	
//	Changelog:		started 1-31-2003
//

#include "JsuperCub.h"
#include "gfx/supercub_anim.raw.c"

//#define TEXT_MODE_OK
#undef TEXT_MODE_OK

JsuperCub::JsuperCub()
{

}

//similar to Jsprite.initSprite but all hard coded...
void JsuperCub::initPlane()
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
	fDir.y = 1;
	fDir.z = 0;

	//speed sprite is travelling
	fSpeed = 0;

	//number of frames of animation
	fFramesOfAnim = 15;

	//current frame of animation
	fTextureIndex = 7;

	fBmpArray = (unsigned char*)&supercub_anim_Bitmap;

	fSpriteNum = ham_CreateObj((void*)fBmpArray,			//ptr to sprite
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
									fLoc.y);				//y screen coord

}

void JsuperCub::DecreaseSpeed()
{
#ifdef TEXT_MODE_OK
	ham_DrawText(1,18,"b and down   ");
#endif	
	fSpeed--;
}

void JsuperCub::IncreaseSpeed()
{
#ifdef TEXT_MODE_OK
	ham_DrawText(1,18,"b and up     ");
#endif

	fSpeed++;
}

void JsuperCub::RotateAileronsLeft()
{
	if(fTextureIndex < fFramesOfAnim)
		fTextureIndex++;
#ifdef TEXT_MODE_OK
	ham_DrawText(1,18,"l only       ");
#endif
}

void JsuperCub::RotateAileronsRight()
{
	if(fTextureIndex > 0)
		fTextureIndex--;
#ifdef TEXT_MODE_OK
	ham_DrawText(1,18,"r only       ");
#endif
}


void JsuperCub::RotateElevatorDown()
{
#ifdef TEXT_MODE_OK
	ham_DrawText(1,18,"up only");
#endif
}

void JsuperCub::RotateElevatorUp()
{
#ifdef TEXT_MODE_OK
	ham_DrawText(1,18,"down only");
#endif
}

void JsuperCub::RotateFlapsDown()
{


}

void JsuperCub::RotateFlapsUp()
{

}

void JsuperCub::RotateRudderLeft()
{
#ifdef TEXT_MODE_OK
	ham_DrawText(1,18,"left only");
#endif
}

void JsuperCub::RotateRudderRight()
{
#ifdef TEXT_MODE_OK
	ham_DrawText(1,18,"right only   ");
#endif
}
