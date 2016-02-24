#pragma once

#include "ofMain.h"
#include "ofxEulerAngles.h"

class Segment : public ofMesh {
  public:
    Segment();
    ~Segment();
  
    void setup(float len, float side, float point);
    void update();
    void updateRotation();
    void transformQuaternionToRotMat(ofMatrix4x4 & m, ofQuaternion q);
    ofVec3f getPoint();
  
  
    ofVec3f rotation;
    ofVec3f position;
    ofVec3f vLength;
    ofQuaternion quaternion;
    float length;
};