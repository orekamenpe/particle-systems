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

namespace FireEffectConsts
{
    const ofVec3f kStartPosition = ofVec3f(300.0f, 400.0f, 0.0f);
    const ofVec3f kYellowColor = ofVec3f{ 255, 255, 210 };
    const ofVec3f kRedColor = ofVec3f{ 255, 10, 10};
    
    const ofVec3f kBrightYellowColor = ofVec3f{ 255, 255, 230 };
}

using namespace FireEffectConsts;

bool FireEffect::initialize(size_t numParticles, ofImage glowImage, ofImage flame1Image, ofImage flame2Image, ofImage flame3Image, ofImage emberImage)
{
    //
    // particles
    //
    const size_t NUM_PARTICLES = numParticles == 0 ? 100 : numParticles;
    _flameSystem = std::make_shared<ParticleSystem>(NUM_PARTICLES);
    _glowSystem = std::make_shared<ParticleSystem>(NUM_PARTICLES);
    _emberSystem = std::make_shared<ParticleSystem>(NUM_PARTICLES);
    
    //
    // emitter:
    //
    auto particleEmitter = std::make_shared<ParticleEmitter>();
    {
        particleEmitter->_emitRate = 15;

        fillEmitterPosition(*particleEmitter, kStartPosition);
        
        // color:
        fillEmitterColor(*particleEmitter, kYellowColor, kYellowColor, kRedColor, kRedColor);

        // textures
        ofVec2f startSize = ofVec2f(glowImage.getWidth()*2.5f, glowImage.getHeight()*2.5f);
        ofVec2f endSize = ofVec2f(glowImage.getWidth(), glowImage.getHeight());
        float startOpacity = 15;
        float endOpacity = 5;
        fillEmitterTextures(*particleEmitter, glowImage, startSize, endSize, startOpacity, endOpacity);
        
        // velocity
        ofVec3f minStartVel = ofVec3f{ 1.25f, 0.0f, 0.0f};
        ofVec3f maxStartVel = minStartVel;
        float direction = -90.f;
        float directionDev = 0;
        fillEmitterVelocity(*particleEmitter, minStartVel, maxStartVel,  direction, directionDev);
        
        // time
        float minTime = 80;
        float maxTime = 80;
        fillEmitterTime(*particleEmitter, minTime, maxTime);
    }
    
    auto glowEmitter = std::make_shared<ParticleEmitter>();
    {
        glowEmitter->_emitRate = 15;
        
        // position:
        ofVec3f startPosition = kStartPosition;
        startPosition.y += 50;
        fillEmitterPosition(*glowEmitter, startPosition);
        
        // color:
        fillEmitterColor(*glowEmitter, kBrightYellowColor, kBrightYellowColor, kYellowColor, kYellowColor);
        
        // textures
        ofVec2f startSize = ofVec2f(glowImage.getWidth()*1.9f, glowImage.getHeight()*1.0f);
        ofVec2f endSize = ofVec2f(glowImage.getWidth()*0.1f, glowImage.getHeight()*0.3f);
        float startOpacity = 200;
        float endOpacity = 5;
        fillEmitterTextures(*glowEmitter, glowImage, startSize, endSize, startOpacity, endOpacity);
        
        // velocity
        ofVec3f minStartVel = ofVec3f{ 0.25f, 0.0f, 0.0f};
        ofVec3f maxStartVel = minStartVel;
        float direction = -90.f;
        float directionDev = 0;
        fillEmitterVelocity(*glowEmitter, minStartVel, maxStartVel,  direction, directionDev);
        
        // time
        float minTime = 30;
        float maxTime = 30;
        fillEmitterTime(*glowEmitter, minTime, maxTime);
    }

    auto flame1ParticleEmitter = std::make_shared<ParticleEmitter>();
    {
        flame1ParticleEmitter->_emitRate = 3;
        
        // position:
        fillEmitterPosition(*flame1ParticleEmitter, kStartPosition);
        
        // color:
        fillEmitterColor(*flame1ParticleEmitter, kYellowColor, kYellowColor, kRedColor, kRedColor);
        
        // textures
        ofVec2f startSize = ofVec2f(flame1Image.getWidth()*0.5f, flame1Image.getHeight()*0.5f);
        ofVec2f endSize = ofVec2f(flame1Image.getWidth()*0.15f, flame1Image.getHeight()*0.15f);
        float startOpacity = 200;
        float endOpacity = 0;
        fillEmitterTextures(*flame1ParticleEmitter, flame1Image, startSize, endSize, startOpacity, endOpacity);
        
        // velocity
        ofVec3f minStartVel = ofVec3f{ 2.5f, 0.0f, 0.0f};
        ofVec3f maxStartVel = minStartVel;
        float direction = -90.f;
        float directionDev = 5;
        fillEmitterVelocity(*flame1ParticleEmitter, minStartVel, maxStartVel,  direction, directionDev);
        
        // time
        float minTime = 30;
        float maxTime = 30;
        fillEmitterTime(*flame1ParticleEmitter, minTime, maxTime);
    }
    
    auto flame2ParticleEmitter = std::make_shared<ParticleEmitter>();
    {
        flame2ParticleEmitter->_emitRate = 4;
        
        // position:
        fillEmitterPosition(*flame2ParticleEmitter, kStartPosition);
        
        // color:
        fillEmitterColor(*flame2ParticleEmitter, kYellowColor, kYellowColor, kRedColor, kRedColor);
        
        // textures
        ofVec2f startSize = ofVec2f(flame2Image.getWidth()*0.5f, flame2Image.getHeight()*0.5f);
        ofVec2f endSize = ofVec2f(flame2Image.getWidth()*0.15f, flame2Image.getHeight()*0.15f);
        float startOpacity = 200;
        float endOpacity = 0;
        fillEmitterTextures(*flame2ParticleEmitter, flame2Image, startSize, endSize, startOpacity, endOpacity);
        
        // velocity
        ofVec3f minStartVel = ofVec3f{ 2.5f, 0.0f, 0.0f};
        ofVec3f maxStartVel = minStartVel;
        float direction = -90.f;
        float directionDev = 5;
        fillEmitterVelocity(*flame2ParticleEmitter, minStartVel, maxStartVel,  direction, directionDev);
        
        // time
        float minTime = 30;
        float maxTime = 30;
        fillEmitterTime(*flame2ParticleEmitter, minTime, maxTime);
    }
    
    auto flame3ParticleEmitter = std::make_shared<ParticleEmitter>();
    {
        flame3ParticleEmitter->_emitRate = 5;
        
        // position:
        fillEmitterPosition(*flame3ParticleEmitter, kStartPosition);
        
        // color:
        fillEmitterColor(*flame3ParticleEmitter, kYellowColor, kYellowColor, kRedColor, kRedColor);
        
        // textures
        ofVec2f startSize = ofVec2f(flame3Image.getWidth()*0.5f, flame3Image.getHeight()*0.5f);
        ofVec2f endSize = ofVec2f(flame3Image.getWidth()*0.15f, flame3Image.getHeight()*0.15f);
        float startOpacity = 200;
        float endOpacity = 0;
        fillEmitterTextures(*flame3ParticleEmitter, flame3Image, startSize, endSize, startOpacity, endOpacity);
        
        // velocity
        ofVec3f minStartVel = ofVec3f{ 2.5f, 0.0f, 0.0f};
        ofVec3f maxStartVel = minStartVel;
        float direction = -90.f;
        float directionDev = 5;
        fillEmitterVelocity(*flame3ParticleEmitter, minStartVel, maxStartVel,  direction, directionDev);
        
        // time
        float minTime = 30;
        float maxTime = 30;
        fillEmitterTime(*flame3ParticleEmitter, minTime, maxTime);
    }

    auto emberParticleEmitter = std::make_shared<ParticleEmitter>();
    {
        emberParticleEmitter->_emitRate = 1;
        
        // position:
        auto posGenerator = std::make_shared<generators::BoxPosGen>();
        posGenerator->_pos = ofVec3f(300, 450.0f, 0.0f);
        emberParticleEmitter->addGenerator(posGenerator);
        
        // color:
        auto colGenerator = std::make_shared<generators::BasicColorGen>();
        colGenerator->_minStartCol = ofVec3f{ 255, 250, 10};
        colGenerator->_maxStartCol = ofVec3f{ 255, 250, 10};
        colGenerator->_minEndCol = ofVec3f{ 255, 10, 10};
        colGenerator->_maxEndCol = ofVec3f{ 255, 10, 10};;
        emberParticleEmitter->addGenerator(colGenerator);
        
        // textures
        auto imgGenerator = std::make_shared<generators::BasicImageGen>();
        imgGenerator->_image = emberImage;
        imgGenerator->_startSize = ofVec2f(emberImage.getWidth() * 0.05f, emberImage.getHeight() * 0.05f);
        imgGenerator->_endSize = ofVec2f(emberImage.getWidth() * 0.05f, emberImage.getHeight() * 0.05f);
        imgGenerator->_startOpacity = 200;
        emberParticleEmitter->addGenerator(imgGenerator);
        
        // velocity
        auto velGenerator = std::make_shared<generators::BasicVelGen>();
        velGenerator->_minStartVel = ofVec3f{ 2.5f, 0.0f, 0.0f};
        velGenerator->_maxStartVel = velGenerator->_minStartVel;
        velGenerator->_direction = -90.0f;
        velGenerator->_directionDev = 30.0f;
        emberParticleEmitter->addGenerator(velGenerator);
        
        // time
        auto timeGenerator = std::make_shared<generators::BasicTimeGen>();
        timeGenerator->_minTime = 60;
        timeGenerator->_maxTime = 60;
        emberParticleEmitter->addGenerator(timeGenerator);
    }


    _glowSystem->addEmitter(particleEmitter);
    _glowSystem->addEmitter(glowEmitter);
    _flameSystem->addEmitter(flame1ParticleEmitter);
    _flameSystem->addEmitter(flame2ParticleEmitter);
    _flameSystem->addEmitter(flame3ParticleEmitter);
    _emberSystem->addEmitter(emberParticleEmitter);
    
    
    auto moveUpdater = std::make_shared<updaters::BasicMoveUpdater>();
    _flameSystem->addUpdater(moveUpdater);
    _glowSystem->addUpdater(moveUpdater);
    _emberSystem->addUpdater(moveUpdater);
    
    auto timeUpdater = std::make_shared<updaters::BasicTimeUpdater>();
    _flameSystem->addUpdater(timeUpdater);
    _glowSystem->addUpdater(timeUpdater);
    _emberSystem->addUpdater(timeUpdater);
    
    auto colorUpdater = std::make_shared<updaters::BasicColorUpdater>();
    _flameSystem->addUpdater(colorUpdater);
    _glowSystem->addUpdater(colorUpdater);
    _emberSystem->addUpdater(colorUpdater);
    
    auto opacityUpdater = std::make_shared<updaters::BasicOpacityUpdater>();
    _flameSystem->addUpdater(opacityUpdater);
    _glowSystem->addUpdater(opacityUpdater);
    
    auto sizeUpdater = std::make_shared<updaters::BasicSizeUpdater>();
    _flameSystem->addUpdater(sizeUpdater);
    _glowSystem->addUpdater(sizeUpdater);
    
    return true;
}

