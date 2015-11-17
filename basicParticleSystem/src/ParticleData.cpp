//
//  ParticleData.cpp
//  basicParticleSystem
//
//  Created by Ibai on 17/11/15.
//
//

#include "ParticleData.h"

ParticleData::ParticleData()
{
}

ParticleData::ParticleData (size_t maxCount)
{
    generate(maxCount);
}

ParticleData::~ParticleData()
{
}

void ParticleData::generate(size_t maxSize)
{
    _count = maxSize;
    _countAlive = 0;
    
    _position.reset(new ofPoint[maxSize]);
    _color.reset(new ofPoint[maxSize]);
    _startColor.reset(new ofPoint[maxSize]);
    _endColor.reset(new ofPoint[maxSize]);
    _velocity.reset(new ofPoint[maxSize]);
    _acceleration.reset(new ofPoint[maxSize]);
    _time.reset(new ofPoint[maxSize]);
    _alive.reset(new bool[maxSize]);
}

void ParticleData::kill(size_t id)
{
    if (_countAlive > 0)
    {
        _alive[id] = false;
        swapData(id, _countAlive - 1);
        _countAlive--;
    }
}

void ParticleData::wake(size_t id)
{
    if (_countAlive < _count)
    {
        _alive[id] = true;
        swapData(id, _countAlive);
        _countAlive++;
    }
}

void ParticleData::swapData(size_t a, size_t b)
{
    std::swap(_position[a], _position[b]);
    std::swap(_color[a], _color[b]);
    std::swap(_startColor[a], _startColor[b]);
    std::swap(_endColor[a], _startColor[b]);
    std::swap(_velocity[a], _velocity[b]);
    std::swap(_acceleration[a], _acceleration[b]);
    std::swap(_time[a], _time[b]);
    std::swap(_alive[a], _alive[b]);
}
