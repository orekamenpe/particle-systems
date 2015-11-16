//
//  particle.cpp
//  simpleParticleSystem
//
//  Created by Ibai on 16/11/15.
//
//

#include "particle.h"
#include "ofMain.h"

Particle::Particle(){
    // Set the initial color
    _color.set( ofRandom(255), ofRandom(255), ofRandom(255));
    
    // initial position
    _x = ofRandom (ofGetWindowWidth());
    _y = ofRandom (ofGetWindowHeight());
}

void Particle::moveTo(float xDestiny, float yDestiny)
{
    _x += (xDestiny - _x) * 0.5f;
    _y += (yDestiny - _y) * 0.5f;
}

void Particle::draw()
{
    ofSetColor(_color);
    ofFill();
    ofDrawCircle(_x,_y,30);
}

void Particle::setPosition(float newX, float newY)
{
    _x = newX;
    _y = newY;
}