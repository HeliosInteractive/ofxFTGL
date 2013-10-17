#pragma once

#include "ofMain.h"
#include "ofxFTGLFont.h"

class ofxFTGLFontManager
{
public : 
	ofxFTGLFontManager() ;
	~ofxFTGLFontManager() ;

	ofxFTGLFont * getFont ( string fontPath , int  fontSize ) ;

	static ofxFTGLFontManager* Instance()
	{
		static ofxFTGLFontManager inst ;
		return &inst ;
	}
private : 
	vector < ofxFTGLFont * > fonts ; 
};