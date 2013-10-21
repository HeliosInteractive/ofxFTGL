#include "ofxFTGLFont.h"

ofxFTGLFont::ofxFTGLFont(){
    loaded = false;
    
}

ofxFTGLFont::~ofxFTGLFont(){
	if(font != NULL && loaded == true ){
       // delete (*font);
		
    }
	 font.reset() ; 
}

bool ofxFTGLFont::loadFont(string _filename, float fontsize, bool _bAntiAliased, bool _bFullCharacterSet, bool makeContours, float simplifyAmnt, int dpi){

	fileName = _filename ; 
	_bFullCharacterSet = false ; 
	loaded = false ; 
	if ( fontsize < 1 ) 
	{
		ofLogError( "ofxFTGLFont::loadFont : font size of " + ofToString( fontsize ) +  " is not valid. ABORTING" ) ;
		return false ; 
	}
	if ( !ofFile::doesFileExist( ofToDataPath( fileName ) ) )
	{
		ofLogError ( "ofxFTGLFont::loadFont : font @ " + fileName + " does not exist! ABORTING." ) ; 
		return false ; 
	}
	fontSize = fontsize ; 

	fontsize *= 2;
    font = ofPtr< FTTextureFont > ( new FTTextureFont(ofToDataPath(fileName).c_str()) ) ;
//	lineHeight = fontsize * 1.43f;
  	lineHeight = fontsize;
  
    font->Outset(0.0f, fontsize);

	font->CharMap(FT_ENCODING_UNICODE);

    if(font->Error()){
        ofLogError("ofxFTGLFont") << "Error loading font " << fileName ;
       font.reset() ; 
		return false;
    }    
    
    if(!font->FaceSize(fontsize)){
        ofLogError("ofxFTGLFont") << "Failed to set font size";
        font.reset() ; 
		return false;
    }
    
	
    loaded = true;
    return true;
}

float ofxFTGLFont::stringWidth(string c){
    ofRectangle rect = getStringBoundingBox(c, 0,0);
    return rect.width;
}

float ofxFTGLFont::stringHeight(string c) {
    ofRectangle rect = getStringBoundingBox(c, 0,0);
    return rect.height;
}

bool ofxFTGLFont::isLoaded(){
    return loaded;
}

void ofxFTGLFont::setSize(int size){
    if(loaded){
	    font->FaceSize(size);
    }
}

float ofxFTGLFont::getLineHeight(){
	return lineHeight;
}

void ofxFTGLFont::setLineHeight(float newHeight){
    lineHeight = newHeight;
}

ofRectangle ofxFTGLFont::getStringBoundingBox(string s, float x, float y){
    if(loaded == true  && s.size() > 0 && font != NULL ){
		//cout << "what is s : " << s << " x : " << x << " y : " << y << endl ; 
		FTBBox bbox = font->BBox(s.c_str());
	    return ofRectangle(x + bbox.Lower().Xf(), y + bbox.Lower().Yf(), bbox.Upper().Xf(), bbox.Upper().Yf());
    }
	return ofRectangle();
}

ofRectangle ofxFTGLFont::getStringBoundingBox(wstring s, float x, float y){
    if(loaded){
    	FTBBox bbox = font->BBox((wchar_t*)s.c_str());
	    return ofRectangle(x + bbox.Lower().Xf(), y + bbox.Lower().Yf(), bbox.Upper().Xf(), bbox.Upper().Yf());
    }
	return ofRectangle();
}

void ofxFTGLFont::drawString(string s, float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(1,-1,1);

	if ( font != NULL ) 
		font->Render(s.c_str());
    glPopMatrix();
}

void ofxFTGLFont::drawString(wstring s, float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(1,-1,1);
    font->Render((wchar_t*)s.c_str());
    glPopMatrix();
}
