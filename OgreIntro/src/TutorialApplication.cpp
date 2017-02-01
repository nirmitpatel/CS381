/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
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
TutorialApplication::TutorialApplication(void)
{
}
//---------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//---------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
    // Create your scene here :)
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

	// Create an entity
	Ogre::Entity* ogreEntity = mSceneMgr->createEntity("ogrehead.mesh");

	// Display entity on the screen
	Ogre::SceneNode* ogreNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	//show the box around it
	ogreNode->showBoundingBox(true);

	// save the SceneNode pointer that is returned by the method
	// so that we can attach our Entity to it
	ogreNode->attachObject(ogreEntity);

	// attach light the scene
	Ogre::Light* light = mSceneMgr->createLight("MainLight");

	// set the position of the light
	light->setPosition(20, 80, 50);

	// set the camera position
	mCamera->setPosition(0, 47, 250);

	// create another entity with different position
	Ogre::Entity* ogreEntity2 = mSceneMgr->createEntity("ogrehead.mesh");

	Ogre::SceneNode* ogreNode2 = mSceneMgr->getRootSceneNode()->createChildSceneNode(
	  Ogre::Vector3(90, 33, 0));
	ogreNode2->attachObject(ogreEntity2);
	//show the box around it
	ogreNode2->showBoundingBox(true);

	// third Ogre head with different size
	Ogre::Entity* ogreEntity3 = mSceneMgr->createEntity("ogrehead.mesh");

	Ogre::SceneNode* ogreNode3 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	ogreNode3->setPosition(0, 104, 0);
	ogreNode3->setScale(2, 1.2, 1);
	ogreNode3->attachObject(ogreEntity3);
	//show the box around it
	ogreNode3->showBoundingBox(true);

	// fourth Ogre rotated in x axis
	Ogre::Entity* ogreEntity4 = mSceneMgr->createEntity("ogrehead.mesh");

	Ogre::SceneNode* ogreNode4 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	ogreNode4->setPosition(-90, 33, 0);
	ogreNode4->roll(Ogre::Degree(-90));
	ogreNode4->attachObject(ogreEntity4);
	ogreNode4->showBoundingBox(true);

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
