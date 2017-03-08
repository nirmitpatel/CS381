#include "EntityMgr.h"
using namespace std;

EntityMgr::EntityMgr(Ogre::SceneManager* mSceneMgr){
	mSceneManager = mSceneMgr;
}

void EntityMgr::Tick(float dt)
{
	for(int i = 0; i<5;i++)
	{
		boat[i]->Tick(dt);
	}
}


void EntityMgr::CreateEntity( EntityType type, Ogre::Vector3 pos, float heading){
	Entity381 * temp;
	switch (type){
	case Destroy:
		boat[0] = new Destroyer;
		boat[0]->ogreEntity = mSceneManager ->createEntity(boat[0]->meshFileName);
		boat[0]->ogreSceneNode = mSceneManager->getRootSceneNode()->createChildSceneNode(pos);
		boat[0]->ogreSceneNode->attachObject(boat[0]->ogreEntity);
		boat[0]->ogreEntity->setMaterialName("Deck");
	break;

	case Car:
		boat[1] = new Carrier;
		boat[1]->ogreEntity = mSceneManager ->createEntity(boat[1]->meshFileName);
		boat[1]->ogreSceneNode = mSceneManager->getRootSceneNode()->createChildSceneNode(pos);
		boat[1]->ogreSceneNode->attachObject(boat[1]->ogreEntity);
		boat[1]->ogreEntity->setMaterialName("DEF_1/SOLID/TEX/ecslDark.bmp/VertCol");
	break;

	case Frig:
		boat[2] = new Frigate;
		boat[2]->ogreEntity = mSceneManager ->createEntity(boat[2]->meshFileName);
		boat[2]->ogreSceneNode = mSceneManager->getRootSceneNode()->createChildSceneNode(pos);
		boat[2]->ogreSceneNode->attachObject(boat[2]->ogreEntity);
		boat[2]->ogreEntity->setMaterialName("DD21-Dark-Hatche/SOLID/TEX/ecsl.bmp");
	break;

	case Speed:
		boat[3] = new Speedboat;
		boat[3]->ogreEntity = mSceneManager ->createEntity(boat[3]->meshFileName);
		boat[3]->ogreSceneNode = mSceneManager->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(pos));
		boat[3]->ogreSceneNode->attachObject(boat[3]->ogreEntity);
		boat[3]->ogreEntity->setMaterialName("SOLID/TEX/ecslHorizontal.bmp");
	break;

	case Al:
		boat[4] = new Alien;
		boat[4]->ogreEntity = mSceneManager ->createEntity(boat[4]->meshFileName);
		boat[4]->ogreSceneNode = mSceneManager->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(pos));
		boat[4]->ogreSceneNode->attachObject(boat[4]->ogreEntity);
		boat[4]->ogreEntity->setMaterialName("al-1");
	break;
	}
}
