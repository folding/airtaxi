#include "JsuperCub.h"


JsuperCub::JsuperCub()
{

}


void JsuperCub::DecreaseSpeed()
{
	ham_DrawText(1,18,"b and down   ");
}

void JsuperCub::IncreaseSpeed()
{
	ham_DrawText(1,18,"b and up     ");
}

void JsuperCub::RotateAileronsLeft()
{
	if(fTextureIndex < 15)
		fTextureIndex++;

	ham_DrawText(1,18,"l only       ");
}

void JsuperCub::RotateAileronsRight()
{
	if(fTextureIndex > 0)
		fTextureIndex--;

	ham_DrawText(1,18,"r only       ");
}


void JsuperCub::RotateElevatorDown()
{
	ham_DrawText(1,18,"up only");
}

void JsuperCub::RotateElevatorUp()
{
	ham_DrawText(1,18,"down only");

}

void JsuperCub::RotateFlapsDown()
{


}

void JsuperCub::RotateFlapsUp()
{

}

void JsuperCub::RotateRudderLeft()
{
	ham_DrawText(1,18,"left only");
}

void JsuperCub::RotateRudderRight()
{
	ham_DrawText(1,18,"right only   ");
}
