#include "ofxFTGLFontManager.h"

ofxFTGLFontManager::ofxFTGLFontManager( )
{

} 

ofxFTGLFontManager::~ofxFTGLFontManager() 
{

} 

ofxFTGLFont * ofxFTGLFontManager::getFont ( string fontPath , int  fontSize )
{
	//Let's make sure our font path is relative to the data folder
	string localPath = ofToDataPath( fontPath , false ) ; 

	//See if the path is formatted to use backslashse
	int lastSlashIndex = fontPath.find_last_of( "/" );

	//No backslahses ? It must be using forward slashes
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
				//This get spammy
				//ofLogWarning( " MATCH FOUND! " ) << fontPath << " and " << localPath << endl ; 
				return fonts[i] ; 
			}
		}
	}

	ofLogError( " NO font Match " ) << " CREATING " << fontPath << " , " << fontSize << endl ; 
	
	//Create our new font, populate it with data then return it.
	fonts.push_back( new ofxFTGLFont() ) ; 
	fonts[ fonts.size() -1  ]->loadFont( localPath , fontSize, true , false , false , 0.3 , 72 ) ; 
	return fonts[ fonts.size() -1 ] ; 

} 