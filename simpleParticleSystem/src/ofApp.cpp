#include "ofApp.h"
#include "particleController.h"

ofApp::ofApp()
{
}

ofApp::~ofApp()
{
    delete _particleController;
}

//--------------------------------------------------------------
void ofApp::setup(){
    _fullscreen = false;
    _mouseDown = false;
    
    ofSetFrameRate(30);
    ofSetVerticalSync(true);
    ofBackground(ofColor::black);
    
    _image.load("circle.png");
    
    _particleController = new ParticleController(_image.getTexture(), ofPoint(ofGetWidth() * 0.5f, ofGetHeight() - 10), 3, 10.0f, 20.0f, -90.0f, 20.0f);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if ( _mouseDown )
    {
        _particleController->_position = _mousePos;
    }
    _particleController->update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    _particleController->draw ();
    
    ofSetColor(0xFF0080);
    ofDrawBitmapString( "FPS: " + ofToString(ofGetFrameRate() ), 10, 20);
    ofDrawBitmapString( "Particles: " + ofToString(_particleController->getParticleCount()), 10, 30);
    ofSetColor(0x0080FF);
    ofDrawBitmapString("Press/drag mouse to spawn particles", ofGetWidth() - (35*8) - 10, 20);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key){
        case 'f':
        case 'F':
            _fullscreen = !_fullscreen;
            ofSetFullscreen(_fullscreen);
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    _mousePos = ofPoint(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    _mousePos = ofPoint(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    _mouseDown = true;
    _mousePos = ofPoint(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    _mouseDown = false;
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
