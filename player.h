#ifndef PLAYER_DOT_H
#define PLAYER_DOT_H

#include "mygba.h"

class Player 
{
private:
	int health;
	int strength;	

public:
	//constructor
	Player();
	//destructor
	~Player();
	//member functions
	void DisplayStats();

};

#endif //PLAYER_DOT_H


