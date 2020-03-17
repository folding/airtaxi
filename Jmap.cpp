//  Filename:		Jmap.cpp
//	Author:			John Carlson
//	Description:	This is a class to abstract map creation and maintenence
//
//	Changelog:		started 2-1-2003
//

//#undef TILE_MODE_OK
//#define TILE_MODE_OK

#include "Jmap.h"

//#ifdef TILE_MODE_OK
	#include "gfx/mapgrid.raw.c"
	#include "gfx/mapgrid.map.c"
/*#else
#include "gfx/sprt.raw.c"
//#include "gfx/maptest.raw.c"
#endif*/



Jmap::Jmap()
{
	fMapZoom = 0;
	fMapRotation = 0;
}

void Jmap::initMap()
{

	map_fragment_info_ptr  bg_pic; //map pointer


	ham_bg[2].ti = ham_InitTileSet((void*)&mapgrid_Tiles,		//ptr to source
									SIZEOF_16BIT(mapgrid_Tiles),//number of 16bit chunks
									1,							//color/palette mode
									1);							//offset or not...

	ham_bg[2].mi = ham_InitMapEmptySet(1,	//256x256	//map size				
									   1);				//rotatable (0 = no)

	fMapX = 512;
	fMapY = 512;

	bg_pic = ham_InitMapFragment((void*)&mapgrid_Map,	//ptr to source
									32,					//map x size in tiles
									32,					//map y size in tiles
									0,					//x offset in tiles
									0,					//y offset in tiles
									32,					//num tiles in x direct
									32,					//num tiles in y direct
									1);					//rotatable (0 = no)

	ham_InsertMapFragment(bg_pic,		//map fragment ptr
							2,			//background number
							0,			//x tilenumber to place frag
							0);			//y tilenumber..

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
