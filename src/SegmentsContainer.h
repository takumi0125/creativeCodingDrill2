#pragma once

#include "ofMain.h"
#include "Segment.h"

class SegmentsContainer {
  
public:
  SegmentsContainer();
  ~SegmentsContainer();
  void drag(Segment *segment, float x, float y, float z);
  void update(float time);
  void setup();
  void setColor(int i, float time);
  
  static const int NUM_SEGMENTS = 16;
  
  vector<Segment> segments;
  ofColor color;
  float radius;
  float rotationOffset;
  float direction1;
  float direction2;
  float speed1;
  float speed2;
  float radiusOffset;
};