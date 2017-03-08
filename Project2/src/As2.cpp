/*
 * As2.cpp

 *
 *  Created on: Mar 1, 2017
 *      Author: Nirmit Patel
 */


#include "As2.h"
#include <iostream>

using namespace std;


//EntityMgr* entityMgr;

As2::As2(void)
{
	deltaVelocity = 50.0f;
	yaw = 0.0f;
	position = Ogre::Vector3::ZERO;
	velocity = Ogre::Vector3::ZERO;
	keyboardTimer = keyTime;
	cubeSceneNode = 0;
}

As2::~As2(void)
{
}

void As2::createScene(void)
{
  mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

  mCamera->lookAt(Ogre::Vector3(0, 0, 0));

  Ogre::Light* light = mSceneMgr->createLight("MainLight");
  light->setPosition(20.0, 80.0, 50.0);

   // Create the 5 boats
   entityMgr = new EntityMgr(mSceneMgr);
   entityMgr->CreateEntity(Destroy,Ogre::Vector3(0,0,-200),0.0f);
   entityMgr->CreateEntity(Car,Ogre::Vector3(0,0,-100),0.0f);
   entityMgr->CreateEntity(Frig,Ogre::Vector3(0,0,0),0.0f);
   entityMgr->CreateEntity(Speed,Ogre::Vector3(0,0,100),0.0f);
   entityMgr->CreateEntity(Al,Ogre::Vector3(0,0,200),0.0f);

   entityMgr->boat[selected]->isSelected = true;
   entityMgr->boat[selected]->ogreSceneNode->showBoundingBox(true);

  // A node to attach the camera to so we can move the camera node instead of the camera.
  cameraNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
  cameraNode->setPosition(0, 200, 1000);
  cameraNode->attachObject(mCamera);

  MakeGround();
  MakeSky();

}

void As2::Selection(){

	entityMgr->boat[selected]->isSelected = false;
	entityMgr->boat[selected]->ogreSceneNode->showBoundingBox(false);

	selected = (selected + 1) % 5;
	entityMgr->boat[selected]->isSelected = true;
	entityMgr->boat[selected]->ogreSceneNode->showBoundingBox(true);

}

void As2::UpdateCamera(const Ogre::FrameEvent& fe){
	float move = 400.0f;
	float rotate = 0.1f;

	 Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

	  if (mKeyboard->isKeyDown(OIS::KC_W))
	    dirVec.z -= move;

	  if (mKeyboard->isKeyDown(OIS::KC_S))
	    dirVec.z += move;

	  if (mKeyboard->isKeyDown(OIS::KC_R))
	    dirVec.y += move;

	  if (mKeyboard->isKeyDown(OIS::KC_F))
	    dirVec.y -= move;

	  if (mKeyboard->isKeyDown(OIS::KC_A))
	      dirVec.x -= move;

	  if (mKeyboard->isKeyDown(OIS::KC_D))
	      dirVec.x += move;

	  if (mKeyboard->isKeyDown(OIS::KC_Q))
		  cameraNode->pitch(Ogre::Degree(-5 * rotate));

	  if (mKeyboard->isKeyDown(OIS::KC_E))
		  cameraNode->pitch(Ogre::Degree(5 * rotate));

	  if (mKeyboard->isKeyDown(OIS::KC_X))
		  cameraNode->yaw(Ogre::Degree(-5 * rotate));

	  if (mKeyboard->isKeyDown(OIS::KC_Z))
		  cameraNode->yaw(Ogre::Degree(5 * rotate));

	  cameraNode->translate(dirVec * fe.timeSinceLastFrame, Ogre::Node::TS_LOCAL);

}

bool As2::frameRenderingQueued(const Ogre::FrameEvent& fe){

	mKeyboard->capture();
	if(mKeyboard->isKeyDown(OIS::KC_ESCAPE)){
		return false;
	}

	mTrayMgr->frameRenderingQueued(fe);

	UpdateCamera(fe);

	UpdateVelocity(fe);

	entityMgr->Tick(fe.timeSinceLastFrame);

	return true;
}

void As2::UpdateVelocity(const Ogre::FrameEvent& fe){
	keyboardTimer -= fe.timeSinceLastEvent;

	if((keyboardTimer < 0) && mKeyboard->isKeyDown(OIS::KC_NUMPAD8)){
		keyboardTimer = keyTime;
		entityMgr->boat[selected]->velocity.z -= entityMgr->boat[selected]->acceleration;
	}
	if((keyboardTimer < 0) && mKeyboard->isKeyDown(OIS::KC_NUMPAD2)){
		keyboardTimer = keyTime;
		entityMgr->boat[selected]->velocity.z += entityMgr->boat[selected]->acceleration;
	}
	if((keyboardTimer < 0) && mKeyboard->isKeyDown(OIS::KC_NUMPAD4)){
		keyboardTimer = keyTime;
		//entityMgr->boat[selected]->desiredHeading -= entityMgr->boat[selected]->turningRate;
		entityMgr->boat[selected]->ogreSceneNode->yaw(Ogre::Degree(entityMgr->boat[selected]->turningRate));
	}
	if((keyboardTimer < 0) && mKeyboard->isKeyDown(OIS::KC_NUMPAD6)){
		keyboardTimer = keyTime;
		entityMgr->boat[selected]->ogreSceneNode->yaw(Ogre::Degree(-entityMgr->boat[selected]->turningRate));
		//entityMgr->boat[selected]->desiredHeading += entityMgr->boat[selected]->turningRate;
	}

	if((keyboardTimer < 0) && mKeyboard->isKeyDown(OIS::KC_SPACE)){
		keyboardTimer = keyTime;
		velocity = Ogre::Vector3::ZERO;
	}
	if((keyboardTimer < 0) && mKeyboard->isKeyDown(OIS::KC_TAB)){
		keyboardTimer = .1;
		Selection();
	}

}

void As2::MakeGround(){

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
	  //	  groundEntity->setMaterialName("Ocean2_HLSL_GLSL");
	  groundEntity->setMaterialName("OceanHLSL_GLSL");
	  //groundEntity->setMaterialName("Ocean2_Cg");
	  //groundEntity->setMaterialName("NavyCg");

}

void As2::MakeSky(){

	mSceneMgr->setSkyBox(true, "Examples/MorningSkyBox");

}

void As2::MakeFog(){
	Ogre::ColourValue fadeColour(0.9, 0.9, 0.9);
	mWindow->getViewport(0)->setBackgroundColour(fadeColour);
	mSceneMgr->setFog(Ogre::FOG_LINEAR, fadeColour, 0, 600, 900);
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
	As2 app;

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
