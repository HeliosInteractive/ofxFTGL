#pragma once

#include "ofMain.h"
#include "ofxFTGLFont.h"

class ofxFTGLFontManager
{
public : 
	
	ofxFTGLFont * getFont ( string fontPath , int  fontSize ) ;

	static ofxFTGLFontManager* Instance()
	{
		static ofxFTGLFontManager inst ;
		return &inst ;
	}

private : 
	vector < ofxFTGLFont * > fonts ;
	ofxFTGLFontManager() ;
	~ofxFTGLFontManager() ;
};