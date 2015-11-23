#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(30);
    ofSetVerticalSync(true);
    ofBackground(ofColor::black);
    
    glowImage.load("particle_fire.png");
    flame1Image.load("flame01.png");
    flame2Image.load("flame02.png");
    flame3Image.load("flame03.png");
    emberImage.load("spot.png");
    fireEffect.initialize(0, glowImage, flame1Image, flame2Image, flame3Image, emberImage);
}

//--------------------------------------------------------------
void ofApp::update(){

    fireEffect.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    fireEffect.draw();

    glDisable(GL_BLEND);
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
