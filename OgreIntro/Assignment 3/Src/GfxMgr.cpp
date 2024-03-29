/*
 * GfxMgr.cpp
 *
 *  Created on: Mar 17, 2017
 *      Author: jwoo
 */

#include <GfxMgr.h>
#include <engine.h>

using namespace std;

GfxMgr::GfxMgr(Engine* engine) : Mgr(engine), mRoot(0), mResourcesCfg(Ogre::StringUtil::BLANK),
		mPluginsCfg(Ogre::StringUtil::BLANK), mWindow(0), mSceneMgr(0), mCamera(0), ogreSceneManager(0){
}

GfxMgr::~GfxMgr(){

}


void GfxMgr::tick(float dt){
	Ogre::WindowEventUtilities::messagePump();

	mWindow->isClosed();

	mRoot->renderOneFrame();
}

void GfxMgr::init(){

	#ifdef _DEBUG
	  mResourcesCfg = "resources_d.cfg";
	  mPluginsCfg = "plugins_d.cfg";
	#else
	  mResourcesCfg = "resources.cfg";
	  mPluginsCfg = "plugins.cfg";
	#endif

	  mRoot = new Ogre::Root(mPluginsCfg);

	  Ogre::ConfigFile cf;
	  cf.load(mResourcesCfg);

	  Ogre::String name, locType;
	  Ogre::ConfigFile::SectionIterator secIt = cf.getSectionIterator();

	  while (secIt.hasMoreElements())
	  {
		Ogre::ConfigFile::SettingsMultiMap* settings = secIt.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator it;

		for (it = settings->begin(); it != settings->end(); ++it)
		{
		  locType = it->first;
		  name = it->second;

		  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, locType);
		}
	  }

	  if (!(mRoot->restoreConfig() || mRoot->showConfigDialog()))
	    engine->keepRunning = false;

	  mRoot->restoreConfig();
	  mRoot->showConfigDialog();

	  mWindow = mRoot->initialise(true, "TutorialApplication Render Window");

	  Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
	  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

	  mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);

	  mCamera = mSceneMgr->createCamera("MainCam");
	  mCamera->setPosition(0, 0, 80);
	  mCamera->lookAt(0, 0, -300);
	  mCamera->setNearClipDistance(5);

	  Ogre::Viewport* vp = mWindow->addViewport(mCamera);
	  vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0));

	  mCamera->setAspectRatio(
	  Ogre::Real(vp->getActualWidth()) /
	  Ogre::Real(vp->getActualHeight()));
}


void GfxMgr::loadLevel(){

	  // Create Scene
	  Ogre::Entity* ogreEntity = mSceneMgr->createEntity("ogrehead.mesh");

	  Ogre::SceneNode* ogreNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	  ogreNode->attachObject(ogreEntity);

	  mSceneMgr->setAmbientLight(Ogre::ColourValue(.5, .5, .5));

	  Ogre::Light* light = mSceneMgr->createLight("MainLight");
	  light->setPosition(20, 80, 50);

	  OIS::ParamList pl;
	  size_t windowHandle = 0;
	  std::ostringstream windowHandleStr;

	  mWindow->getCustomAttribute("WINDOW", &windowHandle);
	  windowHandleStr << windowHandle;
	  pl.insert(std::make_pair(std::string("WINDOW"), windowHandleStr.str()));

	  windowResized(mWindow);
	  Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);

	  mRoot->addFrameListener(this);

	  mSceneMgr->setSkyBox(true, "Examples/MorningSkyBox");

	  Ogre::Plane plane(Ogre::Vector3::UNIT_Y, -5);

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
	  	groundEntity->setMaterialName("Ocean2_HLSL_GLSL");
	  //groundEntity->setMaterialName("OceanHLSL_GLSL");
	  //groundEntity->setMaterialName("Ocean2_Cg");
	  //groundEntity->setMaterialName("NavyCg");

	  //mRoot->startRendering();
	  //cout << endl << "11" << endl << endl << endl;
}

void GfxMgr::stop(){
	Ogre::WindowEventUtilities::removeWindowEventListener(mWindow, this);

	windowClosed(mWindow);

	delete mRoot;
}
























