#include "ofApp.h"
#include <string>

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(238, 239, 242);
    currentpost = 0;
    //myPost[0].setup("Oh herro (0)", false);
    time = -3;
    wait = 3;
    
    eventlist.push_back("EV1");
    eventlist.push_back("EV2");
    eventlist.push_back("Q3");
    eventlist.push_back("EV4");
    eventlist.push_back("Thanks");
    
    typelist.push_back(false);
    typelist.push_back(false);
    typelist.push_back(true);
    typelist.push_back(false);
    typelist.push_back(false);
    
    option_1_list.push_back(0);
    option_1_list.push_back(0);
    option_1_list.push_back(0);
    option_1_list.push_back(0);
    option_1_list.push_back(0);
    
    option_2_list.push_back(0);
    option_2_list.push_back(0);
    option_2_list.push_back(0);
    option_2_list.push_back(0);
    option_2_list.push_back(0);
    
    option_3_list.push_back(0);
    option_3_list.push_back(0);
    option_3_list.push_back(0);
    option_3_list.push_back(0);
    option_3_list.push_back(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i=0; i<NPOSTS; i++){
        myPost[i].update();
    }
    
    time = eventManager(time);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i=0; i<currentpost; i++){
        myPost[i].draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for(int i=0; i<NPOSTS; i++){
        myPost[i].mousePressed(x, y, button);
    }

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

//--------------------------------------------------------------
float ofApp::eventManager(float time){
    //if (time + wait < ofGetElapsedTimef()){
    if (time + wait < ofGetElapsedTimef() && !(myPost[currentpost-1].type)){
        if (currentpost < NPOSTS){
            moving = 20 + myPost[currentpost].setup(eventlist[currentpost], typelist[currentpost]);
            //moving = 20 + ev.manager(myPost[currentpost], currentpost);
            currentpost++;
        }
        else {
            moving = 0;
        }
        for(int i=0; i<currentpost; i++){
            myPost[i].newPost(moving);
        }
        return ofGetElapsedTimef();
    }
    else {
        return time;
    }
}
