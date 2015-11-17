//
//  ParticleData.h
//  basicParticleSystem
//
//  Created by Ibai on 17/11/15.
//
//

#ifndef __basicParticleSystem__ParticleData__
#define __basicParticleSystem__ParticleData__

#include "ofPoint.h"

class ParticleData
{
public:
    std::unique_ptr<ofPoint[]> _position;
    std::unique_ptr<ofPoint[]> _color;
    std::unique_ptr<ofPoint[]> _startColor;
    std::unique_ptr<ofPoint[]> _endColor;
    std::unique_ptr<ofPoint[]> _velocity;
    std::unique_ptr<ofPoint[]> _acceleration;
    std::unique_ptr<ofPoint[]> _time;
    std::unique_ptr<bool[]> _alive;
    
    size_t _count {0};
    size_t _countAlive {0};
    
public:
    ParticleData();
    explicit ParticleData (size_t maxCount);
    ~ParticleData();
    
    ParticleData(const ParticleData &) = delete;
    ParticleData &operator=(const ParticleData &) = delete;
    
    void generate(size_t maxSize);
    void kill(size_t id);
    void wake(size_t id);
    void swapData(size_t a, size_t b);
};

#endif /* defined(__basicParticleSystem__ParticleData__) */
