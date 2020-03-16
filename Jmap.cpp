//  Filename:		Jmap.cpp
//	Author:			John Carlson
//	Description:	This is a class to abstract map creation and maintenence
//
//	Changelog:		started 2-1-2003
//


#include "Jmap.h"

#include "gfx/sprite.raw.c"
#include "gfx/sprite.map.c"

void Jmap::initMap()
{
	map_fragment_info_ptr  bg_pic; //map pointer


	ham_bg[1].ti = ham_InitTileSet((void*)&sprite_Tiles,		//ptr to source
									SIZEOF_16BIT(sprite_Tiles),	//number of 16bit chunks
									1,							//color/palette mode
									1);							//offset or not...

	ham_bg[1].mi = ham_InitMapEmptySet(3,				//map size				
										0);				//rotatable (0 = no)

	fMapX = 30;
	fMapY = 20;

	bg_pic = ham_InitMapFragment((void*)&sprite_Map,	//ptr to source
									fMapX,				//map x size
									fMapY,				//map y size
									0,					//x offset
									0,					//y offset
									1,					//num tiles in x direct
									1,					//num tiles in y direct
									0);					//rotatable (0 = no)

	ham_InsertMapFragment(bg_pic,		//map fragment ptr
							0,			//background number
							0,			//x tilenumber to place frag
							0);			//y tilenumber..

}

u8 Jmap::getElevation(u16 x, u16 y)
{
	//return elevation[fMapY*y+x];
	return 8;

}

