/*
 * inputMgr.cpp
 *
 *  Created on: Mar 17, 2017
 *      Author: jwoo
 */


#include <inputMgr.h>
#include <engine.h>
using namespace std;


InputMgr::InputMgr() : Mgr(engine){

}

InputMgr::InputMgr(Engine* engine) : Mgr(engine){

}

void InputMgr::tick(float dt){

	//cout << endl << "1" << endl << endl << endl;
	/*if(mKeyboard->isKeyDown(OIS::KC_ESCAPE)){
		cout << endl << "3" << endl << endl << endl;
	    engine->stop();
	    cout << endl << "4" << endl << endl << endl;
		}*/

	//cout << endl << "2" << endl << endl << endl;
}

void InputMgr::init(){

	// OIS
	  Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");

	  OIS::ParamList pl;


		// insert the following lines right before calling mInputSystem = OIS::InputManager::createInputSystem( paramList );
		    #if defined OIS_WIN32_PLATFORM
		    pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND" )));
		    pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));
		    pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND")));
		    pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_NONEXCLUSIVE")));
		    #elif defined OIS_LINUX_PLATFORM
		    pl.insert(std::make_pair(std::string("x11_mouse_grab"), std::string("false")));
		    pl.insert(std::make_pair(std::string("x11_mouse_hide"), std::string("false")));
		    pl.insert(std::make_pair(std::string("x11_keyboard_grab"), std::string("false")));
		    pl.insert(std::make_pair(std::string("XAutoRepeatOn"), std::string("true")));
		    #endif

	  size_t windowHandle = 0;
	  std::ostringstream windowHandleStr;

	  engine->gfxMgr->mWindow->getCustomAttribute("WINDOW", &windowHandle);
	  windowHandleStr << windowHandle;
	  pl.insert(std::make_pair(std::string("WINDOW"), windowHandleStr.str()));

	  mInputMgr = OIS::InputManager::createInputSystem(pl);

	  mKeyboard = static_cast<OIS::Keyboard*>(
	    mInputMgr->createInputObject(OIS::OISKeyboard, true));
	  mMouse = static_cast<OIS::Mouse*>(
	    mInputMgr->createInputObject(OIS::OISMouse, true));

	  if(mKeyboard->isKeyDown(OIS::KC_ESCAPE)){
	      engine->stop();
	  	}

	  /*windowResized(engine->gfxMgr->mWindow);
	  	  Ogre::WindowEventUtilities::addWindowEventListener(engine->gfxMgr->mWindow, this);

	  	  mKeyboard->setEventCallback(this);

	  engine->gfxMgr->mRoot->addFrameListener(this);*/





}


void InputMgr::loadLevel(){

}

void InputMgr::stop(){

}




bool InputMgr::keyPressed(const OIS::KeyEvent& ke){

	if(mKeyboard->isKeyDown(OIS::KC_ESCAPE)){
    engine->stop();
	}

	return true;
}




bool InputMgr::keyReleased(){

}



















