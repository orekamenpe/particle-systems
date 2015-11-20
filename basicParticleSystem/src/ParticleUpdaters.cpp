//
//  ParticleUpdaters.cpp
//  basicParticleSystem
//
//  Created by Ibai on 18/11/15.
//
//

#include "ParticleUpdaters.h"
#include "mathHelper.h"

namespace updaters
{
    void EulerUpdater::update(double dt, ParticleData *p)
    {
        const ofVec3f globalA{ static_cast<float>(dt * _globalAcceleration.x), static_cast<float>(dt * _globalAcceleration.y), static_cast<float>(dt * _globalAcceleration.z)};
        const float localDT = (float)dt;
        
        ofVec3f * __restrict acc = p->_acceleration.get();
        ofVec3f * __restrict vel = p->_velocity.get();
        ofVec3f * __restrict pos = p->_position.get();
        
        const unsigned int endId = p->_countAlive;
        for (size_t i = 0; i < endId; ++i)
            acc[i] += globalA;
        
        for (size_t i = 0; i < endId; ++i)
            vel[i] += localDT * acc[i];
        
        for (size_t i = 0; i < endId; ++i)
            pos[i] += localDT * vel[i];
    }
    
    void FloorUpdater::update(double dt, ParticleData *p)
    {
        const float localDT = (float)dt;
        
        ofVec3f * __restrict acc = p->_acceleration.get();
        ofVec3f * __restrict vel = p->_velocity.get();
        ofVec3f * __restrict pos = p->_position.get();
        
        const size_t endId = p->_countAlive;
        for (size_t i = 0; i < endId; ++i)
        {
            if (pos[i].y < _floorY)
            {
                ofVec3f force = p->_acceleration[i];
                float normalFactor = mathHelper::dotVec3f(force, ofVec3f(0.0f, 1.0f, 0.0f));
                if (normalFactor < 0.0f)
                    force -= ofVec3f(0.0f, 1.0f, 0.0f) * normalFactor;
                
                float velFactor = mathHelper::dotVec3f(vel[i], ofVec3f(0.0f, 1.0f, 0.0f));
                //if (velFactor < 0.0)
                vel[i] -= ofVec3f(0.0f, 1.0f, 0.0f) * (1.0f + _bounceFactor) * velFactor;
                
                acc[i] = force;
            }
        }
        
    }
    
    void AttractorUpdater::update(double dt, ParticleData *p)
    {
        const float localDT = (float)dt;
        
        ofVec3f * __restrict acc = p->_acceleration.get();
        ofVec3f * __restrict vel = p->_velocity.get();
        ofVec3f * __restrict pos = p->_position.get();
        
        const size_t endId = p->_countAlive;
        const size_t countAttractors = _attractors.size();
        ofVec3f off;
        float dist;
        size_t a;
        for (size_t i = 0; i < endId; ++i)
        {
            for (a = 0; a < countAttractors; ++a)
            {
                off.x = _attractors[a].x - pos[i].x;
                off.y = _attractors[a].y - pos[i].y;
                off.z = _attractors[a].z - pos[i].z;
                dist = mathHelper::dotVec3f(off, off);
                
                //if (fabs(dist) > 0.00001)
                //dist = _attractors[a].w / dist;
                
                acc[i] += off * dist;
            }
        }
    }
    
    void BasicColorUpdater::update(double dt, ParticleData *p)
    {
        ofVec3f * __restrict col = p->_color.get();
        ofVec3f * __restrict startCol = p->_startColor.get();
        ofVec3f * __restrict endCol = p->_endColor.get();
        ssize_t * __restrict t = p->_time.get();
        
        const size_t endId = p->_countAlive;
        for (size_t i = 0; i < endId; ++i)
        {
            col[i] = mathHelper::mixVec3f(startCol[i], endCol[i], t[i]);
        }
    }
    
    void PosColorUpdater::update(double dt, ParticleData *p)
    {
        ofVec3f * __restrict col = p->_color.get();
        ofVec3f * __restrict startCol = p->_startColor.get();
        ofVec3f * __restrict endCol = p->_endColor.get();
        ssize_t * __restrict t = p->_time.get();
        ofVec3f * __restrict pos = p->_position.get();
        
        const int endId = (int)p->_countAlive;
        float scaler, scaleg, scaleb;
        float diffr = _maxPos.x - _minPos.x;
        float diffg = _maxPos.y - _minPos.y;
        float diffb = _maxPos.z - _minPos.z;
        
        for (int i = 0; i < endId; ++i)
        {
            scaler = (pos[i].x - _minPos.x) / diffr;
            scaleg = (pos[i].y - _minPos.y) / diffg;
            scaleb = (pos[i].z - _minPos.z) / diffb;
            col[i].x = scaler;// mathHelper::mixf(p->_startColor[i].r, p->_endColor[i].r, scaler);
            col[i].y = scaleg;// mathHelper::mixf(p->_startColor[i].g, p->_endColor[i].g, scaleg);
            col[i].z = scaleb;// mathHelper::mixf(p->_startColor[i].b, p->_endColor[i].b, scaleb);
            //col[i].w = mathHelper::mixf(startCol[i].w, endCol[i].w, t[i]);
        }
    }
    
    void VelColorUpdater::update(double dt, ParticleData *p)
    {
        ofVec3f * __restrict col = p->_color.get();
        ofVec3f * __restrict startCol = p->_startColor.get();
        ofVec3f * __restrict endCol = p->_endColor.get();
        ssize_t * __restrict t = p->_time.get();
        ofVec3f * __restrict vel = p->_velocity.get();
        
        const size_t endId = p->_countAlive;
        float scaler, scaleg, scaleb;
        float diffr = _maxVel.x - _minVel.x;
        float diffg = _maxVel.y - _minVel.y;
        float diffb = _maxVel.z - _minVel.z;
        for (size_t i = 0; i < endId; ++i)
        {
            scaler = (vel[i].x - _minVel.x) / diffr;
            scaleg = (vel[i].y - _minVel.y) / diffg;
            scaleb = (vel[i].z - _minVel.z) / diffb;
            col[i].x = scaler;// mathHelper::mixf(p->_startColor[i].r, p->_endColor[i].r, scaler);
            col[i].y = scaleg;// mathHelper::mixf(p->_startColor[i].g, p->_endColor[i].g, scaleg);
            col[i].z = scaleb;// mathHelper::mixf(p->_startColor[i].b, p->_endColor[i].b, scaleb);
            //col[i].w = mathHelper::mixf(startCol[i].w, endCol[i].w, t[i]);
        }
    }
    
    void BasicTimeUpdater::update(double dt, ParticleData *p)
    {
        unsigned int endId = p->_countAlive;
        const float localDT = (float)dt;
        
        ssize_t * __restrict t = p->_time.get();
        
        if (endId == 0) return;
        
        for (size_t i = 0; i < endId; ++i)
        {
            t[i] -= 1;
            
            if (t[i] < 0)
            {
                p->kill(i);
                endId = p->_countAlive < p->_count ? p->_countAlive : p->_count;
            }
        }
    }
}