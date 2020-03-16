//  Filename:		Jmap.cpp
//	Author:			John Carlson
//	Description:	This is a class to abstract map creation and maintenence
//
//	Changelog:		started 2-1-2003
//

//#define TILE_MODE_OK
#undef TILE_MODE_OK

#include "Jmap.h"

#ifdef TILE_MODE_OK
	#include "gfx/sprite.raw.c"
	#include "gfx/sprite.map.c"
#else
	#include "gfx/sprt.raw.c"
#endif



Jmap::Jmap()
{
	fMapZoom = 0;
	fMapRotation = 0;
}

void Jmap::initMap()
{
#ifdef TILE_MODE_OK
/*	map_fragment_info_ptr  bg_pic; //map pointer


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
							0);			//y tilenumber..*/

#else 

	//this is set up for mode 4 one big bitmap.
	TOOL_DMA3_SET(&sprt_Bitmap,				//source address
				  MEM_BG_PTR,				//destination address
				  SIZEOF_32BIT(sprt_Bitmap),//size
				  DMA_TRANSFER_32BIT,		//mode
				  DMA_STARTAT_NOW)			//timing


#endif

}

u8 Jmap::getElevation(u16 x, u16 y)
{
	//return elevation[fMapY*y+x];
	return 8;

}

void Jmap::RotateLeft()
{
	if(fMapRotation == 0)
		fMapRotation = 359;
	else
		fMapRotation--;
}

void Jmap::RotateRight()
{
	if(fMapRotation == 359)
		fMapRotation = 0;
	else
		fMapRotation++;
}

void Jmap::ZoomIn()
{
	if (fMapZoom == 359) {
		//do nothing
	}
	else
		fMapZoom++;
}

void Jmap::ZoomOut()
{
	if(fMapZoom == 0)
	{
		//do nothing
	}
	else
		fMapZoom--;
}

u16 Jmap::GetRot()
{
	return fMapRotation;
}

u16 Jmap::GetZoom()
{
	return fMapZoom;
}
