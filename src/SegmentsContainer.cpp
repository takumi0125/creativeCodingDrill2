#include "ofMain.h"
#include "SegmentsContainer.h"
#include "Segment.h"

SegmentsContainer::SegmentsContainer() {
  
  for(int i = 0; i < NUM_SEGMENTS; i++) {
    Segment segment;
    segment.setup(60, 20, 10);
    segments.push_back(segment);
  }
}

SegmentsContainer::~SegmentsContainer() {
}

void SegmentsContainer::setup() {
  radius = ofRandom(450, 550);
  
  int r = ofRandom(0, 2);
  if(r == 1) {
    direction1 = 1;
  } else {
    direction1 = -1;
  }
  
  r = ofRandom(0, 1);
  if(r == 1) {
    direction2 = 1;
  } else {
    direction2 = -1;
  }
  
  speed1 = ofRandom(0.25, 0.3) / 3;
  speed2 = ofRandom(0.03, 0.04) / 3;
  
  rotationOffset = ofRandom(360) / 180 * PI;
  
  color.setHsb(ofRandom(255), ofRandom(128, 255), ofRandom(128, 200));
}

void SegmentsContainer::drag(Segment *segment, float x, float y, float z) {
  ofVec3f to(x, y, z);
  
  ofVec3f v1 = (to - segment->position).getNormalized();
  ofVec3f v2 = (segment->getPoint() - segment->position).getNormalized();
  
  if(isnan(v2.angle(v1))) {
    return;
  }
  
  ofQuaternion quat;
  quat.makeRotate(v2, v1);
  segment->quaternion *= quat;
  segment->updateRotation();
  
  ofVec3f size = segment->getPoint() - segment->position;
  segment->position.set(to - size);
}

void SegmentsContainer::update(float time) {
  ofPushMatrix();
  
  ofRotateZ(360 * cos(ofRadToDeg(time) * speed2 * 2 + rotationOffset));
  ofRotateX(360 * cos(ofRadToDeg(time) * speed2 * 2 + rotationOffset));
  
  float x = (radius + radiusOffset) * cos((ofRadToDeg(time) * speed1 * 5 + rotationOffset) * direction1);
  float y = 0;
  float z = (radius + radiusOffset) * sin((ofRadToDeg(time) * speed1 * 5 + rotationOffset) * direction1);
  
  setColor(0, time);
  drag(&segments[0], x, y, z);
  segments[0].update();
  
  for(int i = 1; i < NUM_SEGMENTS; i++) {
    setColor(i, time);
    Segment beforeSegment = segments[i - 1];
    drag(&segments[i], beforeSegment.position.x, beforeSegment.position.y, beforeSegment.position.z);
    segments[i].update();
  }
  
  ofPopMatrix();
}

void SegmentsContainer::setColor(int i, float time) {
  color.setHsb(
   128 + 127 * sin((ofRadToDeg(time) * speed1 * 0.1 + rotationOffset) * direction1),
   128 + 127 * sin((ofRadToDeg(time) * speed1 * 10 + rotationOffset + ofRadToDeg(i / 4)) * direction1),
   30 + 30 * cos((ofRadToDeg(time) * speed1 + rotationOffset) * direction1)
  );
  ofSetColor(color);
}