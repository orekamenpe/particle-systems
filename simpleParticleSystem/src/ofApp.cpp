#include "ofApp.h"

ofApp::ofApp()
{
    _VParticles.clear();
    
    for (int i = 0; i < 5; ++i)
    {
        Particle* particle = new Particle();
        
        _VParticles.push_back(particle);
    }
}

ofApp::~ofApp()
{
    for (auto p : _VParticles)
    {
        delete p;
    }
    
    _VParticles.clear();
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
    
    _particle.moveTo(mouseX, mouseY);
    
    Particle& previousParticle = _particle;
    
    for (auto p : _VParticles)
    {
        p->moveTo(previousParticle.getX(), previousParticle.getY());
        previousParticle = *p;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor(30,10,30), OF_GRADIENT_CIRCULAR);
    
    // Draw Circle
    _particle.draw();

    // Draw Shadow
    for (auto p : _VParticles)
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
    _particle.setPosition(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()));
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
