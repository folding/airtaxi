//  Filename:		Jmenu.cpp
//	Author:			John Carlson
//	Description:	This is a class to abstract menu creation and maintenence
//					Possible menus include main, pause, and sub.  would this be
//					a good subclass of map???(or do I mean superclass??)
//
//	Changelog:		started 2-2-2003
//

//possible menu decisions
#define NODECISION 200
#define EXITMENU 201
#define EXITTOMAINMENU 202


#include "Jmenu.h"

Jmenu::Jmenu()
{
	fNumOptions = 0;
	fCurOption = 0;
	fOptionX[0]=0;
	fOptionY[0]=0;
	fOptionX[1]=0;
	fOptionY[1]=0;
	fOptionX[2]=0;
	fOptionY[2]=0;
	fOptionX[3]=0;
	fOptionY[3]=0;
	fOptionX[4]=0;
	fOptionY[4]=0;
	//fSelector.initSprite();
	//fScreen.initMap();

}

void Jmenu::SetNumOptions(u8 numOpts)
{
	fNumOptions = numOpts;
}

void Jmenu::SetOptionXY(u8 optionNumber, u8 x, u8 y)
{
	if (optionNumber > 0 && optionNumber <= fNumOptions ) 
	{
		fOptionX[optionNumber-1] = x;
		fOptionY[optionNumber-1] = y;
	}
}

void Jmenu::MoveSelectorTo(u8 optionNumber)
{
	fSelector.setXLoc(fOptionX[optionNumber-1]);
	fSelector.setYLoc(fOptionY[optionNumber-1]);
	fSelector.updateLocation();
}

void Jmenu::MoveSelectorUp()
{
	if (fCurOption > 0) {
		fCurOption--;
		fSelector.setXLoc(fOptionX[fCurOption]);
		fSelector.setYLoc(fOptionY[fCurOption]);
		fSelector.updateLocation();
	}
	else
	{
		fCurOption = fNumOptions-1;
		fSelector.setXLoc(fOptionX[fCurOption]);
		fSelector.setYLoc(fOptionY[fCurOption]);
		fSelector.updateLocation();
	}
}

void Jmenu::MoveSelectorDown()
{
	if (fCurOption < fNumOptions-1) {
		fCurOption++;
		fSelector.setXLoc(fOptionX[fCurOption]);
		fSelector.setYLoc(fOptionY[fCurOption]);
		fSelector.updateLocation();
	}
	else
	{
		fCurOption = 0;
		fSelector.setXLoc(fOptionX[fCurOption]);
		fSelector.setYLoc(fOptionY[fCurOption]);
		fSelector.updateLocation();
	}
}
//this feels alittle bit backwards I am making the calling method
//figure out what to do based on the currently selected option.
u8 Jmenu::ProcessInput()
{
	if(F_CTRLINPUT_UP_ONLY_PRESSED)
		MoveSelectorUp();
	else if(F_CTRLINPUT_DOWN_ONLY_PRESSED || F_CTRLINPUT_SELECT_ONLY_PRESSED)
		MoveSelectorDown();
	else if(F_CTRLINPUT_A_ONLY_PRESSED)
		return fCurOption;
	//else	
	return NODECISION;
}

void Jmenu::ViewMenu()
{
	

	//load up the map junk into backgrounds


	//load up the sprite into whatever

	//display menu


}

void Jmenu::HideMenu()
{
	//clean up the map

	//hide the selector

	//return screen to previous state.	
}

