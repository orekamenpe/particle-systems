//
//  ParticleSystem.h
//  basicParticleSystem
//
//  Created by Ibai on 17/11/15.
//
//

#ifndef __basicParticleSystem__ParticleSystem__
#define __basicParticleSystem__ParticleSystem__

#include "ParticleEmitter.h"
#include "ParticleUpdater.h"
#include "ParticleData.h"

class ParticleSystem
{
protected:
    ParticleData _particles;
    ParticleData _aliveParticles;
    
    size_t _count;
    
    std::vector<std::shared_ptr<ParticleEmitter>> _emitters;
    std::vector<std::shared_ptr<ParticleUpdater>> _updaters;
    
public:
    explicit ParticleSystem(size_t maxCount);
    virtual ~ParticleSystem() { }
    
    ParticleSystem(const ParticleSystem &) = delete;
    ParticleSystem &operator=(const ParticleSystem &) = delete;
    
    virtual void update(double dt);
    virtual void reset();
    
    virtual size_t numAllParticles() const { return _particles._count; }
    virtual size_t numAliveParticles() const { return _particles._countAlive; }
    
    void addEmitter(std::shared_ptr<ParticleEmitter> em) { _emitters.push_back(em); }
    void addUpdater(std::shared_ptr<ParticleUpdater> up) { _updaters.push_back(up); }
    
    ParticleData *finalData() { return &_particles; }
    
    static size_t computeMemoryUsage(const ParticleSystem &p);
};

#endif /* defined(__basicParticleSystem__ParticleSystem__) */
