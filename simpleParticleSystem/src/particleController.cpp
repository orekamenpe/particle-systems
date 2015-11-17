//
//  particleController.cpp
//  simpleParticleSystem
//
//  Created by Ibai on 16/11/15.
//
//

#include "particleController.h"

ParticleController::ParticleController()
{
}

ParticleController::ParticleController(ofTexture& text, ofPoint pos, int rate, float sizeMin, float sizeMax, float direction, float directionDev)
{
    _colorIndex = 0;
    _differentColors = 1200;
    
    _position = pos;
    _rate = rate;
    _particleSizeMin = sizeMin;
    _particleSizeMax = sizeMax;
    _direction = direction;
    _directionDeviation = directionDev;
    _particleTexture = &text;
}


//--------------------------------------------------------------
void ParticleController::update()
{
    for (auto p = _particles.begin(); p != _particles.end();)
    {
        if (p->isOffscreen () || p->_dead)
        {
            p = _particles.erase(p);
        }
        else
        {
            p->update();
            ++p;
        }
    }
    
    for (int i = 0; i < _rate; ++i)
    {
        float size = ofRandom(_particleSizeMin, _particleSizeMax);
        
        ofVec2f vel = ofVec2f(size * 0.25f, 0.0f );
        vel.rotate( ofRandom(_direction - _directionDeviation, _direction + _directionDeviation));
        
        Particle tmpParticle = Particle(_position, vel , size, _particleTexture);
        tmpParticle.setColor(nextColor());
        
        _particles.push_back(tmpParticle);
    }
    
}

//--------------------------------------------------------------
void ParticleController::draw()
{
    for (auto p : _particles)
    {
        p.draw();
    }
}

//--------------------------------------------------------------
void ParticleController::addParticle(ofPoint pos)
{
    _particles.push_back(Particle(pos));
}

//--------------------------------------------------------------
void ParticleController::addParticles(ofPoint pos, int amt)
{
    for (int i = 0; i < amt; ++i )
    {
        _particles.push_back(Particle(pos));
    }
}

//--------------------------------------------------------------
void ParticleController::addParticles(int amt)
{
    for (int i = 0; i < amt; ++i )
    {
        _particles.push_back(Particle());
    }
}

//--------------------------------------------------------------
void ParticleController::removeParticles(int amt)
{
}

//--------------------------------------------------------------
int ParticleController::getParticleCount()
{
    return _particles.size();
}

//--------------------------------------------------------------
ofColor ParticleController::nextColor()
{
    float f, p1, p2;
    ofColor c;
    
    f =  TWO_PI * 2 / _differentColors;
    p1 = TWO_PI / 3;
    p2 = p1 * 2;
    
    c.r = sin(_colorIndex * f + 0) * 127 + 128;
    c.g = sin(_colorIndex * f + p1) * 127 + 128;
    c.b = sin(_colorIndex++ * f + p2) * 127 + 128;
    return c;
}

