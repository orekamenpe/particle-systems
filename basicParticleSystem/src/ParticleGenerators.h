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
#include "ofMain.h"

namespace generators
{
    //----------------------------------------------------
    class BoxPosGen : public ParticleGenerator
    {
    public:
        ofVec3f _pos;
        ofVec3f _maxStartPosOffset;
    public:
        BoxPosGen() : _pos(0.0), _maxStartPosOffset(0.0) { }
        
        virtual void generate(ParticleData *p, size_t startId, size_t endId) override;
    };
    
    //----------------------------------------------------
    class RoundPosGen : public ParticleGenerator
    {
    public:
        ofVec3f _center;
        float _radX;
        float _radY;
    public:
        RoundPosGen() : _center(0.0), _radX(0.0), _radY(0.0) { }
        RoundPosGen(const ofVec3f &center, double radX, double radY)
        : _center(center)
        , _radX((float)radX)
        , _radY((float)radY)
        { }
        
        virtual void generate(ParticleData *p, size_t startId, size_t endId) override;
    };
    
    //----------------------------------------------------
    class BasicColorGen : public ParticleGenerator
    {
    public:
        ofVec3f _minStartCol;
        ofVec3f _maxStartCol;
        ofVec3f _minEndCol;
        ofVec3f _maxEndCol;
    public:
        BasicColorGen() : _minStartCol(0.0), _maxStartCol(0.0), _minEndCol(0.0), _maxEndCol(0.0) { }
        
        virtual void generate(ParticleData *p, size_t startId, size_t endId) override;
    };
    
    //----------------------------------------------------
    class BasicVelGen : public ParticleGenerator
    {
    public:
        ofVec3f _minStartVel;
        ofVec3f _maxStartVel;
        
        float _direction;
        float _directionDev;
        
    public:
        BasicVelGen() : _minStartVel(0.0), _maxStartVel(0.0) { }
        
        virtual void generate(ParticleData *p, size_t startId, size_t endId) override;
    };
    
    //----------------------------------------------------
    class SphereVelGen : public ParticleGenerator
    {
    public:
        float _minVel;
        float _maxVel;
    public:
        SphereVelGen() : _minVel(0.0), _maxVel(0.0) { }
        
        virtual void generate(ParticleData *p, size_t startId, size_t endId) override;
    };
    
    //----------------------------------------------------
    class VelFromPosGen : public ParticleGenerator
    {
    public:
        ofVec3f _offset;
        float _minScale;
        float _maxScale;
    public:
        VelFromPosGen() : _offset(0.0), _minScale(0.0), _maxScale(0.0) { }
        VelFromPosGen(const ofVec3f &off, double minS, double maxS)
        : _offset(off)
        , _minScale((float)minS)
        , _maxScale((float)maxS)
        { }
        
        virtual void generate(ParticleData *p, size_t startId, size_t endId) override;
    };
    
    //----------------------------------------------------
    class BasicTimeGen : public ParticleGenerator
    {
    public:
        size_t _minTime;
        size_t _maxTime;
    public:
        BasicTimeGen() : _minTime(1), _maxTime(1) { }
        
        virtual void generate(ParticleData *p, size_t startId, size_t endId) override;
    };
    
    
    //----------------------------------------------------
    class BasicImageGen : public ParticleGenerator
    {
    public:
        ofImage _image;
        ofVec2f _startSize;
        ofVec2f _endSize;
        size_t _startOpacity;
        size_t _endOpacity;
    public:
        BasicImageGen() : _startSize(0.0f), _endSize(0.0f) {}
        BasicImageGen(const ofImage& image, const ofVec2f& startSize, const ofVec2f& endSize, size_t startOpacity, size_t endOpacity)
        : _image(image)
        , _startSize(startSize)
        , _endSize(endSize)
        , _startOpacity(startOpacity)
        , _endOpacity(endOpacity)
        {}
        
        virtual void generate(ParticleData *p, size_t startId, size_t endId) override;
        
    };
}

#endif /* defined(__basicParticleSystem__ParticleGenerators__) */
