//
//  ParticleEmitter.h
//  basicParticleSystem
//
//  Created by Ibai on 17/11/15.
//
//

#ifndef __basicParticleSystem__ParticleEmitter__
#define __basicParticleSystem__ParticleEmitter__

#include "ParticleData.h"
#include "ParticleGenerator.h"


class ParticleEmitter
{
protected:
    std::vector<std::shared_ptr<ParticleGenerator>> _generators;
public:
    float _emitRate{ 0.0 };
    int _fps{ 30 };
    int _fpsCounter;
    
public:
    ParticleEmitter() : _fpsCounter(0) { }
    virtual ~ParticleEmitter() { }
    
    // calls all the generators and at the end it activates (wakes) particle
    virtual void emit(ParticleData *p);
    
    void addGenerator(std::shared_ptr<ParticleGenerator> gen) { _generators.push_back(gen); }
};

#endif /* defined(__basicParticleSystem__ParticleEmitter__) */
