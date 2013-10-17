#include "ofxFTGLFontManager.h"

ofxFTGLFontManager::ofxFTGLFontManager( )
{

} 

ofxFTGLFontManager::~ofxFTGLFontManager() 
{

} 

ofxFTGLFont * ofxFTGLFontManager::getFont ( string fontPath , int  fontSize )
{
	string localPath = ofToDataPath( fontPath , false ) ; 
	int lastSlashIndex = fontPath.find_last_of( "/" ) ; 
	if ( lastSlashIndex < 0 )
		lastSlashIndex = fontPath.find_last_of( "\\" ) ; 
	else if ( lastSlashIndex < 0 )
		localPath = fontPath.substr( lastSlashIndex  + 1 ) ; 
	
	if ( fonts.size() > 0 ) 
	{
		for ( int i = 0 ; i < fonts.size() ; i++  ) 
		{
			//cout << "[" << i << " ] " << fonts[i]->fontSize << " vs. " << fontSize << endl ; 
			if ((fonts[i]->fontSize == fontSize) &&  ((fonts[i])->fileName.compare( localPath ) == 0 )  ) 
			{
				ofLogWarning( " MATCH FOUND! " ) << fontPath << " and " << localPath << endl ; 
				return fonts[i] ; 
			}
		}
	}

	ofLogWarning( " NO font Match. CREATING a new one " ) << fontPath << " and " << fontSize << endl ; 
	int index = fonts.size(); 
	fonts.push_back( new ofxFTGLFont() ) ; 
	fonts[ index ]->loadFont( localPath , fontSize, true , false , false , 0.3 , 72 ) ; 

	return fonts[ index ] ; 

} 