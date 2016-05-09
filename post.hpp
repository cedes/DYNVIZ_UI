//
//  post.hpp
//  TIFI_GUI
//
//  Created by Mercedes Said on 05/05/2016.
//
//

#ifndef post_hpp
#define post_hpp

#include <stdio.h>
#include "ofMain.h"
#include <string>


class Post {
    
public:

    //methods
    int setup(string, bool);
    void update();
    void draw();
    void newPost(int);
    int mousePressed(int, int, int);
    
    //public variables
    bool type;
    float xpos;
    float ypos;
    float x;
    float y;
    float btnarea;
    float scroll;
    float scrolling;
    ofColor color;
    
    int b1x, b2x, b3x;
    int bw, bh, by;
    
    ofTrueTypeFont font;
    string text;
    //constructor
    
    Post();
    
    //private variables
    
private:
    
};

#endif /* post_hpp */
