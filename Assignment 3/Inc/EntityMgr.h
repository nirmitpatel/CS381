/*
 * EntityMgr.h
 *
 *  Created on: Feb 22, 2017
 *      Author: sushil
 */

#ifndef ENTITYMGR_H_
#define ENTITYMGR_H_


#include <list>
#include <OgreVector3.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>

#include <Entity381.h>
#include <mgr.h>


class EntityMgr : Mgr{

private:
//
public:
	std::list<Entity381 *> entities;
	Ogre::SceneManager *ogreSceneMgr;
	Entity381* selectedEntity;

	EntityMgr(Ogre::SceneManager *ogreSceneMgr);
	~EntityMgr();

	Entity381 *CreateEntity(EntityType entityType, Ogre::Vector3 pos, float yaw = 0);
	void CreateOgreEntityAndNode(Entity381 *ent);
	void Tick(float dt);
	void SelectNextEntity();

	virtual void init();
	virtual void loadLevel();
	virtual void stop();

	EntityMgr(Engine* engine);

	EntityMgr *entityMgr;
};



#endif /* ENTITYMGR_H_ */
