/*
 * GfxMgr.h
 *
 *  Created on: Mar 17, 2017
 *      Author: jwoo
 */

#ifndef INC_GFXMGR_H_
#define INC_GFXMGR_H_

#include <mgr.h>
#include <OgreRoot.h>
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
#include <OgreMeshManager.h>
#include <OgreWindowEventUtilities.h>

class Engine;
class GfxMgr : public Mgr, public Ogre::WindowEventListener, public Ogre::FrameListener{
public:

	GfxMgr(Engine* engine);
	~GfxMgr();

	virtual void tick(float dt);
	virtual void init();
	virtual void loadLevel();
	virtual void stop();

	Ogre::Root* mRoot;
	Ogre::String mResourcesCfg;
	Ogre::String mPluginsCfg;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager* mSceneMgr;
	Ogre::Camera* mCamera;
	Ogre::SceneManager* ogreSceneManager;
};






#endif /* INC_GFXMGR_H_ */
