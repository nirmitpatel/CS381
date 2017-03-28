/*
 * GfxMgr.h
 *
 *  Created on: Mar 23, 2017
 *      Author: nirmitp
 */

#ifndef INC_GFXMGR_H_
#define INC_GFXMGR_H_

#include <list>
#include <OgreVector3.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>

#include <Entity381.h>
#include <mgr.h>

class GfxMgr : Mgr {

public:
	GfxMgr GfxMgr;
	~GfxMgr();

	virtual void tick(float dt);
	virtual void init();
	virtual void loadLevel();
	virtual void stop();

};
#endif /* INC_GFXMGR_H_ */
