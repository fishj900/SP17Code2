#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth = ofGetWindowWidth();
    camHeight = ofGetWindowHeight();
    
   
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    for(int i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
        
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
         
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(100);
    vidGrabber.initGrabber(camWidth, camHeight);
    
    videoInverted.allocate(camWidth, camHeight, OF_PIXELS_RGB);
    videoTexture.allocate(videoInverted);
    ofSetVerticalSync(true);
}


//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(249, 249, 249);
    vidGrabber.update();
    
    if(vidGrabber.isFrameNew()){
        ofPixels & pixels = vidGrabber.getPixels();
        for(int i = 0; i < pixels.size(); i++){
            
            videoInverted[i] = 150 - pixels[i];
        }
 
        videoTexture.loadData(videoInverted);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xffffff);
    vidGrabber.draw(ofGetWindowHeight(),ofGetWindowWidth());
    videoTexture.draw(ofGetWindowHeight()/8,ofGetWindowWidth()/8);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
 
   
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
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
