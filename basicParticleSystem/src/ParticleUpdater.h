//
//  ParticleUpdater.h
//  basicParticleSystem
//
//  Created by Ibai on 17/11/15.
//
//

#ifndef __basicParticleSystem__ParticleUpdater__
#define __basicParticleSystem__ParticleUpdater__

#include "ParticleData.h"


class ParticleUpdater
{
public:
    ParticleUpdater() { }
    virtual ~ParticleUpdater() { }
    
    virtual void update(ParticleData *p) = 0;
};

#endif /* defined(__basicParticleSystem__ParticleUpdater__) */
