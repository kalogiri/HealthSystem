#include "gameStates.h"


gameStates::gameStates(void) {
	hoverRestartState = false;
	hoverExitState = false;
	hoverRestartColorRed = 92;
	hoverRestartColorGreen = 1;
	hoverRestartColorBlue = 106; 
	hoverExitColorRed = 92;
	hoverExitColorGreen = 1;
	hoverExitColorBlue = 106; 
}

void gameStates::fontLoader() {
	bigTextForStartScreen.loadFont("BebasNeue.otf", 62);
	bigTextForGameOverScreen.loadFont("BebasNeue.otf", 75);
	restart.loadFont("BebasNeue.otf", 15);
	quit.loadFont("BebasNeue.otf", 15);
	control.loadFont("BebasNeue.otf", 15);
}

void gameStates::drawGameStartString() {
	ofSetColor(92,1,106);
	ofFill();
	bigTextForStartScreen.drawString("Press",120,190);
	bigTextForStartScreen.drawString("Shoot",285,190);
	bigTextForStartScreen.drawString("To",120,270);
	bigTextForStartScreen.drawString("Start",195,270);
	control.drawString("Controls",370,270);
	quit.drawString("Exit",440,270);
}

void gameStates::drawGameOverString() {
	ofSetColor(92,1,106);
	ofFill();
	bigTextForGameOverScreen.drawString("Game",132,210);
	bigTextForGameOverScreen.drawString("Over",312,210);
	ofSetColor(hoverRestartColorRed,hoverRestartColorGreen,hoverRestartColorBlue);
	restart.drawString("Restart",251,251);
	ofSetColor(hoverExitColorRed,hoverExitColorGreen,hoverExitColorBlue);
	quit.drawString("Exit",310,251);
}

void gameStates::displayGameOver() {
	ofSetColor(0);
	ofFill();
	ofRect(100,90,400,220);
	drawEdges();
}

void gameStates::drawEdges() {
	ofSetColor(0);
	ofFill();
	ofRect(0,0,600,40);
	ofRect(0,360,600,40);
}

void gameStates::hover() {

	//Exit
	if(ofGetMouseX() >= 310 && ofGetMouseX() < 335 && 
	   ofGetMouseY() >= 236 && ofGetMouseY() < 250) {
		hoverExitState = true;
	} else { hoverExitState = false; }

	if(hoverExitState == true) {
		hoverExitColorRed = 147;
		hoverExitColorGreen = 1;
		hoverExitColorBlue = 169; 
	} else {
		hoverExitColorRed = 92;
		hoverExitColorGreen = 1;
		hoverExitColorBlue = 106; 
	}
	
	//Restart
	if(ofGetMouseX() >= 251 && ofGetMouseX() < 302 && 
	   ofGetMouseY() >= 236 && ofGetMouseY() < 250) {
		hoverRestartState = true;
	} else { hoverRestartState = false; }

	if(hoverRestartState == true) {
		hoverRestartColorRed = 147;
		hoverRestartColorGreen = 1;
		hoverRestartColorBlue = 169; 
	} else {
		hoverRestartColorRed = 92;
		hoverRestartColorGreen = 1;
		hoverRestartColorBlue = 106; 
	}
}


gameStates::~gameStates(void)
{
}
