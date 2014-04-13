#pragma once
#include "ofMain.h"

class gameStates
{
public:
	void fontLoader();
	void drawGameOverString();
	void drawGameStartString();
	void displayGameOver();
	void drawEdges();
	void hover();

	ofTrueTypeFont bigTextForStartScreen, bigTextForGameOverScreen, control, quit, restart;
	int 
		hoverRestartColorRed, hoverRestartColorGreen, hoverRestartColorBlue,
		hoverExitColorRed, hoverExitColorGreen, hoverExitColorBlue;
	bool hoverRestartState, hoverExitState;

	gameStates(void);
	~gameStates(void);
};

