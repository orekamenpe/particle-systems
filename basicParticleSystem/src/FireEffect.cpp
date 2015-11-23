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
        
        // position:
        auto posGenerator = std::make_shared<generators::BoxPosGen>();
        posGenerator->_pos = ofVec3f(300.0f, 400.0f, 0.0f);
        particleEmitter->addGenerator(posGenerator);
        
        // color:
        auto colGenerator = std::make_shared<generators::BasicColorGen>();
        colGenerator->_minStartCol = ofVec3f{ 255, 255, 210 };
        colGenerator->_maxStartCol = ofVec3f{ 255, 255, 210};
        colGenerator->_minEndCol = ofVec3f{ 255, 10, 10};
        colGenerator->_maxEndCol = ofVec3f{ 255, 10, 10};
        particleEmitter->addGenerator(colGenerator);
        
        // textures
        auto imgGenerator = std::make_shared<generators::BasicImageGen>();
        imgGenerator->_image = glowImage;
        imgGenerator->_startSize = ofVec2f(glowImage.getWidth()*2.5f, glowImage.getHeight()*2.5f);
        imgGenerator->_endSize = ofVec2f(glowImage.getWidth() * 1.0f, glowImage.getHeight() * 1.0f);
        imgGenerator->_startOpacity = 15;
        imgGenerator->_endOpacity = 5;
        particleEmitter->addGenerator(imgGenerator);
        
        // velocity
        auto velGenerator = std::make_shared<generators::BasicVelGen>();
        velGenerator->_minStartVel = ofVec3f{ 1.25f, 0.0f, 0.0f};
        velGenerator->_maxStartVel = velGenerator->_minStartVel;
        velGenerator->_direction = -90.0f;
        //velGenerator->_directionDev = 20.0f;
        particleEmitter->addGenerator(velGenerator);
        
        // time
        auto timeGenerator = std::make_shared<generators::BasicTimeGen>();
        timeGenerator->_minTime = 80;
        timeGenerator->_maxTime = 80;
        particleEmitter->addGenerator(timeGenerator);
    }
    
    auto glowEmitter = std::make_shared<ParticleEmitter>();
    {
        glowEmitter->_emitRate = 15;
        
        // position:
        auto posGenerator = std::make_shared<generators::BoxPosGen>();
        posGenerator->_pos = ofVec3f(300.0f, 450.0f, 0.0f);
        glowEmitter->addGenerator(posGenerator);
        
        // color:
        auto colGenerator = std::make_shared<generators::BasicColorGen>();
        colGenerator->_minStartCol = ofVec3f{ 255, 255, 230 };
        colGenerator->_maxStartCol = ofVec3f{ 255, 255, 230};
        colGenerator->_minEndCol = ofVec3f{ 255, 255, 210};
        colGenerator->_maxEndCol = ofVec3f{ 255, 255, 210};
        glowEmitter->addGenerator(colGenerator);
        
        // textures
        auto imgGenerator = std::make_shared<generators::BasicImageGen>();
        imgGenerator->_image = glowImage;
        imgGenerator->_startSize = ofVec2f(glowImage.getWidth()*1.8f, glowImage.getHeight()*1.0f);
        imgGenerator->_endSize = ofVec2f(glowImage.getWidth() * 0.1f, glowImage.getHeight() * 0.3f);
        imgGenerator->_startOpacity = 200;
        imgGenerator->_endOpacity = 5;
        glowEmitter->addGenerator(imgGenerator);
        
        // velocity
        auto velGenerator = std::make_shared<generators::BasicVelGen>();
        velGenerator->_minStartVel = ofVec3f{ 1.25f, 0.0f, 0.0f};
        velGenerator->_maxStartVel = velGenerator->_minStartVel;
        velGenerator->_direction = -90.0f;
        //velGenerator->_directionDev = 20.0f;
        glowEmitter->addGenerator(velGenerator);
        
        // time
        auto timeGenerator = std::make_shared<generators::BasicTimeGen>();
        timeGenerator->_minTime = 70;
        timeGenerator->_maxTime = 70;
        glowEmitter->addGenerator(timeGenerator);
    }
    
    auto flame1ParticleEmitter = std::make_shared<ParticleEmitter>();
    {
        flame1ParticleEmitter->_emitRate = 3;
        
        // position:
        auto posGenerator = std::make_shared<generators::BoxPosGen>();
        posGenerator->_pos = ofVec3f(300.0f, 400.0f, 0.0f);
        flame1ParticleEmitter->addGenerator(posGenerator);
        
        // color:
        auto colGenerator = std::make_shared<generators::BasicColorGen>();
        colGenerator->_minStartCol = ofVec3f{ 255, 255, 210 };
        colGenerator->_maxStartCol = ofVec3f{ 255, 255, 210};
        colGenerator->_minEndCol = ofVec3f{ 255, 10, 10};
        colGenerator->_maxEndCol = ofVec3f{ 255, 10, 10};
        flame1ParticleEmitter->addGenerator(colGenerator);
        
        // textures
        auto imgGenerator = std::make_shared<generators::BasicImageGen>();
        imgGenerator->_image = flame1Image;
        imgGenerator->_startSize = ofVec2f(flame1Image.getWidth() * 0.5f, flame1Image.getHeight() * 0.5f);
        imgGenerator->_endSize = ofVec2f(flame1Image.getWidth() * 0.15f, flame1Image.getHeight() * 0.15f);
        imgGenerator->_startOpacity = 200;
        imgGenerator->_endOpacity = 0;
        flame1ParticleEmitter->addGenerator(imgGenerator);
        
        // velocity
        auto velGenerator = std::make_shared<generators::BasicVelGen>();
        velGenerator->_minStartVel = ofVec3f{ 2.5f, 0.0f, 0.0f};
        velGenerator->_maxStartVel = velGenerator->_minStartVel;
        velGenerator->_direction = -90.0f;
        velGenerator->_directionDev = 5.0f;
        flame1ParticleEmitter->addGenerator(velGenerator);
        
        // time
        auto timeGenerator = std::make_shared<generators::BasicTimeGen>();
        timeGenerator->_minTime = 30;
        timeGenerator->_maxTime = 30;
        flame1ParticleEmitter->addGenerator(timeGenerator);
    }
    
    auto flame2ParticleEmitter = std::make_shared<ParticleEmitter>();
    {
        flame2ParticleEmitter->_emitRate = 4;
        
        // position:
        auto posGenerator = std::make_shared<generators::BoxPosGen>();
        posGenerator->_pos = ofVec3f(300.0f, 400.0f, 0.0f);
        flame2ParticleEmitter->addGenerator(posGenerator);
        
        // color:
        auto colGenerator = std::make_shared<generators::BasicColorGen>();
        colGenerator->_minStartCol = ofVec3f{ 255, 255, 210 };
        colGenerator->_maxStartCol = ofVec3f{ 255, 255, 210};
        colGenerator->_minEndCol = ofVec3f{ 255, 10, 10};
        colGenerator->_maxEndCol = ofVec3f{ 255, 10, 10};;
        flame2ParticleEmitter->addGenerator(colGenerator);
        
        // textures
        auto imgGenerator = std::make_shared<generators::BasicImageGen>();
        imgGenerator->_image = flame2Image;
        imgGenerator->_startSize = ofVec2f(flame2Image.getWidth() * 0.5f, flame2Image.getHeight() * 0.5f);
        imgGenerator->_endSize = ofVec2f(flame2Image.getWidth() * 0.15f, flame2Image.getHeight() * 0.15f);
        imgGenerator->_startOpacity = 200;
        imgGenerator->_endOpacity = 0;
        flame2ParticleEmitter->addGenerator(imgGenerator);
        
        // velocity
        auto velGenerator = std::make_shared<generators::BasicVelGen>();
        velGenerator->_minStartVel = ofVec3f{ 2.5f, 0.0f, 0.0f};
        velGenerator->_maxStartVel = velGenerator->_minStartVel;
        velGenerator->_direction = -90.0f;
        velGenerator->_directionDev = 5.0f;
        flame2ParticleEmitter->addGenerator(velGenerator);
        
        // time
        auto timeGenerator = std::make_shared<generators::BasicTimeGen>();
        timeGenerator->_minTime = 30;
        timeGenerator->_maxTime = 30;
        flame2ParticleEmitter->addGenerator(timeGenerator);
    }
    
    auto flame3ParticleEmitter = std::make_shared<ParticleEmitter>();
    {
        flame3ParticleEmitter->_emitRate = 5;
        
        // position:
        auto posGenerator = std::make_shared<generators::BoxPosGen>();
        posGenerator->_pos = ofVec3f(300.0f, 400.0f, 0.0f);
        flame3ParticleEmitter->addGenerator(posGenerator);
        
        // color:
        auto colGenerator = std::make_shared<generators::BasicColorGen>();
        colGenerator->_minStartCol = ofVec3f{ 255, 255, 210 };
        colGenerator->_maxStartCol = ofVec3f{ 255, 255, 210};
        colGenerator->_minEndCol = ofVec3f{ 255, 10, 10};
        colGenerator->_maxEndCol = ofVec3f{ 255, 10, 10};;
        flame3ParticleEmitter->addGenerator(colGenerator);
        
        // textures
        auto imgGenerator = std::make_shared<generators::BasicImageGen>();
        imgGenerator->_image = flame3Image;
        imgGenerator->_startSize = ofVec2f(flame3Image.getWidth() * 0.5f, flame3Image.getHeight() * 0.5f);
        imgGenerator->_endSize = ofVec2f(flame3Image.getWidth() * 0.15f, flame3Image.getHeight() * 0.15f);
        imgGenerator->_startOpacity = 200;
        imgGenerator->_endOpacity = 0;
        flame3ParticleEmitter->addGenerator(imgGenerator);
        
        // velocity
        auto velGenerator = std::make_shared<generators::BasicVelGen>();
        velGenerator->_minStartVel = ofVec3f{ 2.5f, 0.0f, 0.0f};
        velGenerator->_maxStartVel = velGenerator->_minStartVel;
        velGenerator->_direction = -90.0f;
        velGenerator->_directionDev = 5.0f;
        flame3ParticleEmitter->addGenerator(velGenerator);
        
        // time
        auto timeGenerator = std::make_shared<generators::BasicTimeGen>();
        timeGenerator->_minTime = 30;
        timeGenerator->_maxTime = 30;
        flame3ParticleEmitter->addGenerator(timeGenerator);
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