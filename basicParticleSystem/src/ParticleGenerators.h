//
//  ParticleGenerators.h
//  basicParticleSystem
//
//  Created by Ibai on 18/11/15.
//
//

#ifndef __basicParticleSystem__ParticleGenerators__
#define __basicParticleSystem__ParticleGenerators__

#include "ParticleGenerator.h"
#include "ofPoint.h"

//----------------------------------------------------
class BoxPosGen : public ParticleGenerator
{
public:
    ofPoint _pos;
    ofPoint _maxStartPosOffset;
public:
    BoxPosGen() : _pos(0.0), _maxStartPosOffset(0.0) { }
    
    virtual void generate(double dt, ParticleData *p, size_t startId, size_t endId) override;
};

//----------------------------------------------------
class RoundPosGen : public ParticleGenerator
{
public:
    ofPoint _center;
    float _radX;
    float _radY;
public:
    RoundPosGen() : _center(0.0), _radX(0.0), _radY(0.0) { }
    RoundPosGen(const ofPoint &center, double radX, double radY)
				: _center(center)
				, _radX((float)radX)
				, _radY((float)radY)
    { }
    
    virtual void generate(double dt, ParticleData *p, size_t startId, size_t endId) override;
};

//----------------------------------------------------
class BasicColorGen : public ParticleGenerator
{
public:
    ofPoint _minStartCol;
    ofPoint _maxStartCol;
    ofPoint _minEndCol;
    ofPoint _maxEndCol;
public:
    BasicColorGen() : _minStartCol(0.0), _maxStartCol(0.0), _minEndCol(0.0), _maxEndCol(0.0) { }
    
    virtual void generate(double dt, ParticleData *p, size_t startId, size_t endId) override;
};

//----------------------------------------------------
class BasicVelGen : public ParticleGenerator
{
public:
    ofPoint _minStartVel;
    ofPoint _maxStartVel;
public:
    BasicVelGen() : _minStartVel(0.0), _maxStartVel(0.0) { }
    
    virtual void generate(double dt, ParticleData *p, size_t startId, size_t endId) override;
};

//----------------------------------------------------
class SphereVelGen : public ParticleGenerator
{
public:
    float _minVel;
    float _maxVel;
public:
    SphereVelGen() : _minVel(0.0), _maxVel(0.0) { }
    
    virtual void generate(double dt, ParticleData *p, size_t startId, size_t endId) override;
};

//----------------------------------------------------
class VelFromPosGen : public ParticleGenerator
{
public:
    ofPoint _offset;
    float _minScale;
    float _maxScale;
public:
    VelFromPosGen() : _offset(0.0), _minScale(0.0), _maxScale(0.0) { }
    VelFromPosGen(const ofPoint &off, double minS, double maxS)
				: _offset(off)
				, _minScale((float)minS)
				, _maxScale((float)maxS)
    { }
    
    virtual void generate(double dt, ParticleData *p, size_t startId, size_t endId) override;
};

//----------------------------------------------------
class BasicTimeGen : public ParticleGenerator
{
public:
    float _minTime;
    float _maxTime;
public:
    BasicTimeGen() : _minTime(0.0), _maxTime(0.0) { }
    
    virtual void generate(double dt, ParticleData *p, size_t startId, size_t endId) override;
};

#endif /* defined(__basicParticleSystem__ParticleGenerators__) */
