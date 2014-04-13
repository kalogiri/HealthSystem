#pragma once
#include "ofMain.h"
class collider
{
public:
	void drawColliderObject();
	void updateColliderObject();
	bool returnCollided();
	void collisionDetect(ofPoint);

	ofVec2f vel;
	ofPoint pos;
	
	bool 
		collided;
	collider(void);
	~collider(void);
};

