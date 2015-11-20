//
//  ParticleEmitter.cpp
//  basicParticleSystem
//
//  Created by Ibai on 17/11/15.
//
//

#include "ParticleEmitter.h"

void ParticleEmitter::emit(ParticleData *p)
{
    const size_t maxNewParticles = static_cast<size_t>(_emitRate);
    const size_t startId = p->_countAlive;
    const size_t endId = std::min(startId + maxNewParticles, p->_count-1);
    
    for (auto &gen : _generators)
        gen->generate( p, startId, endId);
    
    for (size_t i = startId; i < endId; ++i)
    {
        p->wake(i);
    }
}