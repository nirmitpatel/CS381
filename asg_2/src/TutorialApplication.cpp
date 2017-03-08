//============================================================================
// Name        : as1.cpp
// Author      : Sushil J Louis
// Version     :
// Copyright   : All rights reserved
// Description : Assignment 1
//============================================================================

#include "TutorialApplication.h"

TutorialApplication::TutorialApplication(void)
{
	rotate = 0;
	yaw = 0;
	static EntityType types;
}

TutorialApplication::~TutorialApplication(void)
{
}

void TutorialApplication::SetupLight()
{
   mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
   Ogre::Light* light = mSceneMgr->createLight("MainLight");
   light->setPosition(20.0, 80.0, 50.0);
}

void TutorialApplication::SetupCamera()
{
	mCamera->lookAt(Ogre::Vector3(0, 0, 0));

	// A node to attach the camera to so we can move the camera node instead of the camera.
	  cameraNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	  cameraNode->setPosition(300, 200, 900);
	  cameraNode->attachObject(mCamera);
}

void TutorialApplication::createScene(void)
{
  //setup light
  SetupLight();

  //setup camera
  SetupCamera();

  //create all entities
  EntityManager = new EntityMgr(mSceneMgr);

  EntityManager->CreateEntity(EntityType::Destroyer, Ogre::Vector3(0, 0, 0), 0.0f);
  EntityManager->CreateEntity(EntityType::Frigate, Ogre::Vector3(200, 0, 200), 0.0f);
  EntityManager->CreateEntity(EntityType::Carrier, Ogre::Vector3(400, 0, -200), 0.0f);
  EntityManager->CreateEntity(EntityType::Alien, Ogre::Vector3(400, 0, 0), 0.0f);
  EntityManager->CreateEntity(EntityType::SpeedBoat, Ogre::Vector3(400, 0, 200), 0.0f);

  EntityManager->SelectedEntityIndex = 0;
  EntityManager->SelectedEntity = EntityManager->entities[0];
  EntityManager->sceneNodes[EntityManager->SelectedEntityIndex]->showBoundingBox(true);

  MakeGround();
  MakeSky();
}

void TutorialApplication::UpdateCamera(const Ogre::FrameEvent& fe){


}

bool TutorialApplication::frameRenderingQueued(const Ogre::FrameEvent& fe){

	mKeyboard->capture();
	if(mKeyboard->isKeyDown(OIS::KC_ESCAPE)){
		return false;
	}

	mTrayMgr->frameRenderingQueued(fe);

	cameraNode->translate(dirVec * fe.timeSinceLastFrame, Ogre::Node::TS_LOCAL);
	cameraNode->pitch(Ogre::Degree(5 * rotate));
	cameraNode->yaw(Ogre::Degree(5 * yaw));

	EntityManager->tick(fe.timeSinceLastFrame);

	return true;
}

void TutorialApplication::MakeGround(){

	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

	  Ogre::MeshManager::getSingleton().createPlane(
	    "ground",
	    Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
	    plane,
	    15000, 15000, 20, 20,
	    true,
	    1, 5, 5,
	    Ogre::Vector3::UNIT_Z);

	  Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
	  mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
	  groundEntity->setCastShadows(false);
	  groundEntity->setMaterialName("OceanHLSL_GLSL");
}

void TutorialApplication::MakeSky()
{
	mSceneMgr->setSkyBox(true, "Examples/MorningSkyBox");
}

void TutorialApplication::MakeFog()
{
	Ogre::ColourValue fadeColour(0.9, 0.9, 0.9);
	mWindow->getViewport(0)->setBackgroundColour(fadeColour);
	mSceneMgr->setFog(Ogre::FOG_LINEAR, fadeColour, 0, 600, 900);
}

void TutorialApplication::UpdateSelection()
{
	EntityManager->sceneNodes[EntityManager->SelectedEntityIndex]->showBoundingBox(false);
	EntityManager->SelectedEntityIndex = EntityManager->SelectedEntityIndex + 1;

	if (EntityManager->SelectedEntityIndex == 5)
	{
		EntityManager->SelectedEntityIndex = 0;
	}

    EntityManager->SelectedEntity = EntityManager->entities[EntityManager->SelectedEntityIndex];
	EntityManager->sceneNodes[EntityManager->SelectedEntityIndex]->showBoundingBox(true);
}

bool TutorialApplication::keyPressed(const OIS::KeyEvent& ke)
{
	switch (ke.key)
	{
		case OIS::KC_TAB:
			UpdateSelection();
			break;
		case OIS::KC_W:
			dirVec.z -= move;
			break;
		case OIS::KC_S:
			dirVec.z += move;
			break;
		case OIS::KC_R:
			dirVec.y += move;
			break;
		case OIS::KC_F:
			dirVec.y -= move;
			break;
		case OIS::KC_A:
			dirVec.x -= move;
			break;
		case OIS::KC_D:
			dirVec.x += move;
			break;
		case OIS::KC_Q:
			yaw = 0.1f;
			break;
		case OIS::KC_E:
			yaw = -0.1f;
			break;
		case OIS::KC_X:
			rotate = -0.1f;
			break;
		case OIS::KC_Z:
			rotate = 0.1f;
			break;

		default:
			EntityManager->UpdateVelocity(ke);
			break;
	 }

	return true;
}

bool TutorialApplication::keyReleased(const OIS::KeyEvent& ke)
{
	switch (ke.key)
	{
		case OIS::KC_W:
			dirVec.z = 0;
			break;
		case OIS::KC_S:
			dirVec.z = 0;
			break;
		case OIS::KC_R:
			dirVec.y = 0;
			break;
		case OIS::KC_F:
			dirVec.y = 0;
			break;
		case OIS::KC_A:
			dirVec.x = 0;
			break;
		case OIS::KC_D:
			dirVec.x = 0;
			break;
		case OIS::KC_Q:
			yaw = 0;
			break;
			case OIS::KC_E:
			yaw = 0;
			break;
		case OIS::KC_X:
			rotate = 0;
			break;
		case OIS::KC_Z:
			rotate = 0;
			break;

		default:
			break;
	}
	return true;
}


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

