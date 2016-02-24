#include "ofApp.h"
#include "Segment.h"
#include "SegmentsContainer.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofEnableBlendMode(OF_BLENDMODE_SCREEN);
  ofBackground(0, 0, 0);
  
  
  
  for(int i = 0; i < NUM_SEGMENTS_CONTAINERS; i++) {
    SegmentsContainer segmentsContainer;
    segmentsContainer.setup();
    segmentsContainers.push_back(segmentsContainer);
  }
  
  mouseX = 0;
  mouseY = 0;
  
  cam.setDistance(1000);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();
  
  for(int i = 0; i < NUM_SEGMENTS_CONTAINERS; i++) {
    segmentsContainers[i].update(ofGetFrameNum() * 0.001);
  }
  
  cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
  
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
  mouseX = x - ofGetWidth() / 2;
  mouseY = -y + ofGetHeight() / 2;
  
  for(int i = 0; i < NUM_SEGMENTS_CONTAINERS; i++) {
    segmentsContainers[i].radiusOffset = x / 2;
  }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
