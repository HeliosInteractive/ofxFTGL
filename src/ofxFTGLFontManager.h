#pragma once

#include "ofMain.h"
#include "ofxFTGLFont.h"
#include <unordered_map>

class ofxFTGLFontManager
{
public : 
	
	static ofxFTGLFont * getFont ( string fontPath , int  fontSize ) ;

	static ofxFTGLFontManager Instance()
	{
		initInstance();
        return *instance;
	}
	
	~ofxFTGLFontManager();

private : 
	ofxFTGLFontManager();
	static void initInstance();
	static std::auto_ptr<ofxFTGLFontManager> instance;
	unordered_map<string,ofxFTGLFont *> fontTable;
    ofxFTGLFontManager(ofxFTGLFontManager const&);          
    void operator=(ofxFTGLFontManager const&);
	ofxFTGLFont * getFontInternal(string fontPath , int  fontSize);
};

