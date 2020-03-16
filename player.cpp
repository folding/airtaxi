#include "player.h"

//implementation of member functions

Player::Player() 
{
	health=50;
	strength=100;
}

Player::~Player() 
{
	health=0;
	strength=0;
}

void Player::DisplayStats() 
{

	ham_DrawText(2,2,"HAMlib simple CPP Test");
	ham_DrawText(2,5,"health  : %d",this->health);
	ham_DrawText(2,6,"strength: %d",this->strength);
}


