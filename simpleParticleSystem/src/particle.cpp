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
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
    
    // initial position
    x = ofRandom (ofGetWindowWidth());
    y = ofRandom (ofGetWindowHeight());
}

void Particle::moveTo(float xDestiny, float yDestiny)
{
    x += (xDestiny - x) * 0.1f;
    y += (yDestiny -y) * 0.1f;
}

void Particle::draw()
{
    ofSetColor(color);
    ofFill();
    ofDrawCircle(x,y,30);
}

void Particle::setPosition(float newX, float newY)
{
    x = newX;
    y = newY;
}