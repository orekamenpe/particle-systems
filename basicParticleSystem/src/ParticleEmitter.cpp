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
    int rate = _fps / _emitRate;
    
    if (_fpsCounter == 0 || _fpsCounter % rate == 0)
    {
        const size_t maxNewParticles = 1;
        
        const size_t startId = p->_countAlive;
        const size_t endId = std::min(startId + maxNewParticles, p->_count-1);
        
        for (auto &gen : _generators)
        {
            gen->generate( p, startId, endId);
        }
        
        for (size_t i = startId; i < endId; ++i)
        {
            p->wake(i);
        }

    }
    
    if (_fpsCounter == _fps)
    {
        _fpsCounter = 0;
    }
    else
    {
        _fpsCounter++;
    }
}