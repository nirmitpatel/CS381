/*
 * gameMgr.h
 *
 *  Created on: Mar 17, 2017
 *      Author: jwoo
 */

#ifndef INC_GAMEMGR_H_
#define INC_GAMEMGR_H_




#include <mgr.h>
class GameMgr : Mgr{
public:

	GameMgr();
	GameMgr(Engine* engine);


	virtual void tick(float dt);
	virtual void init();
	virtual void loadLevel();
	virtual void stop();

};






#endif /* INC_GAMEMGR_H_ */