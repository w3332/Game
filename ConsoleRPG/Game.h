#ifndef GAME_H
#define GAME_H

#include "Character.h"
#include "functions.h"
#include <ctime>

class Game
{
public:
	Game();
	virtual ~Game();

	//operators

	//functions	
	void mainMenu();
	void setName();

	//accessors
	inline bool getPlaying() const { return this->playing; }

	//modifiers

private:
	int choice;
	bool playing;

	//character
	Character character;
};

#endif