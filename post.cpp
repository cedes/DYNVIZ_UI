//
//  post.cpp
//  TIFI_GUI
//
//  Created by Mercedes Said on 05/05/2016.
//
//

#include "post.hpp"
#include "ofApp.h"
#include <string>

Post::Post(){
    
}

int Post::setup(string str, bool settype){
    
    btnarea=150;
    
    scroll=0;
    
    type = settype;
    
    x = ofGetWidth()/3;
    y = ofRandom(200, 500);
    
    xpos = ofGetWidth()/3;
    //ypos = ofGetHeight()-y-btnarea;
    ypos = ofGetHeight()-btnarea;
    
    b1x = 600;
    b2x = 700;
    b3x = 800;
    bw = 75;
    bh = 50;
    by = 800+y;
    
    text = str;
    
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
    font.load("hockey.ttf", 30);
    return y;
}


void Post::update(){
    
    if (scrolling > 0){
        scroll+=50;
        scrolling--;
    }

}

void Post::draw(){
    ofSetColor(color);
    ofDrawRectangle(xpos, ypos - scroll, x, y);
    ofSetColor(0);
    font.drawString(text, xpos+20, ypos+50-scroll);
    if (type){
        ofSetColor(100);
        ofDrawRectangle(b1x, by - scroll, bw, bh);
        ofDrawRectangle(b2x, by - scroll, bw, bh);
        ofDrawRectangle(b3x, by - scroll, bw, bh);
    }
}

void Post::newPost(int movement){
    
    scrolling+=movement/50;
    scroll+=movement%50;
}

int Post::mousePressed(int xm, int ym, int button) {
    if (type && (xm > b1x) && (xm < b1x + bw) && (ym > by - scroll) && (ym < by + bh - scroll)){
        type = false;
        return 1;
    }
    else if (type && (xm > b2x) && (xm < b2x + bw) && (ym > by - scroll) && (ym < by + bh - scroll)){
        type = false;
        return 2;
    }
    else if (type && (xm > b3x) && (xm < b3x + bw) && (ym > by - scroll) && (ym < by + bh - scroll)){
        type = false;
        return 3;
    }
    else {
        return 0;
    }
}
