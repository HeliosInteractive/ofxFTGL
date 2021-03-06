#include "ofxFTGLFontManager.h"

std::auto_ptr<ofxFTGLFontManager> ofxFTGLFontManager::instance;

ofxFTGLFontManager::ofxFTGLFontManager(){} 
ofxFTGLFontManager::~ofxFTGLFontManager(){ofLogNotice() << "The instance of FTGLFontManager was destroyed";} 

void ofxFTGLFontManager::initInstance ()
{
	if (!instance.get())
	{
		ofLogNotice("FontManager") << "The instance of FTGLFontManager was created";
		instance.reset( new ofxFTGLFontManager());
	}
}


ofxFTGLFont * ofxFTGLFontManager::getFont ( string fontPath , int  fontSize )
{
	return Instance()->getFontInternal(fontPath,fontSize);
}

ofxFTGLFont * ofxFTGLFontManager::getFontInternal ( string fontPath , int  fontSize )
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
	
	string fontkey = localPath+ofToString(fontSize);

	if (fontTable.find(fontkey) == fontTable.end())
	{
		ofxFTGLFont* newFont = new ofxFTGLFont();
		newFont->loadFont( localPath , fontSize, true , false , false , 0.3 , 72 ); 
		fontTable[fontkey] = newFont;
		ofLogNotice("Font Cached") << fontPath<< " @ "<<fontSize<<"pt : "<<fontTable.size()<<" fonts cached total";
	}

	return fontTable[fontkey];
} 

void ofxFTGLFontManager::exportToXML( string xmlName  )
{

	unordered_map<string,ofxFTGLFont *>::iterator font ;

	ofxXmlSettings xml ; 
	font = fontTable.begin() ; 
	while ( font != fontTable.end() ) 
	{
		int tagIndex = xml.addTag( "font" ) ;
		xml.pushTag( "font" , tagIndex ) ; 
	//	xml.setValue( "fontPath" , (*font).first. ) ; 
		xml.setValue ( "fontSize" , (*font).second->fontSize ) ; 
		xml.setValue ( "fileName" , (*font).second->fileName ) ; 


		//cout << "fontPath : " <<  (*font).first  << endl ; 
		//cout << "fontSize : " << (*font).second->fileName << endl ; 
		xml.popTag() ; 
		++font ; 
	}
	
	xml.saveFile( ofToDataPath( xmlName ) ) ; 
} 