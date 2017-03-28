/*
 * InputMgr.h
 *
 *  Created on: Mar 23, 2017
 *      Author: nirmitp
 */

#ifndef INC_INPUTMGR_H_
#define INC_INPUTMGR_H_

#include <list>
#include <OgreVector3.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>

#include <Entity381.h>
#include <mgr.h>

class InputMgr : Mgr {

public:
	InputMgr InputMgr;
	~InputMgr();

	virtual void tick(float dt);
	virtual void init();
	virtual void loadLevel();
	virtual void stop();
};



#endif /* INC_INPUTMGR_H_ */
