//
//  particle.h
//  simpleParticleSystem
//
//  Created by Ibai on 16/11/15.
//
//

#ifndef __simpleParticleSystem__particle__
#define __simpleParticleSystem__particle__

#include "ofColor.h"

class Particle {
private:
    float _x;
    float _y;
    ofColor _color;
    
public:
    Particle();
    
    void moveTo(float xDestiny, float yDestiny);
    void draw();
    
    void setPosition(float x, float y);
    const float getX() const { return _x; };
    const float getY() const { return _y; };
};

#endif /* defined(__simpleParticleSystem__particle__) */
