#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    mySoundPlayer.load("stuck like glue.wav");
    mySoundPlayer.setMultiPlay(true);
    
    mySoundStream.setup(this, 0, 2, 44100, 256, 4);
    
    bufferSize = 256;
    left.assign(256, 0);
    right.assign(256, 0);
    volHistory.assign(400, 0);
    
    cam.setDistance(0);
    cam.enableMouseInp;
    
   
}

//--------------------------------------------------------------
void ofApp::update(){
    
    cout << vol << endl;

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofDrawBox(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 100, 100, 200, 200);
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
    mySoundPlayer.setSpeed(ofMap(x,0,ofGetWindowHeight(),0,4));
    mySoundPlayer.play();
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
//_______________________________________________

void ofApp::audioIn(float * input, int buffersize, int nChannels){
    
    float currentVol = 0;
    
    for (int i = 0; i < 256; i++);{
        left[i] = input[i*2]*0.5
        right[i] = input[i*2+1]*0.5;
        
        numCounted += 2;
        
        currentVol += left[i] * left[i];
        currentVol += right[i] * right[i];
        
    }
    }
    
}
