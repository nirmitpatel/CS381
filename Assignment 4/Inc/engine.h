/*
 * engine.h
 *
 *  Created on: Mar 9, 2017
 *      Author: sushil
 */

#ifndef ENGINE_H_
#define ENGINE_H_

#include "../Inc/EntityMgr.h"
#include "../Inc/gameMgr.h"
#include "../Inc/GfxMgr.h"
#include "../Inc/inputMgr.h"
#include "../Inc/Command.h"
#include "../Inc/UnitAI.h"

class Engine {
private:
public:
	Engine();
	~Engine();


	EntityMgr*      entityMgr;
	GfxMgr*         gfxMgr;
	InputMgr*       inputMgr;
	GameMgr*        gameMgr;
	//Command*		command;
	//MoveTo*			moveTo;
	//UnitAI*			AI;
	//SelectionMgr* selectionMgr;
	//ControlMgr*   controlMgr;

	void init();
	void run();
	void tickAll(float dt);
	void stop();
	void shutdown();

	//
	bool keepRunning;


};



#endif /* ENGINE_H_ */
