/*
---------------------------
HAMlib simple C++ example 

modified into proj.gba
---------------------------
*/

#include "mygba.h"

//#include "player.h"

//graphics includes
#include "gfx/object.pal.c"
#include "gfx/supercub_anim.raw.c"
#include "gfx/spr.pal.c"
#include "gfx/sprite.raw.c"
#include "gfx/sprite.map.c"


u16 rot_plane = 7;
u8 plane[1];//sprite index for the plane //is this array notation so it is a pointer?
u8 plane_x = 110;
u8 plane_y = 50;

// when plane rotates, this is 1
u8 in_rot=0;

// global frame counter
u32 frames=0;

void vblFunc();
void query_keys();
//void redraw_plane();



MULTIBOOT

int main(void)
{
    // initialize HAMlib
    ham_Init();

    // init the Text display system on the bg of your choice
   // ham_InitText(2);

	//Player *myplayer = new Player;

	//myplayer->DisplayStats();

	map_fragment_info_ptr  bg_pic;

	ham_SetBgMode(1);

	/*TOOL_DMA1_SET(&spr_Bitmap,
				  MEM_BG_PTR,
				  SIZEOF_32BIT(spr_Bitmap),
				  DMA_TRANSFER_32BIT,
				  DMA_STARTAT_NOW)*/

    ham_LoadBGPal256((void*)&spr_Palette);
	
	//now load the supercubs color palette
	ham_LoadObjPal((void*)&object_Palette,256);

	ham_bg[0].ti = ham_InitTileSet((void*)&sprite_Tiles,		//ptr to source
								   SIZEOF_16BIT(sprite_Tiles),	//number of 16bit chunks
								   1,							//color/palette mode
								   1);							//offset or not...

	ham_bg[0].mi = ham_InitMapEmptySet(3,				//mapsize				
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
			   0,		//set priorty (0-high,3-low)
			   0);		//turn mosaic on/off

	//initalize our supercub sprite
	plane[0] = ham_CreateObj((void*)&supercub_anim_Bitmap, //ptr to sprite
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
							 plane_y);				//y screen coord

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
		ham_UpdateObjGfx(plane[0],
					 (void*)&supercub_anim_Bitmap[4096*rot_plane]);
		//send updated sprite to hardware
		ham_CopyObjToOAM();

		in_rot = 0;
	}	

	//check for a keypress
	query_keys();

	frames++;

}//end vblFunc
	
void query_keys()
{
	if(F_CTRLINPUT_LEFT_PRESSED && rot_plane > 0)
	{
		//rotate the plane back to the left
		rot_plane--;
		in_rot = 1;

	}

	if(F_CTRLINPUT_RIGHT_PRESSED && rot_plane < 15)
	{
		//rotate the plane to the right
		rot_plane++;
		in_rot = 1;
	}

}//end query_keys




