//
//  ParticleData.cpp
//  basicParticleSystem
//
//  Created by Ibai on 17/11/15.
//
//

#include "ParticleData.h"
#include "ofMain.h"

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
    
    _position.reset(new ofVec3f[maxSize]);
    _color.reset(new ofVec3f[maxSize]);
    _startColor.reset(new ofVec3f[maxSize]);
    _endColor.reset(new ofVec3f[maxSize]);
    _direction.reset(new ofVec3f[maxSize]);
    _velocity.reset(new ofVec3f[maxSize]);
    _acceleration.reset(new ofVec3f[maxSize]);
    _lifeTime.reset(new ssize_t[maxSize]);
    _life.reset(new size_t[maxSize]);
    _opacity.reset(new size_t[maxSize]);
    _startOpacity.reset(new size_t[maxSize]);
    _endOpacity.reset(new size_t[maxSize]);
    _size.reset(new ofVec2f[maxSize]);
    _startSize.reset(new ofVec2f[maxSize]);
    _endSize.reset(new ofVec2f[maxSize]);
    _alive.reset(new bool[maxSize]);
    
    _image.reset(new ofImage[maxSize]);
    _size.reset(new ofVec2f[maxSize]);
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
    std::swap(_endColor[a], _endColor[b]);
    std::swap(_direction[a], _direction[b]);
    std::swap(_velocity[a], _velocity[b]);
    std::swap(_acceleration[a], _acceleration[b]);
    std::swap(_lifeTime[a], _lifeTime[b]);
    std::swap(_life[a], _life[b]);
    std::swap(_opacity[a], _opacity[b]);
    std::swap(_startOpacity[a], _startOpacity[b]);
    std::swap(_endOpacity[a], _endOpacity[b]);
    std::swap(_size[a], _size[b]);
    std::swap(_startSize[a], _startSize[b]);
    std::swap(_endSize[a], _endSize[b]);
    std::swap(_alive[a], _alive[b]);
}

void ParticleData::copyOnlyAlive(const ParticleData *source, ParticleData *destination)
{
    assert(source->_count == destination->_count);
    
    size_t id = 0;
    for (size_t i = 0; i < source->_countAlive; ++i)
    {
        if (source->_alive[i])
        {
            destination->_position[id] = source->_position[i];
            destination->_color[id] = source->_color[i];
            destination->_startColor[id] = source->_startColor[i];
            destination->_endColor[id] = source->_endColor[i];
            destination->_direction[id] = source->_direction[i];
            destination->_velocity[id] = source->_velocity[i];
            destination->_acceleration[id] = source->_acceleration[i];
            destination->_lifeTime[id] = source->_lifeTime[i];
            destination->_life[id] = source->_life[i];
            destination->_opacity[id] = source->_opacity[i];
            destination->_startOpacity[id] = source->_startOpacity[i];
            destination->_endOpacity[id] = source->_endOpacity[i];
            destination->_size[id] = source->_size[i];
            destination->_startSize[id] = source->_startSize[i];
            destination->_endSize[id] = source->_endSize[i];
            destination->_alive[id] = true;
            
            destination->_image[id] = source->_image[i];
            destination->_size[id] = source->_size[i];
            id++;
        }
    }
    
    destination->_countAlive = id;
}

size_t ParticleData::computeMemoryUsage(const ParticleData &p)
{
    return p._count * (7 * sizeof(ofVec3f) + sizeof(bool)) + sizeof(size_t) * 2;
}

void ParticleData::draw(size_t id)
{
    ofSetColor(_color[id].x, _color[id].y, _color[id].z, _opacity[id]);
    
    _image[id].draw(_position[id].x - _size[id].x * 0.5f, _position[id].y, _size[id].x, _size[id].y);
}
