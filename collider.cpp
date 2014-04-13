#include "collider.h"
collider::collider(void){
	collided = false;
	pos.set(600,ofRandom(55,330));
	vel.set(ofRandom(-1,-3),0);
}


void collider::collisionDetect(ofPoint plPos) {
	if(plPos.distance(pos) < 25) {
		collided = true;
	} else {
		collided = false;
	}
}

bool collider::returnCollided() { return collided;}

void collider::updateColliderObject() {
	pos+=vel;
}

void collider::reset() {
	collided = false;
	pos.set(600,ofRandom(55,330));
	vel.set(ofRandom(-1,-3),0);
}
void collider::drawColliderObject(){
	ofSetColor(255,0,0);
	ofFill();
	ofRect(pos.x, pos.y, 10,10);
}

collider::~collider(void){
}
