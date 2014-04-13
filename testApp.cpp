#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	up = false;
	down = false;
	right = false;
	left = false;
	gameStart = true;
	gameReset = false;
	gameWait = false;
	g.fontLoader();
	ofBackground(92,1,106);
}//endSetup

//--------------------------------------------------------------
void testApp::colliderObjectDraw(){
	for(int i = 0; i < ti.size(); i+=500) {
		ti[i].updateColliderObject();
		ti[i].drawColliderObject();
		if(ti[i].pos.x < 0) {
				ti[i].pos.set(-50,0);
				ti[i].vel.set(0,0);
		}//endIf
	}//endFor
}//endTimerObjectDraw

void testApp::colliderObjectUpdate(){
	for(int i = 0; i < 1; i++) {
		ti.push_back(collider());
	}//endFor
	colliderObjectDraw();
}//endTimerObjectUpdate


//--------------------------------------------------------------
void testApp::colliderCollideWithPlayer(){
	for(int i = 0; i < ti.size(); i++) {
		ti[i].collisionDetect(c.pos);
	}//end for i
}//end colliderCollidesWithPlayer

//--------------------------------------------------------------
void testApp::update(){
	//timer
	for(int j = 0; j < ti.size(); j++) {
		if(ti[j].returnCollided()) {
			ti[j].pos.set(500,500);
			c.deathCount++;
		}//end if ti[j]
	}//end for j
	colliderCollideWithPlayer();
	c.updatePlayer();
}//end update

//--------------------------------------------------------------
void testApp::draw(){
	
	//cout<<"MouseX: "<<ofGetMouseX()<<endl;
	cout<<"MouseY: "<<ofGetMouseY()<<endl;
	//Start drawing everything when gameStart = true 
	if(gameStart == true) {
		colliderObjectUpdate();
		playerMove();
		c.playerDisplay();
	}//end gameStart == true

	//if the 
	if(c.getDead() == true) {
		gameStart = false;
		gameReset = true;
	}//end c.dead == true

	if(gameStart == false) {
		g.displayGameOver();
		g.drawGameOverString();
		g.drawEdges();
		g.hover();
	}//end gameStart == false

	if(gameReset == true) {
		ti.clear();
		c.reset();
		gameWait = true;
		gameReset = false;
	}
}//end draw

//--------------------------------------------------------------
void testApp::playerMove(){
	 if(up == true) {
        c.pos.y--;
    }//end if up
    
    if(down == true) {
        c.pos.y++;
    }//end if down
    
    if(right == true) {
        c.pos.x++;
    }//end if right
    
    if(left == true) {
        c.pos.x--;
    }//end if left

	if(gameReset == true) {
		gameStart = true;
	}
}//end playerMove

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    /*
     left arrow key = 356
     up arrow key = 357
     right arrow key = 358
     down arrow key = 359
     w = 119
     a = 97
     s = 115
     d = 100
     */
    //cout<< key << endl;
    //Movement of the player
 
    if(key == 119 || key == 357) {//Up
        up = true;
    }//end if up
    if(key == 97|| key == 356) {//Left
        left = true;
    }//end if left
    if (key == 115|| key == 359) {//Down
        down = true;
    }//end if down
    if(key == 100|| key == 358) {//Right
        right = true;
    }//end if right
	
	//The space key here is for debug purpose for button functionality
	/*
	if(key == 32) {//Space key
		//Do stuff here to emulate button scenarios.
	}//end if space
    */
}//endKeyPressed

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(key == 119 || key == 357) {//Up
        up = false;
    }//end if up
    if(key == 97|| key == 356) {//Left
        left = false;
    }//end if left
    if (key == 115|| key == 359) {//Down
        down = false;
    }//end if down
    if(key == 100|| key == 358) {//Right
        right = false;
    }//end if right
	
}//endKeyReleleased

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	//Shooting the bullets when pressing a mouseButton
    //button 0 = left mouse button
    //button 1 = middle mouse button
    //button 3 = right mouse button

    if(button == 0) {
		if(ofGetMouseX() >= 251 && ofGetMouseX() < 302 && 
		   ofGetMouseY() >= 236 && ofGetMouseY() < 250) {
			if(gameStart == false) {
				if(gameWait == true) {
					gameStart = true;
					gameWait = false;
				}//end if gameWait
				gameReset = true;
				gameStart = true;
			}//end if gameStart = false
		}//end if restart button detection
		
		if(ofGetMouseX() >= 310 && ofGetMouseX() < 335 && 
		   ofGetMouseY() >= 236 && ofGetMouseY() < 250) {
			if(gameStart == false) {
				exitApp();
			}//end if gameStart = false
		}//end if exit button detection
    }//end if left mouseButton
}//end mousePressed
