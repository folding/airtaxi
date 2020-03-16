#ifndef _JMENU_DOT_H_
#define _JMENU_DOT_H_
//  Filename:		Jmenu.h
//	Author:			John Carlson
//	Description:	This is a class to abstract menu creation and maintenence
//					Possible menus include main, pause, and sub.  would this be
//					a good subclass of map???(or do I mean superclass??)
//
//	Changelog:		started 2-2-2003
//

#include "mygba.h"
#include "Jmap.h"
#include "Jsprite.h"

class Jmenu
{
public:
		Jmenu();
		void SetNumOptions(u8 numOpts);
		void SetOptionXY(u8 optionNumber, u8 x, u8 y);
        void MoveSelectorTo(u8 optionNumber);
		void MoveSelectorUp();
		void MoveSelectorDown();
		u8   ProcessInput();
		void ViewMenu();
		void HideMenu();
protected:

private:
		
		//map screen
		Jmap fScreen;
		//selection sprite
		Jsprite fSelector;
		//number of options
        u8 fNumOptions;//1-5
		//current option
		u8 fCurOption;
		//each options screen coordinate
        u8 fOptionX[5];
		u8 fOptionY[5];
};


#endif //_JMENU_DOT_H_


