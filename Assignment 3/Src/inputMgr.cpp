/*
 * inputMgr.cpp
 *
 *  Created on: Mar 17, 2017
 *      Author: jwoo
 */


#include <inputMgr.h>



InputMgr::InputMgr() : Mgr(engine){

}

InputMgr::InputMgr(Engine* engine) : Mgr(engine){

}

void InputMgr::tick(float dt){

}

void InputMgr::init(){

	// OIS
	  /*Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");

	  OIS::ParamList pl;
	  size_t windowHandle = 0;
	  std::ostringstream windowHandleStr;

	  mWindow->getCustomAttribute("WINDOW", &windowHandle);
	  windowHandleStr << windowHandle;
	  pl.insert(std::make_pair(std::string("WINDOW"), windowHandleStr.str()));

	  mInputMgr = OIS::InputManager::createInputSystem(pl);

	  mKeyboard = static_cast<OIS::Keyboard*>(
	    mInputMgr->createInputObject(OIS::OISKeyboard, false));
	  mMouse = static_cast<OIS::Mouse*>(
	    mInputMgr->createInputObject(OIS::OISMouse, false));



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
	    #endif*/

}


void InputMgr::loadLevel(){

}

void InputMgr::stop(){

}




bool InputMgr::keyPressed(){

	/*if(OIS::KC_ESCAPE){
    mShutDown = true;
	}

	return true;*/
}




bool InputMgr::keyReleased(){

}




















