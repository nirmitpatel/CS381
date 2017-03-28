/*
 * inputMgr.h
 *
 *  Created on: Mar 17, 2017
 *      Author: jwoo
 */

#ifndef INC_INPUTMGR_H_
#define INC_INPUTMGR_H_


#include <mgr.h>
#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include <OgreEntity.h>
#include <OgreCamera.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>
#include <OgreException.h>

#include <OgreWindowEventUtilities.h>
#include <BaseApplication.h>


class InputMgr : Mgr{
public:
	InputMgr();
	InputMgr(Engine* engine);

	virtual void tick(float dt);
	virtual void init();
	virtual void loadLevel();
	virtual void stop();

	virtual bool keyPressed();
	virtual bool keyReleased();

	OIS::InputManager* mInputMgr;
	OIS::Keyboard* mKeyboard;
	OIS::Mouse* mMouse;
};






#endif /* INC_INPUTMGR_H_ */
