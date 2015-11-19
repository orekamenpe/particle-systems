//
//  ParticleUpdaters.h
//  basicParticleSystem
//
//  Created by Ibai on 18/11/15.
//
//

#ifndef __basicParticleSystem__ParticleUpdaters__
#define __basicParticleSystem__ParticleUpdaters__

#include "ParticleUpdater.h"
#include "ofMath.h"

class EulerUpdater : public ParticleUpdater
{
public:
    ofVec4f _globalAcceleration;
public:
    EulerUpdater() : _globalAcceleration(0.0) { }
    
    virtual void update(double dt, ParticleData *p) override;
};

// collision with the floor :) todo: implement a collision model
class FloorUpdater : public ParticleUpdater
{
public:
    float _floorY;
    float _bounceFactor;
public:
    FloorUpdater() : _floorY(0.0), _bounceFactor(0.5f) { }
    
    virtual void update(double dt, ParticleData *p) override;
};

class AttractorUpdater : public ParticleUpdater
{
protected:
    std::vector<ofVec4f> _attractors; // .w is force
public:
    virtual void update(double dt, ParticleData *p) override;
    
    size_t collectionSize() const { return _attractors.size(); }
    void add(const ofVec4f &attr) { _attractors.push_back(attr); }
    ofVec4f &get(size_t id) { return _attractors[id]; }
};

class BasicColorUpdater : public ParticleUpdater
{
public:
    virtual void update(double dt, ParticleData *p) override;
};

class PosColorUpdater : public ParticleUpdater
{
public:
    ofVec4f _minPos;
    ofVec4f _maxPos;
public:
    PosColorUpdater() : _minPos(0.0), _maxPos(1.0) { }
    
    virtual void update(double dt, ParticleData *p) override;
};

class VelColorUpdater : public ParticleUpdater
{
public:
    ofVec4f _minVel;
    ofVec4f _maxVel;
public:
    VelColorUpdater() : _minVel(0.0), _maxVel(1.0) { }
    
    virtual void update(double dt, ParticleData *p) override;
};

class BasicTimeUpdater : public ParticleUpdater
{
public:
    virtual void update(double dt, ParticleData *p) override;
};

#endif /* defined(__basicParticleSystem__ParticleUpdaters__) */