void FireEffect::fillEmitterPosition(ParticleEmitter& emitter, const ofVec3f& startPosition)
{
    auto posGenerator = std::make_shared<generators::BoxPosGen>();
    posGenerator->_pos = startPosition;
    emitter.addGenerator(posGenerator);
}

void FireEffect::fillEmitterColor(ParticleEmitter& emitter, const ofVec3f& minStartColor, const ofVec3f& maxStartColor, const ofVec3f& minEndColor, const ofVec3f& maxEndColor)
{
    auto colGenerator = std::make_shared<generators::BasicColorGen>();
    colGenerator->_minStartCol = minStartColor;
    colGenerator->_maxStartCol = maxStartColor;
    colGenerator->_minEndCol = minEndColor;
    colGenerator->_maxEndCol = maxEndColor;
    emitter.addGenerator(colGenerator);
}

void FireEffect::fillEmitterTextures(ParticleEmitter& emitter, const ofImage& image, const ofVec2f& startSize, const ofVec2f& endSize, float startOpacity, float endOpacity)
{
    auto imgGenerator = std::make_shared<generators::BasicImageGen>();
    imgGenerator->_image = image;
    imgGenerator->_startSize = startSize;
    imgGenerator->_endSize = endSize;
    imgGenerator->_startOpacity = startOpacity;
    imgGenerator->_endOpacity = endOpacity;
    emitter.addGenerator(imgGenerator);
}

void FireEffect::fillEmitterVelocity(ParticleEmitter& emitter, const ofVec3f& minStartVel, const ofVec3f& maxStartVel, float direction, float directionDev)
{
    auto velGenerator = std::make_shared<generators::BasicVelGen>();
    velGenerator->_minStartVel = minStartVel;
    velGenerator->_maxStartVel = maxStartVel;
    velGenerator->_direction = direction;
    velGenerator->_directionDev = directionDev;
    emitter.addGenerator(velGenerator);
}

void FireEffect::fillEmitterTime(ParticleEmitter& emitter, float minTime, float maxTime)
{
    auto timeGenerator = std::make_shared<generators::BasicTimeGen>();
    timeGenerator->_minTime = minTime;
    timeGenerator->_maxTime = maxTime;
    emitter.addGenerator(timeGenerator);
}

void FireEffect::clean()
{
}

void FireEffect::update()
{
    _flameSystem->update();
    _glowSystem->update();
    _emberSystem->update();
}

void FireEffect::draw()
{
    _emberSystem->draw();
    _flameSystem->draw();
    _glowSystem->draw();
    

}