//
//  particle.h
//  simpleParticleSystem
//
//  Created by Ibai on 16/11/15.
//
//

#ifndef __simpleParticleSystem__particle__
#define __simpleParticleSystem__particle__

#include "ofMain.h"

class Particle {
public:
    Particle();
    Particle(ofPoint pos);
    Particle(ofPoint pos, ofPoint vel, float size, ofTexture* texture);
    ~Particle();
    void setup();
    
    void update();
    void draw();
    bool isOffscreen();
    
    void setColor(int r, int g, int b);
    void setColor( ofColor c );
    
    ofPoint _pos;
    ofPoint _vel;
    
    float _size;
    
    int _age;
    int _lifetime;
    bool _dead;
    
    ofTexture* _texture;
    
    int _colorR;
    int _colorG;
    int _colorB;
    int _opacity;
};

#endif /* defined(__simpleParticleSystem__particle__) */
