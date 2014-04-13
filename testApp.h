#pragma once

#include "ofMain.h"
#include "player.h"
#include "collider.h"
#include "gameStates.h"

class testApp : public ofBaseApp {
	public:
		void setup();
		void update();
		void draw();
		void colliderObjectDraw();
		void colliderObjectUpdate();
		void colliderCollideWithPlayer();
		void playerMove();

	//Variables
		bool 
			up,down,right,left,
			gameStart,gameReset,gameWait;

		//The player
		player c;

		//Timer
		vector<collider> ti;
		collider t;

		//Game state screens
		gameStates g;

		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
};
