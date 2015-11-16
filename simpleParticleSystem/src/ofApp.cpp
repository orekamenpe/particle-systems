#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Smooth edges
    ofEnableSmoothing();
    
    // Fixed framerate
    ofSetFrameRate(30);
    
    // Initial x & y position of the ball
    xPos = ofGetWindowWidth() * 0.5f;
    yPos = ofGetWindowHeight() * 0.5f;
    
    oldXPos = xPos;
    oldYPos = yPos;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    oldXPos = xPos;
    oldYPos = yPos;
    
    // calculate the x and y distance
    xPos += (mouseX - xPos) * 0.1f;
    yPos += (mouseY - yPos) * 0.1f;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor(30,10,30), OF_GRADIENT_CIRCULAR);
    
    // Draw Shadow
    ofSetColor(100,100,70);
    ofFill();
    ofDrawCircle(oldXPos,oldYPos,29);
    
    // Draw Circle
    ofSetColor(200,200,124);
    ofFill();
    ofDrawCircle(xPos,yPos,30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    xPos = ofRandom(ofGetWindowWidth());
    yPos = ofRandom(ofGetWindowHeight());

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
