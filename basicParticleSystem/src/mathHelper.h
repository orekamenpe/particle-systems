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
    static ofVec3f linearRandVec3(const ofVec3f& min, const ofVec3f& max)
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
    
    static ofVec3f interpolateVec3f(const ofVec3f& startVec, const ofVec3f& endVec, int stepNumber, int lastStepNumber)
    {
        ofVec3f result = ofVec3f(0.0f);
        result.x = (endVec.x - startVec.x) * stepNumber / lastStepNumber + startVec.x;
        result.y = (endVec.y - startVec.y) * stepNumber / lastStepNumber + startVec.y;
        result.z = (endVec.z - startVec.z) * stepNumber / lastStepNumber + startVec.z;
        
        return result;
    }
    
    static float interpolatef(const float start, const float end, int stepNumber, int lastStepNumber)
    {
        return (end - start) * stepNumber / lastStepNumber + start;
    }
}

#endif /* defined(__basicParticleSystem__mathHelper__) */
