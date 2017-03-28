/*
 * GameMgr.h
 *
 *  Created on: Mar 23, 2017
 *      Author: nirmitp
 */

#ifndef INC_GAMEMGR_H_
#define INC_GAMEMGR_H_

#include <list>
#include <OgreVector3.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>

#include <Entity381.h>
#include <mgr.h>

class GameMgr : Mgr {

public:
	GameMgr GameMgr;
	~GameMgr();

	virtual void tick(float dt);
	virtual void init();
	virtual void loadLevel();
	virtual void stop();

};



#endif /* INC_GAMEMGR_H_ */
