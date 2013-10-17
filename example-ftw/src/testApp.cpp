/*
 **********************************************************
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * ----------------------
 * ofxFTGL is by Rick Companje
 *
 * example and static libs by obviousjim
 *
 */

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetFrameRate(30);
	ofSetVerticalSync(true);
	ofSetLogLevel( OF_LOG_VERBOSE ) ; 	
	ofEnableAlphaBlending();

	fontPath = "mplus-1c-regular.ttf" ; 
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);

	string systemTime = "sysemtTime : " + ofToString( ofGetSystemTime() ) ; 
	string elapsedTimef = "elapsedTime : " + ofToString( ofGetElapsedTimef() ) ; 

	ofSetColor( 255 ) ; 
	//We query the manager with a font size and path which returns a pointer to of type ofxFTGLFont
	ofxFTGLFontManager::Instance()->getFont( fontPath , 22 )->drawString( systemTime , 50 , 250 ) ; 

	ofSetColor( 200 , 255 , 200 ) ; 
	//Querying this font should return that it already has been allocated, so we save some GPU memory allocation
	ofxFTGLFontManager::Instance()->getFont( fontPath , 22 )->drawString( elapsedTimef , 50 , 450 ) ; 


	ofSetColor( 200 , 195 , 255 ) ; 
	//Querying this font will *not* have a match the first time around and will create a new ofxFTGL and return it.
	ofxFTGLFontManager::Instance()->getFont( fontPath , 29 )->drawString( elapsedTimef , 50 , 650 ) ; 


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
	
}