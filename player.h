#pragma once
#include "ofMain.h"

class player
{
public:

	player(void);

	//Variable
	ofVec2f vel,pos;
	int deathColor;
	int colorRed;
	int colorBlue;
	int colorGreen;
	int deathCount;
	bool dead;
	//Functions
	void
		playerDisplay(),
		updatePlayer(),
		reset();
	bool getDead();
	
	~player(void);
};

