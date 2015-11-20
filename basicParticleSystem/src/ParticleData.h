//
//  ParticleData.h
//  basicParticleSystem
//
//  Created by Ibai on 17/11/15.
//
//

#ifndef __basicParticleSystem__ParticleData__
#define __basicParticleSystem__ParticleData__

#include "ofMath.h"
#include "ofTexture.h"

class ParticleData
{
public:
    std::unique_ptr<ofVec3f[]> _position;
    std::unique_ptr<ofVec3f[]> _color;
    std::unique_ptr<ofVec3f[]> _startColor;
    std::unique_ptr<ofVec3f[]> _endColor;
    std::unique_ptr<ofVec3f[]> _direction;
    std::unique_ptr<ofVec3f[]> _velocity;
    std::unique_ptr<ofVec3f[]> _acceleration;
    std::unique_ptr<ssize_t[]> _lifeTime;
    std::unique_ptr<size_t[]> _life;
    std::unique_ptr<bool[]> _alive;

    std::unique_ptr<ofVec2f[]> _size;
    std::unique_ptr<ofTexture[]> _image;
    
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
    
    static void copyOnlyAlive(const ParticleData *source, ParticleData *destination);
    static size_t computeMemoryUsage(const ParticleData &p);
    
    void draw(size_t id);
};

#endif /* defined(__basicParticleSystem__ParticleData__) */
