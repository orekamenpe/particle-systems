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
    
public:
    FireEffect() { }
    ~FireEffect() { }
    
    bool initialize(size_t numParticles, ofTexture flameImage);
    bool initializeRenderer();
    void reset();
    void clean();
    
    void update(double dt);
    void cpuUpdate(double dt);
    void gpuUpdate(double dt);
    void draw();
    
    int numAllParticles();
    int numAliveParticles();
    
    int numFlameAliveParticles();
    int numGlowAliveParticles();
    int numEmberAliveParticles();
    
};

#endif /* defined(__basicParticleSystem__FireEffect__) */
