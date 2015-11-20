//
//  mathHelper.h
//  basicParticleSystem
//
//  Created by Ibai on 18/11/15.
//
//

#ifndef __basicParticleSystem__mathHelper__
#define __basicParticleSystem__mathHelper__

#include "ofMath.h"

namespace mathHelper{
    static ofVec3f linearRandVec4(const ofVec3f& min, const ofVec3f& max)
    {
        float x = min.x + sqrt(rand())*(max.x - min.x);
        float y = min.y + sqrt(rand())*(max.y - min.y);
        float z = min.z + sqrt(rand())*(max.z - min.z);
        
        return ofVec3f(x,y,z);
    }
    
    static float dotVec3f(const ofVec3f& a, const ofVec3f& b)
    {
        return a.dot(b);
    }
    
    static float mixf(float x, float y, float a)
    {
        return x * (1.0 - a) + y * a;
    }
    
    static ofVec3f mixVec3f(const ofVec3f& a, const ofVec3f& b, float m)
    {
        return a * (1.0 - m) + b * m;
    }
}

#endif /* defined(__basicParticleSystem__mathHelper__) */
