//
//  particleController.h
//  simpleParticleSystem
//
//  Created by Ibai on 16/11/15.
//
//

#ifndef __simpleParticleSystem__particleController__
#define __simpleParticleSystem__particleController__

#include "ofMain.h"
#include "particle.h"

class ParticleController {
    
public:
    ParticleController();
    ParticleController(ofTexture &text, ofPoint pos, int rate, float sizeMin, float sizeMax, float direction, float directionDev);
    void update();
    void draw();
    
    void addParticle(ofPoint pos);
    void addParticles(ofPoint pos, int amt);
    void addParticles(int amt);
    void removeParticles(int amt);
    
    int getParticleCount();
    
    std::list<Particle> _particles;
    
    int _rate; // emitting rate
    int _rateDeviation; // emitting rate deviation
    float _particleSizeMin;
    float _particleSizeMax;
    ofPoint _position; // position of the emitter
    float _direction; // angle in degrees
    float _directionDeviation; // min/max deviation from Direction, angle in degrees
    ofTexture* _particleTexture;
    
    int _colorIndex;
    int _differentColors;
    ofColor nextColor();
};
#endif /* defined(__simpleParticleSystem__particleController__) */
