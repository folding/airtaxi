//  Filename:		main.cpp
//	Author:			John Carlson
//	Description:	This file started as the cpptest example from the ham samples folder
//					it then was morphed through the aaronroger.com tutorials and other 
//					code from the ham samples folder.  When finished it will be the driver
//					for my gba version of "air taxi"...
//	
//	Changelog:		started 1-30-2003
//
//					At this point the sprite handling has been transfered to the Jsprite class
//					it is still however mostly hard coded :( so it currently won't do more than
//					one sprite.
//
//					changes 1-31-2003
//
//					Jsprite.initSprite() now takes a ptr to the array representing the bmp
//					...
//					Can now make different sprites based.  I ditched the idea of having one big
//					static array of 128 sprites in the sprite class because the compiler balked
//					at it.  So each instance has a u8 that corresponds with its sprite data.
//					initSprite now also takes a screen x&y position



//Jsprite class
#include "Jsprite.h"

//graphics includes
#include "gfx/object.pal.c"//supercubs color palette
#include "gfx/supercub_anim.raw.c"
#include "gfx/spr.pal.c"
#include "gfx/sprite.raw.c"
#include "gfx/sprite.map.c"

u8 in_rot;

// global frame counter
u32 frames=0;

void vblFunc();
void query_keys();
//void redraw_plane();

Jsprite plane; //this is our plane sprite.
Jsprite otherplane;

MULTIBOOT

int main(void)
{
    // initialize HAMlib
    ham_Init();

	map_fragment_info_ptr  bg_pic; //map pointer

	ham_SetBgMode(1);	//set background mode to one

    ham_LoadBGPal256((void*)&spr_Palette);
	
	
	//now load the supercubs color palette
	ham_LoadObjPal((void*)&object_Palette,256);

	ham_bg[0].ti = ham_InitTileSet((void*)&sprite_Tiles,		//ptr to source
								   SIZEOF_16BIT(sprite_Tiles),	//number of 16bit chunks
								   1,							//color/palette mode
								   1);							//offset or not...

	ham_bg[0].mi = ham_InitMapEmptySet(3,				//map size				
									   0);				//rotatable (0 = no)

	bg_pic = ham_InitMapFragment((void*)&sprite_Map,	//ptr to source
								 30,					//map x size
								 20,					//map y size
								 0,						//x offset
								 0,						//y offset
								 1,						//num tiles in x direct
								 1,						//num tiles in y direct
								 0);					//rotatable (0 = no)

	ham_InsertMapFragment(bg_pic,		//map fragment ptr
						  0,			//background number
						  0,			//x tilenumber to place frag
						  0);			//y tilenumber..


	//Display the background
	ham_InitBg(0,		//background number
			   1,		//turn bg on/off (1 = on)
			   0,		//set priority (0-high,3-low)
			   0);		//turn mosaic on/off

	//initialize our supercub sprite
	plane.initSprite(0,										//sprite index number 0 - 127
					 (unsigned char*)&supercub_anim_Bitmap,	//pointer to bmp array
					 110,
					 50
					);

	otherplane.initSprite(1,(unsigned char*)&supercub_anim_Bitmap,10,10);

	/*plane[0] = ham_CreateObj((void*)&supercub_anim_Bitmap, //ptr to sprite
							 0,						//sprite shape
							 3,						//sprite size
							 OBJ_MODE_NORMAL,		//display sprite normal(nofx)
							 1,						//color/palette mode
							 0,						//palette index if mode 0
							 0,						//support mosaic (0 = off)
							 0,						//horiz flip on/off
							 0,						//vert flip on/off
                             0,						//priority(0-high, 3-low)
							 0,						//doublesize on/off
							 plane_x,				//x screen coord
							 plane_y);				//y screen coord*/

	plane.changeTexture();
	otherplane.changeTexture();
	//change the planes texture
	/*ham_UpdateObjGfx(plane[0],
					 (void*)&supercub_anim_Bitmap[4096*rot_plane]);
	//send updated sprite to hardware
	ham_CopyObjToOAM();*/

	//start the Vertical BLank interrupt handler
	ham_StartIntHandler(INT_TYPE_VBL,(void*)&vblFunc);		//calls vblFunc ~60 times per sec

	//infinite loop so program doesn't end
    while(1)
    {
    }    
}//end main

void vblFunc()
{
	// only update animation every 5th frame, 
	// and only if the plane is "in rotation"
	if(!(frames%5)&& in_rot)
	{
		//change the planes texture if necessary
		plane.changeTexture();		
		otherplane.changeTexture();
		in_rot = 0;
	}	

	//check for a keypress
	query_keys();

	frames++;

}//end vblFunc
	
void query_keys()
{
	if(F_CTRLINPUT_RIGHT_PRESSED && plane.getTextureIndex() > 0)
	{
		//rotate the plane back to the left
		plane.setTextureIndex(plane.getTextureIndex()-1);
		otherplane.setTextureIndex(plane.getTextureIndex()-1);
		in_rot = 1;

	}

	if(F_CTRLINPUT_LEFT_PRESSED && plane.getTextureIndex() < 15)
	{
		//rotate the plane to the right
		plane.setTextureIndex(plane.getTextureIndex()+1);
		otherplane.setTextureIndex(plane.getTextureIndex()+1);
		in_rot = 1;
	}

}//end query_keys









