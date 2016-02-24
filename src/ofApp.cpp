#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  shader.load("shaders/lightSpeed.vert", "shaders/lightSpeed.frag");
  fbo.allocate(ofGetWidth(), ofGetHeight());
  img.load("space.jpg");
  
  loopStart = 0;
  loopEnd = 1;
  
  loopStartTween.setParameters(0, easeExpo, ofxTween::easeOut, 0, 0, 0, 0);
  loopEndTween.setParameters(0, easeExpo, ofxTween::easeOut, 1, 1, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  fbo.begin();
  ofClear(0, 0, 0, 0);
  img.draw(0, 0);
  fbo.end();
  
  loopStartTween.update();
  loopEndTween.update();
  
  loopStart = loopStartTween.getTarget(0);
  loopEnd = loopEndTween.getTarget(0);
  
  shader.begin();
  shader.setUniformTexture("texture", fbo, 0);
  shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
  shader.setUniform1i("loopStart", loopStart);
  shader.setUniform1i("loopEnd", loopEnd);
  
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  shader.end();
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
//  loopStartTween.setParameters(0, easeExpo, ofxTween::easeIn, 0, 100, 2400, 0);
  loopEndTween.setParameters(0, easeExpo, ofxTween::easeIn, 1, 200, 1400, 0);
  ofAddListener(loopEndTween.end_E, this, &ofApp::loopEndTweenCallback);
}

void ofApp::loopEndTweenCallback(int &e) {
  if(e == 0) {
    loopEndTween.setParameters(1, easeExpo, ofxTween::easeOut, 200, 1800, 300, 0);
  } else if(e == 1) {
    loopEndTween.setParameters(2, easeExpo, ofxTween::easeOut, 1800, 0, 400, 300);
  } else {
    ofRemoveListener(loopEndTween.end_E, this, &ofApp::loopEndTweenCallback);
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
