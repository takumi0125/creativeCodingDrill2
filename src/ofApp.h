#pragma once

#include "ofMain.h"
#include "SegmentsContainer.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
  
    static const int NUM_SEGMENTS_CONTAINERS = 100;
  
    ofEasyCam cam;
    vector<SegmentsContainer> segmentsContainers;
    float mouseX;
    float mouseY;
};