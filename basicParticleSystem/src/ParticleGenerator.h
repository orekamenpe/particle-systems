//
//  ParticleGenerator.h
//  basicParticleSystem
//
//  Created by Ibai on 17/11/15.
//
//

#ifndef __basicParticleSystem__ParticleGenerator__
#define __basicParticleSystem__ParticleGenerator__

#include "ParticleData.h"

class ParticleGenerator
{
public:
    ParticleGenerator() { }
    virtual ~ParticleGenerator() { }
    
    virtual void generate(double dt, ParticleData *p, size_t startId, size_t endId) = 0;
};

#endif /* defined(__basicParticleSystem__ParticleGenerator__) */
