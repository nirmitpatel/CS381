/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
Name: Nirmit Patel
Class: CS 381
Date: February 22, 2017
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/
Tutorial Framework (for Ogre 1.9)
http://www.ogre3d.org/wiki/
-----------------------------------------------------------------------------
*/

#include "TutorialApplication.h"

//---------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void): mCamNode(0), mDirection(Ogre::Vector3::ZERO), mMove(250), velocity(0)
{
	vector = Ogre::Vector3::ZERO;
}
//---------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//---------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
    // local variables
	int surfaceHeight = -10;

	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

	// cube 1
	Ogre::Entity* cubeEntity = mSceneMgr->createEntity("cube.mesh");
	cubeEntity->setCastShadows(false);

	Ogre::SceneNode* cubeNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("CubeNode");
	cubeNode->setPosition(0, 0, 0);
	cubeNode->attachObject(cubeEntity);

	// cube 2
	Ogre::Entity* cubeEntity2 = mSceneMgr->createEntity("cube.mesh");
	cubeEntity->setCastShadows(false);

	Ogre::SceneNode* cubeNode2 = mSceneMgr->getRootSceneNode()->createChildSceneNode("CubeNode2");
	cubeNode2->setPosition(250, 0, 0);
	cubeNode2->attachObject(cubeEntity2);


	// create plane
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

	Ogre::MeshManager::getSingleton().createPlane(
	  "ground",
	  Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
	  plane,
	  10000, 10000, 20, 20,
	  true,
	  1, 5, 5,
	  Ogre::Vector3::UNIT_Z);

	Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");

	Ogre::Light* spotLight = mSceneMgr->createLight("SpotLight");

	spotLight->setDiffuseColour(0, 0, 1.0);
	spotLight->setSpecularColour(0, 0, 1.0);

	spotLight->setType(Ogre::Light::LT_SPOTLIGHT);

	spotLight->setDirection(-1, -1, 0);
	spotLight->setPosition(Ogre::Vector3(200, 200, 0));

	Ogre::SceneNode* groundNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	groundNode->setPosition(0, surfaceHeight, 0);
	groundNode->attachObject(groundEntity);

	groundEntity->setCastShadows(false);

	// give rockwall texture to ground
	groundEntity->setMaterialName("Examples/Rockwall");
	// give borg texture to cube 1
	cubeEntity->setMaterialName("Borg/borg");
	// give wood texture to cube 2
	cubeEntity2->setMaterialName("Borg/wood");

	cubeNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(
	    "CamNode", Ogre::Vector3(0, 300, 1000));

	mCamNode = cubeNode;
	cubeNode->attachObject(mCamera);
}


bool TutorialApplication::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
  bool ret = BaseApplication::frameRenderingQueued(fe);

  if(!processUnbufferedInput(fe))
    return false;

  mCamNode->translate(mDirection * fe.timeSinceLastFrame, Ogre::Node::TS_LOCAL);

  return ret;
}

bool TutorialApplication::processUnbufferedInput(const Ogre::FrameEvent& fe)
{
	static bool keyDownLastFrame8, keyDownLastFrameSpace, keyDownLastFrame2, keyDownLastFrame4,
				keyDownLastFrame6, keyDownLastFrame3, keyDownLastFrameTab, keyDownLastFrame9 = false;
	bool keyPress8, keyPressSpace, keyPress2, keyPress4, keyPress6, keyPress3, keyPress9, keyPressTab;

	// if num key 8 pressed, go forward in negative z direction
	keyPress8 = mKeyboard->isKeyDown(OIS::KC_NUMPAD8);
	if (keyPress8 && !keyDownLastFrame8)
		{
		vector = updateVelocity();
		}
	keyDownLastFrame8 = keyPress8;

	// if the keypress is a spacebar, then stop the object
	keyPressSpace = mKeyboard->isKeyDown(OIS::KC_SPACE);
	if (keyPressSpace && !keyDownLastFrameSpace)
		{
		vector = Ogre::Vector3::ZERO;
		}
	keyDownLastFrameSpace = keyPressSpace;

	// if keypress is num key 2, go in positive z direction
	keyPress2 = mKeyboard->isKeyDown(OIS::KC_NUMPAD2);
	if (keyPress2 && !keyDownLastFrame2)
		{
		vector = updateVelocity();
		}
	keyDownLastFrame2 = keyPress2;

	// if key pressed is num key 4, move in negative x direction
	keyPress4 = mKeyboard->isKeyDown(OIS::KC_NUMPAD4);
	if (keyPress4 && !keyDownLastFrame4)
		{
		vector = updateVelocity();
		}
	keyDownLastFrame4 = keyPress4;

	// if key pressed is num key 6, move in positive x direction
	keyPress6 = mKeyboard->isKeyDown(OIS::KC_NUMPAD6);
	if (keyPress6 && !keyDownLastFrame6)
		{
		vector = updateVelocity();
		}
	keyDownLastFrame6 = keyPress6;

	// if key pressed is num key 3, move in negative y direction
	keyPress3 = mKeyboard->isKeyDown(OIS::KC_NUMPAD3);
	//keyPress
	if (keyPress3 && !keyDownLastFrame3)
		{
		vector = updateVelocity();
		}
	keyDownLastFrame3 = keyPress3;

	// if key pressed is num key 9, move in positive y direction
	keyPress9 = mKeyboard->isKeyDown(OIS::KC_NUMPAD9);
	if (keyPress9 && !keyDownLastFrame9)
		{
		vector = updateVelocity();
		}
	keyDownLastFrame9 = keyPress9;

	// if tab key is pressed, only move the second cube
	keyPressTab = mKeyboard->isKeyDown(OIS::KC_TAB);
	if (keyPressTab && !keyDownLastFrameTab) {
		// translate the cube according to the time frame
		mSceneMgr->getSceneNode("CubeNode2")->translate(
			vector * fe.timeSinceLastFrame,
			Ogre::Node::TS_LOCAL);
	}
	// else only move the first cube
	else {
		// translate the cube according to the time frame
		mSceneMgr->getSceneNode("CubeNode")->translate(
			vector * fe.timeSinceLastFrame,
			Ogre::Node::TS_LOCAL);
	}

  // return true if the operation is successful
  return true;
}

