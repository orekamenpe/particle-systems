#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Smooth edges
    ofEnableSmoothing();
    
    // Fixed framerate
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //theShadowParticle.setPosition(theParticle.getX(), theParticle.getY());
    
    theParticle.moveTo(mouseX, mouseY);
    theShadowParticle.moveTo(theParticle.getX(), theParticle.getY());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor(30,10,30), OF_GRADIENT_CIRCULAR);
    
    // Draw Shadow
    theShadowParticle.draw();
    
    // Draw Circle
    theParticle.draw();
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
    theParticle.setPosition(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()));

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
