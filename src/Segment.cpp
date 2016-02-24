#include "Segment.h"
#include "ofMain.h"
#include "ofxEulerAngles.h"

Segment::Segment() {
}


Segment::~Segment() {
}

void Segment::setup(float len, float side, float point) {
  setMode(OF_PRIMITIVE_TRIANGLE_FAN);
  
  addVertex(ofPoint(   0,   len,      0));  // 0
  addVertex(ofPoint(-side, point, -side));  // 1
  addVertex(ofPoint( side, point, -side));  // 2
  addVertex(ofPoint( side, point,  side));  // 3
  addVertex(ofPoint(-side, point,  side));  // 4
  addVertex(ofPoint(    0,     0,     0));  // 5
  
  addIndex(0);
  addIndex(2);
  addIndex(1);
  
  addIndex(0);
  addIndex(3);
  addIndex(2);
  
  addIndex(0);
  addIndex(4);
  addIndex(3);
  
  addIndex(0);
  addIndex(1);
  addIndex(4);
  
  addIndex(5);
  addIndex(1);
  addIndex(2);
  
  addIndex(5);
  addIndex(2);
  addIndex(3);
  
  addIndex(5);
  addIndex(3);
  addIndex(4);
  
  addIndex(5);
  addIndex(4);
  addIndex(1);

  length = len;
  vLength.set(0, len, 0);
}

void Segment::update() {
  ofPushMatrix();
  
  ofTranslate(position.x, position.y, position.z);
  
  ofRotateX(rotation.x);
  ofRotateZ(rotation.z);
  ofRotateY(rotation.y);
  
  drawFaces();
  
  ofPopMatrix();
}

ofVec3f Segment::getPoint() {
  ofVec3f v(0, length, 0);
  
  v.rotate(0, rotation.y, 0);
  v.rotate(0, 0, rotation.z);
  v.rotate(rotation.x, 0, 0);
  v += position;
  
  return v;
}

void Segment::updateRotation() {
  ofMatrix4x4 matrix;
  transformQuaternionToRotMat(matrix, quaternion);
  rotation.set(ofxEulerAngles::toEulerXYZ(matrix));
}

void Segment::transformQuaternionToRotMat(ofMatrix4x4 & m, ofQuaternion q) {
  m(0,0) = 1.0 - 2.0f * q.y() * q.y() - 2.0f * q.z() * q.z();
  m(0,1) = 2.0f * q.x() * q.y() + 2.0f * q.w() * q.z();
  m(0,2) = 2.0f * q.x() * q.z() - 2.0f * q.w() * q.y();
  
  m(1,0) = 2.0f * q.x() * q.y() - 2.0f * q.w() * q.z();
  m(1,1) = 1.0f - 2.0f * q.x() * q.x() - 2.0f * q.z() * q.z();
  m(1,2) = 2.0f * q.y() * q.z() + 2.0f * q.w() * q.x();
  
  m(2,0) = 2.0f * q.x() * q.z() + 2.0f * q.w() * q.y();
  m(2,1) = 2.0f * q.y() * q.z() - 2.0f * q.w() * q.x();
  m(2,2) = 1.0f - 2.0f * q.x() * q.x() - 2.0f * q.y() * q.y();
}