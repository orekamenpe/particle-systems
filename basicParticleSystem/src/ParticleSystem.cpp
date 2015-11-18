//
//  ParticleSystem.cpp
//  basicParticleSystem
//
//  Created by Ibai on 17/11/15.
//
//

#include "ParticleSystem.h"
#include "ofPoint.h"

ParticleSystem::ParticleSystem(size_t maxCount)
{
    _count = maxCount;
    _particles.generate(maxCount);
    _aliveParticles.generate(maxCount);
    
    for (size_t i = 0; i < maxCount; ++i)
        _particles._alive[i] = false;
}

void ParticleSystem::update(double dt)
{
    for (auto & em : _emitters)
    {
        em->emit(dt, &_particles);
    }
    
    for (size_t i = 0; i < _count; ++i)
    {
        _particles._acceleration[i] = ofPoint(0.0f);
    }
    
    for (auto & up : _updaters)
    {
        up->update(dt, &_particles);
    }
    
    //ParticleData::copyOnlyAlive(&_particles, &_aliveParticles);
}

void ParticleSystem::reset()
{
    _particles._countAlive = 0;
}

size_t ParticleSystem::computeMemoryUsage(const ParticleSystem &p)
{
    return 2 * ParticleData::computeMemoryUsage(p._particles);
}