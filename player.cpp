#include "player.h"


player::player(void) {
	deathCount = 0;
	pos.set(50, 200);
	dead = false;
}//endConstructor

void player::updatePlayer() {
	switch (deathCount) {		
		default:
			colorRed = 0;
			colorGreen = 0;
			colorBlue = 0;
			break;

		case 1:
			colorRed = 97;
			colorGreen = 54;
			colorBlue = 54;
			dead = true;
			break;

		case 2:
			colorRed = 144;
			colorGreen = 41;
			colorBlue = 41;
			break;

		case 3:
			colorRed = 217;
			colorGreen = 65;
			colorBlue = 65;
			break;
		
		case 4:
			colorRed = 255;
			colorGreen = 0;
			colorBlue = 0;
			break;
	}//end switch
}//endUpdatePlayer

bool player::getDead() { return dead; }

void player::reset() {
	deathCount = 0;
	pos.set(50, 200);
	dead = false;
}

void player::playerDisplay() {
	ofSetColor(colorRed, colorGreen, colorBlue);
	ofFill();
	ofRect(pos.x, pos.y, 25, 25);
}//endPlayerDisplay
player::~player(void) {

}//endDestructor
