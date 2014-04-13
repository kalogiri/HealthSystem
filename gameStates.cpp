#include "gameStates.h"


gameStates::gameStates(void)
{
}

void gameStates::fontLoader() {
	bigText.loadFont("BebasNeue.otf", 62);
	control.loadFont("BebasNeue.otf", 15);
	quit.loadFont("BebasNeue.otf", 15);
}

void gameStates::drawString() {
	ofSetColor(92,1,106);
	ofFill();
	bigText.drawString("Press",120,190);
	bigText.drawString("Shoot",285,190);
	bigText.drawString("To",120,270);
	bigText.drawString("Start",195,270);
	control.drawString("Controls",370,270);
	quit.drawString("Exit",440,270);

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


gameStates::~gameStates(void)
{
}
