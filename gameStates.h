#pragma once
#include "ofMain.h"

class gameStates
{
public:
	void fontLoader();
	void drawString();
	void displayGameOver();
	void drawEdges();

	ofTrueTypeFont bigText, control, quit;

	gameStates(void);
	~gameStates(void);
};

