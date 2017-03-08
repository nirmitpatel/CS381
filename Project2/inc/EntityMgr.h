/*
 * EntityMgr.h
 *
 *  Created on: Mar 5, 2017
 *      Author: Nirmit Patel
 */

#ifndef INC_ENTITYMGR_H_
#define INC_ENTITYMGR_H_

#include "Entity381.h"
#include "BaseApplication.h"
#include <vector>

enum EntityType{Destroy, Car, Speed, Frig, Al };

class EntityMgr {
public:
	EntityMgr(Ogre::SceneManager* mSceneMgr);
	Entity381* boat[5];

	void Tick(float dt);
	void CreateEntity( EntityType , Ogre::Vector3 , float);
	Ogre::SceneManager * mSceneManager = NULL;
};


#endif /* INC_ENTITYMGR_H_ */
