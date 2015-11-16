#include "ofApp.h"

ofApp::ofApp()
{
    followerParticles.clear();
    
    for (int i = 0; i < 5; ++i)
    {
        Particle* particle = new Particle();
        
        followerParticles.push_back(particle);
    }
}

ofApp::~ofApp()
{
    for (auto p : followerParticles)
    {
        delete p;
    }
    
    followerParticles.clear();
}

//--------------------------------------------------------------
void ofApp::setup(){
    // Smooth edges
    ofEnableSmoothing();
    
    // Fixed framerate
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    theParticle.moveTo(mouseX, mouseY);
    
    Particle& previousParticle = theParticle;
    
    for (auto p : followerParticles)
    {
        p->moveTo(previousParticle.getX(), previousParticle.getY());
        previousParticle = *p;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor(30,10,30), OF_GRADIENT_CIRCULAR);
    
    // Draw Circle
    theParticle.draw();

    // Draw Shadow
    for (auto p : followerParticles)
    {
        p->draw();
    }
    
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