Ogre::Vector3 TutorialApplication::updateVelocity()
{
	// set move to 50
	static Ogre::Real move = 50;

	// check for num key 8 and move it in negative z direction
	if (mKeyboard->isKeyDown(OIS::KC_NUMPAD8))
		{
			vector.z -= move;
		}

	// check for num key 2 and move it in positive z direction
	if (mKeyboard->isKeyDown(OIS::KC_NUMPAD2))
		{
			vector.z += move;
		}

	// check for num key 6 and move it in positive x direction
	if (mKeyboard->isKeyDown(OIS::KC_NUMPAD6))
		{
			vector.x += move;
		}

	// check for num key 4 and move it in negative x direction
	if (mKeyboard->isKeyDown(OIS::KC_NUMPAD4))
		{
			vector.x -= move;
		}

	// check for num key 9 and move it in positive y direction
	if (mKeyboard->isKeyDown(OIS::KC_NUMPAD9))
		{
			vector.y += move;
		}

	// check for num key 3 and move it in negative y direction
	if (mKeyboard->isKeyDown(OIS::KC_NUMPAD3))
		{
			vector.y -= move;
		}

	// return the resulting vector
	return vector;
}

Ogre::Vector3 TutorialApplication::updatePosition()
{
	return vector = updateVelocity();
}

bool TutorialApplication::keyPressed(const OIS::KeyEvent& ke)
{
  switch (ke.key)
  {
  // if pressed ESC, exit from the program
  case OIS::KC_ESCAPE:
    mShutDown = true;
    break;

  // if w pressed, move camera in negative z direction
  case OIS::KC_W:
    mDirection.z = -mMove;
    break;

  // if s pressed, move camera in positive z direction
  case OIS::KC_S:
    mDirection.z = mMove;
    break;

  // if a pressed, move camera in negative x direction
  case OIS::KC_A:
    mDirection.x = -mMove;
    break;

  // if d pressed, move camera in positive y direction
  case OIS::KC_D:
    mDirection.x = mMove;
    break;

  // if f pressed, move camera in negative y direction
  case OIS::KC_F:
    mDirection.y = -mMove;
    break;

  // if w pressed, move camera in positive y direction
  case OIS::KC_E:
    mDirection.y = mMove;
    break;

  default:
    break;
  }

  return true;
}

bool TutorialApplication::keyReleased(const OIS::KeyEvent& ke)
{
  switch (ke.key)
  {
  case OIS::KC_W:
    mDirection.z = 0;
    break;

  case OIS::KC_S:
    mDirection.z = 0;
    break;

  case OIS::KC_A:
    mDirection.x = 0;
    break;

  case OIS::KC_D:
    mDirection.x = 0;
    break;

  case OIS::KC_F:
    mDirection.y = 0;
    break;

  case OIS::KC_E:
    mDirection.y = 0;
    break;

  default:
    break;
  }

  return true;
}
//---------------------------------------------------------------------------

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        TutorialApplication app;

        try {
            app.go();
        } catch(Ogre::Exception& e)  {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox(NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occurred: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif

//---------------------------------------------------------------------------
