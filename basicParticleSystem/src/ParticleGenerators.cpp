//
//  ParticleGenerators.cpp
//  basicParticleSystem
//
//  Created by Ibai on 18/11/15.
//
//

#include "ParticleGenerators.h"
#include "ofMain.h"
#include "ofMath.h"
#include "mathHelper.h"

namespace generators
{
    
// Position -------------------------------------------
    void BoxPosGen::generate(ParticleData *p, size_t startId, size_t endId)
    {
        ofVec3f posMin{ _pos.x - _maxStartPosOffset.x, _pos.y - _maxStartPosOffset.y, _pos.z - _maxStartPosOffset.z };
        ofVec3f posMax{ _pos.x + _maxStartPosOffset.x, _pos.y + _maxStartPosOffset.y, _pos.z + _maxStartPosOffset.z };
        
        for (size_t i = startId; i < endId; ++i)
        {
            p->_position[i] = mathHelper::linearRandVec3(posMin, posMax);
        }
    }
    
    void RoundPosGen::generate(ParticleData *p, size_t startId, size_t endId)
    {
        for (size_t i = startId; i < endId; ++i)
        {
            double ang = ofRandom(0.0, M_PI*2.0);
            p->_position[i] = _center + ofVec3f(_radX*sin(ang), _radY*cos(ang), 0.0);
        }
    }

// Color -------------------------------------------
    void BasicColorGen::generate(ParticleData *p, size_t startId, size_t endId)
    {
        for (size_t i = startId; i < endId; ++i)
        {
            p->_startColor[i] = mathHelper::linearRandVec3(_minStartCol, _maxStartCol);
            p->_endColor[i] = mathHelper::linearRandVec3(_minEndCol, _maxEndCol);
            p->_color[i] = p->_startColor[i];
        }
    }

// Velocity -------------------------------------------
    void BasicVelGen::generate(ParticleData *p, size_t startId, size_t endId)
    {
        for (size_t i = startId; i < endId; ++i)
        {
            ofVec2f vel = ofVec2f(_minStartVel.x, 0.0f);
            vel.rotate(ofRandom(_direction - _directionDev, _direction + _directionDev));
            p->_velocity[i] = ofVec3f(vel.x, vel.y, 0.0f);
        }
    }
    
    void SphereVelGen::generate(ParticleData *p, size_t startId, size_t endId)
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
    
    void VelFromPosGen::generate(ParticleData *p, size_t startId, size_t endId)
    {
        for (size_t i = startId; i < endId; ++i)
        {
            float scale = static_cast<float>(ofRandom(_minScale, _maxScale));
            ofVec3f vel = (p->_position[i] - _offset);
            p->_velocity[i] = scale * vel;
        }
    }

// Time -------------------------------------------
    void BasicTimeGen::generate(ParticleData *p, size_t startId, size_t endId)
    {
        for (size_t i = startId; i < endId; ++i)
        {
            p->_lifeTime[i] = ofRandom(_minTime, _maxTime);
            p->_life[i] = p->_lifeTime[i];
        }
    }
    
// Image/Texture -------------------------------------------
    void BasicImageGen::generate(ParticleData *p, size_t startId, size_t endId)
    {
        for (size_t i = startId; i < endId; ++i)
        {
            p->_image[i] = _image;
            p->_size[i] = _startSize;
            p->_startSize[i] = _startSize;
            p->_endSize[i] = _endSize;
            p->_opacity[i] = _startOpacity;
            p->_startOpacity[i] = _startOpacity;
            p->_endOpacity[i] = _endOpacity;
        }
    }
}