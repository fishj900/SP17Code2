#include "ofApp.h"

const int width = 800;
const int height = 600;

//--------------------------------------------------------------
void ofApp::setup(){
    
    nana.load("realnana.png");
    cel.load("celery.png");
    eggplant.load("eggplant.png");
    peach.load("peach.png");
    energy.load("monster.png");
    pizza.load("pizza.png");
    nut.load("donutshit.png");
    dog.load("doghot.png");

    
    
    dietdj.load("cooperBlack.ttf",15);
    
    celery.load("sound eat bass.wav");
    banana.load("sound eat clap.wav");
    egg.load("sound eat hi 2.wav");
    peachsound.load("sound eat open.wav");
    monster.load("monstersound.wav");
    pizzasound.load("pizzasound.wav");
    donut.load("donutsound1.wav");
    hotdog.load("hotdogsoundfinal.wav");
    
    counter = 0;
    ofSetCircleResolution(50);
    
    //ofBackground(0,0,0);
    
    bSmooth = false;
    ofSetWindowTitle("Final Project Test");
    
    mainOutputSyphonServer.setName("Screen Output");
    individualTextureSyphonServer.setName("Texture Output");
    
    mClient.setup();
    
    //using Syphon app Simple Server, found at http://syphon.v002.info/
    mClient.set("","Simple Server");
    
    tex.allocate(200, 100, GL_RGBA);
    
    ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
}

//--------------------------------------------------------------
void ofApp::update(){
    counter = counter + 0.033f;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // Clear with alpha, so we can capture via syphon and composite elsewhere should we want.
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    ofSetColor(255);
    ofDrawRectangle(700, 100, 200, 200);
    
    if (pizzasound.isPlaying()){
        ofSetColor(255,236,183);
        ofDrawRectangle(700, 100, 200, 200);
    }
    
    if (monster.isPlaying()){
        ofSetColor(80,80,80);
        ofDrawRectangle(700, 100, 200, 200);
    }
    
    if (hotdog.isPlaying()){
        ofSetColor(188,82,65);
        ofDrawRectangle(700, 100, 200, 200);
    }
    
    if (donut.isPlaying()){
        ofSetColor(240,153,83);
        ofDrawRectangle(700, 100, 200, 200);
    }
    
    ofSetColor(255);
    ofDrawRectangle(100, 400, 200, 200);
    
    ofSetColor(255);
    ofDrawRectangle(400, 400, 200, 200);
    
    if (banana.isPlaying()){
     nana.draw(ofRandom(465,470),ofRandom(405,410),120,120);
        
    }
    
    if (celery.isPlaying()){
        cel.draw(ofRandom (405,410),ofRandom (475,480),120,120);
        
    }
    
    if (egg.isPlaying()){
        eggplant.draw(ofRandom (415,420),ofRandom(405,410));
        eggplant.resize(120,120);
        
    }
    
    if (peachsound.isPlaying()){
        peach.draw(ofRandom (455,460),ofRandom(485,490));
        peach.resize(130,100);
        
    }
   
    
    ofSetColor(255);
    ofDrawRectangle(700, 400, 200, 200);
    
    if (egg.isPlaying()){
        ofSetColor(97,64,81);
        ofDrawRectangle(700, 400, 200, 200);
        
    }
    if (banana.isPlaying()){
        ofSetColor(255,235,53);
        ofDrawRectangle(700, 400, 200, 200);
        
    }
    if (celery.isPlaying()){
        ofSetColor(157,206,92);
        ofDrawRectangle(700, 400, 200, 200);
        
    }
    if (peachsound.isPlaying()){
        ofSetColor(201,52,19);
        ofDrawRectangle(700, 400, 200, 200);
        
    }
    ofSetColor(255);
    dietdj.drawString("Diet Dj", 460,60);
    
    ofSetColor(255);
    dietdj.drawString("by Fisher", 460,650);

    ofSetColor(255);
   ofDrawRectangle(100, 100, 200, 200);
    
    ofSetColor(200,200,0);

    ofSetColor(240,153,83);
    if (donut.isPlaying()){
        dietdj.drawString( "transfat!", ofRandom(117,120), 150);
    }
    ofSetColor(255,236,183);
    if (pizzasound.isPlaying()) {
    dietdj.drawString("saturated fat!", ofRandom(122,125), 200);
    }
    ofSetColor(188,82,65);
    if (hotdog.isPlaying()){
         dietdj.drawString("sodium!",ofRandom(114,117), 235);
    }
    
        ofSetColor(170, 170, 170);
        if (monster.isPlaying()) {
            dietdj.drawString("corn syrup!", ofRandom(147,150), 270);
        }
    {

    }
    
    ofSetColor(255,235,53);
    if (banana.isPlaying()){
         dietdj.drawString("potassium!", ofRandom(137,140), 500);
        
    }
    
    ofSetColor(157,206,92);
    if (celery.isPlaying()){
        dietdj.drawString("water!", ofRandom(177,180), 580);
        
    }
   
    
    ofSetColor(201,52,19);
    if (peachsound.isPlaying()){
        dietdj.drawString("calcium!", ofRandom (117,120),450);
        
    }
    
    
    ofSetColor(97,64,81);
    if (egg.isPlaying()){
        dietdj.drawString("fiber!",ofRandom(117,120),540);
        
    }
    ofSetColor(255);
    ofDrawRectangle(400, 100, 200, 200);
    
    if (monster.isPlaying()){
        
    energy.draw(ofRandom(395,400),ofRandom(115,120),120,120);
        
    }
    
    if (pizzasound.isPlaying()) {
    pizza.draw(ofRandom(445,450), ofRandom(170,175), 120,120);
    }
    
    
    if (hotdog.isPlaying()) {
        dog.draw(ofRandom (425,430),ofRandom(105,110), 130,95);
    }
    
    if (donut.isPlaying()) {
        nut.draw(ofRandom(490,495), ofRandom(130,135), 95,95);
    }


    
    

    
    
    // Syphon Stuff!
    
    mClient.draw(50, 50);
    
    mainOutputSyphonServer.publishScreen();
    
    individualTextureSyphonServer.publishTexture(&tex);
    
    
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    switch (key) {
        
    
case 'w':
    celery.play();
    break;
    
case 's':
    banana.play();
    break;
            
        case 'a':
            egg.play();
            break;
            
        case 'd':
            peachsound.play();
            break;
            
    }
            if (key == OF_KEY_UP){
               monster.play();
                
            }
    if (key == OF_KEY_LEFT){
        pizzasound.play();
        
    }
    if (key == OF_KEY_RIGHT){
        donut.play();
        
    }
    
    if (key == OF_KEY_DOWN){
        hotdog.play();
        
    }
    
    
}




