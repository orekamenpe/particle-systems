//
//  FireEffect.cpp
//  basicParticleSystem
//
//  Created by Ibai on 19/11/15.
//
//

#include "FireEffect.h"
#include "ParticleUpdaters.h"
#include "ParticleGenerators.h"

bool FireEffect::initialize(size_t numParticles, ofTexture flameImage)
{
    //
    // particles
    //
    const size_t NUM_PARTICLES = numParticles == 0 ? 10 : numParticles;
    _flameSystem = std::make_shared<ParticleSystem>(NUM_PARTICLES);
    _glowSystem = std::make_shared<ParticleSystem>(NUM_PARTICLES);
    _emberSystem = std::make_shared<ParticleSystem>(NUM_PARTICLES);
    
    //
    // emitter:
    //
    auto particleEmitter = std::make_shared<ParticleEmitter>();
    {
        particleEmitter->_emitRate = (float)NUM_PARTICLES*0.45f;
        
        // position:
        auto posGenerator = std::make_shared<generators::RoundPosGen>();
        posGenerator->_center = ofVec3f{ 300.0, 300.0, 0.0};
        posGenerator->_radX = 15.0f;
        posGenerator->_radY = 15.0f;
        particleEmitter->addGenerator(posGenerator);
        
        // color:
        auto colGenerator = std::make_shared<generators::BasicColorGen>();
        colGenerator->_minStartCol = ofVec3f{ 0.7, 0.0, 0.7 };
        colGenerator->_maxStartCol = ofVec3f{ 1.0, 1.0, 1.0};
        colGenerator->_minEndCol = ofVec3f{ 0.5, 0.0, 0.6};
        colGenerator->_maxEndCol = ofVec3f{ 0.7, 0.5, 1.0};
        particleEmitter->addGenerator(colGenerator);
        
        // velocity
        auto velGenerator = std::make_shared<generators::BasicVelGen>();
        velGenerator->_minStartVel = ofVec3f{ ofRandomf(), ofRandomf(), 0.0f} * 10;
        velGenerator->_maxStartVel = velGenerator->_minStartVel;
        particleEmitter->addGenerator(velGenerator);
        
        // textures
        auto imgGenerator = std::make_shared<generators::BasicImageGen>();
        imgGenerator->_image = flameImage;
        imgGenerator->_size = ofVec2f(flameImage.getWidth(), flameImage.getHeight());
        particleEmitter->addGenerator(imgGenerator);
        
        // time
        auto timeGenerator = std::make_shared<generators::BasicTimeGen>();
        timeGenerator->_minTime = 30;
        timeGenerator->_maxTime = 30;
        particleEmitter->addGenerator(timeGenerator);
    }
    
    _flameSystem->addEmitter(particleEmitter);
    _glowSystem->addEmitter(particleEmitter);
    
    auto timeUpdater = std::make_shared<updaters::BasicTimeUpdater>();
    _flameSystem->addUpdater(timeUpdater);
    _glowSystem->addUpdater(timeUpdater);
    
    auto colorUpdater = std::make_shared<updaters::BasicColorUpdater>();
    _flameSystem->addUpdater(colorUpdater);
    _glowSystem->addUpdater(colorUpdater);
    
    auto eulerUpdater = std::make_shared<updaters::EulerUpdater>();
    eulerUpdater->_globalAcceleration = ofVec3f{ 0.0, 0.0, 0.0};
    _flameSystem->addUpdater(eulerUpdater);
    _glowSystem->addUpdater(eulerUpdater);
    
    return true;
}


void FireEffect::clean()
{
}

void FireEffect::update(double dt)
{
    static double time = 0.0;
    time += dt;
}

void FireEffect::cpuUpdate(double dt)
{
    _flameSystem->update(dt);
    _glowSystem->update(dt);
}

void FireEffect::draw()
{
    _flameSystem->draw();
    _glowSystem->draw();
}