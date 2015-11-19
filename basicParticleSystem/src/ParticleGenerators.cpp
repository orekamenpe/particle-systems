//
//  ParticleGenerators.cpp
//  basicParticleSystem
//
//  Created by Ibai on 18/11/15.
//
//

#include "ParticleGenerators.h"
#include "ofMath.h"
#include "mathHelper.h"

void BoxPosGen::generate(double dt, ParticleData *p, size_t startId, size_t endId)
{
    ofVec4f posMin{ _pos.x - _maxStartPosOffset.x, _pos.y - _maxStartPosOffset.y, _pos.z - _maxStartPosOffset.z, 1.0 };
    ofVec4f posMax{ _pos.x + _maxStartPosOffset.x, _pos.y + _maxStartPosOffset.y, _pos.z + _maxStartPosOffset.z, 1.0 };
    
    for (size_t i = startId; i < endId; ++i)
    {
        p->_position[i] = mathHelper::linearRandVec4(posMin, posMax);
    }
}

void RoundPosGen::generate(double dt, ParticleData *p, size_t startId, size_t endId)
{
    for (size_t i = startId; i < endId; ++i)
    {
        double ang = ofRandom(0.0, M_PI*2.0);
        p->_position[i] = _center + ofVec4f(_radX*sin(ang), _radY*cos(ang), 0.0, 1.0);
    }
}

void BasicColorGen::generate(double dt, ParticleData *p, size_t startId, size_t endId)
{
    for (size_t i = startId; i < endId; ++i)
    {
        p->_startColor[i] = mathHelper::linearRandVec4(_minStartCol, _maxStartCol);
        p->_endColor[i] = mathHelper::linearRandVec4(_minEndCol, _maxEndCol);
    }
}

void BasicVelGen::generate(double dt, ParticleData *p, size_t startId, size_t endId)
{
    for (size_t i = startId; i < endId; ++i)
    {
        p->_velocity[i] = mathHelper::linearRandVec4(_minStartVel, _maxStartVel);
    }
}

void SphereVelGen::generate(double dt, ParticleData *p, size_t startId, size_t endId)
{
    float phi, theta, v, r;
    for (size_t i = startId; i < endId; ++i)
    {
        phi = ofRandom(-M_PI, M_PI);
        theta = ofRandom(-M_PI, M_PI);
        v = ofRandom(_minVel, _maxVel);
        
        r = v*sinf(phi);
        p->_velocity[i].z = v*cosf(phi);
        p->_velocity[i].x = r*cosf(theta);
        p->_velocity[i].y = r*sinf(theta);
    }
}

void VelFromPosGen::generate(double dt, ParticleData *p, size_t startId, size_t endId)
{
    for (size_t i = startId; i < endId; ++i)
    {
        float scale = static_cast<float>(ofRandom(_minScale, _maxScale));
        ofVec4f vel = (p->_position[i] - _offset);
        p->_velocity[i] = scale * vel;
    }
}

void BasicTimeGen::generate(double dt, ParticleData *p, size_t startId, size_t endId)
{
    for (size_t i = startId; i < endId; ++i)
    {
        p->_time[i].x = p->_time[i].y = ofRandom(_minTime, _maxTime);
        p->_time[i].z = (float)0.0;
        p->_time[i].w = (float)1.0 / p->_time[i].x;
    }
}