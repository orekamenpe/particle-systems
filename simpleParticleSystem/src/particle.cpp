//
//  particle.cpp
//  simpleParticleSystem
//
//  Created by Ibai on 16/11/15.
//
//

#include "particle.h"

Particle::Particle()
{
    _pos = ofPoint(ofRandomWidth(), ofRandomWidth());
    setup();
}

//--------------------------------------------------------------
Particle::Particle(ofPoint pos)
{
    _pos = pos;
    setup();
}

//--------------------------------------------------------------
Particle::Particle(ofPoint pos, ofPoint vel, float size, ofTexture* texture)
{
    _pos = pos;
    _vel = vel;
    _size = size;
    _texture = texture;
    
    _age = 0;
    _lifetime = 120;
    _dead = false;
}

//--------------------------------------------------------------
Particle::~Particle()
{
}

//--------------------------------------------------------------
void Particle::setup()
{
    _vel = ofPoint(ofRandomf(), ofRandomf()) * 10;
    _size = 5.0f;
    
    _age = 0;
    _lifetime = 120;
    _dead = false;
}

//--------------------------------------------------------------
void Particle::update()
{
    _pos += _vel;
    
    // particle life
    /*_age++;
    if (_age > _lifetime)
    {
        _dead = true;
    }*/
}

//--------------------------------------------------------------
void Particle::draw()
{
    float x = _pos.x - (_size * 0.5f);
    float y = _pos.y - (_size * 0.5f);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    
    ofSetColor(_colorR, _colorG, _colorB, _opacity);
    _texture->draw (x, y, _size, _size);
    
    glDisable(GL_BLEND);
}

//--------------------------------------------------------------
bool Particle::isOffscreen()
{
    return (_pos.x < 0 || _pos.y < 0 || _pos.x > ofGetWidth() || _pos.y > ofGetHeight());
}

//--------------------------------------------------------------
void Particle::setColor(int r, int g, int b)
{
    _colorR = r;
    _colorG = g;
    _colorB = b;
}
//--------------------------------------------------------------
void Particle::setColor(ofColor c)
{
    _colorR = c.r;
    _colorG = c.g;
    _colorB = c.b;
}
