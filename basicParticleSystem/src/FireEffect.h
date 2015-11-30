//
//  FireEffect.h
//  basicParticleSystem
//
//  Created by Ibai on 19/11/15.
//
//

#ifndef __basicParticleSystem__FireEffect__
#define __basicParticleSystem__FireEffect__

#include "ParticleSystem.h"
#include "ofMain.h"

class FireEffect
{
private:
    // the fire is going to be composed by 3 particle systems:
    // - flames
    // - glow
    // - ember
    std::shared_ptr<ParticleSystem> _flameSystem;
    std::shared_ptr<ParticleSystem> _glowSystem;
    std::shared_ptr<ParticleSystem> _emberSystem;
    
    void fillEmitterPosition(ParticleEmitter& emitter, const ofVec3f& startPosition);
    void fillEmitterColor(ParticleEmitter& emitter, const ofVec3f& minStartColor, const ofVec3f& maxStartColor, const ofVec3f& minEndColor, const ofVec3f& maxEndColor);
    void fillEmitterTextures(ParticleEmitter& emitter, const ofImage& image, const ofVec2f& startSize, const ofVec2f& endSize, float startOpacity, float endOpacity);
    void fillEmitterVelocity(ParticleEmitter& emitter, const ofVec3f& minStartVel, const ofVec3f& maxStartVel, float direction, float directionDev);
    void fillEmitterTime(ParticleEmitter& emitter, float minTime, float maxTime);

    
public:
    FireEffect() { }
    ~FireEffect() { }
    
    bool initialize(size_t numParticles, ofImage glowImage, ofImage flame1Image, ofImage flame2Image, ofImage flame3Image, ofImage emberImage);
    bool initializeRenderer();
    void reset();
    void clean();
    
    void update();
    void draw();
    
    int numAllParticles();
    int numAliveParticles();
    
    int numFlameAliveParticles();
    int numGlowAliveParticles();
    int numEmberAliveParticles();
    
};

#endif /* defined(__basicParticleSystem__FireEffect__) */
