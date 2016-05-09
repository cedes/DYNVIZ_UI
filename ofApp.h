#pragma once

#include "ofMain.h"
#include "post.hpp"
#include <string>

#define NPOSTS 5

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
    
    float eventManager(float);
	
    Post myPost[NPOSTS];
    int currentpost;
    int moving;
    float time;
    float wait;
    
    vector<string> eventlist;
    vector<bool> typelist;
    vector<int> option_1_list;
    vector<int> option_2_list;
    vector<int> option_3_list;
    
    ofFile myfile;
};
