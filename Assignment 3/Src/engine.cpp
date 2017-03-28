/*
 * engine.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: sushil
 */

#include <engine.h>
#include <OgreTimer.h>
#include <iostream>

Engine::Engine(){
	gfxMgr = 0;
	inputMgr = 0;
	entityMgr = 0;
	gameMgr = 0;
	keepRunning = true;

}

Engine::~Engine(){

}

void Engine::stop(){
	keepRunning = false;
}

void Engine::init(){
// construct
	gfxMgr    = new GfxMgr(this);
	std::cout << "Constructed GfxMgr" << std::endl<< std::endl<< std::endl;
	inputMgr = new InputMgr(this);
	std::cout << "Constructed inputMgr" << std::endl<< std::endl<< std::endl;
	//entityMgr = new EntityMgr(this);
	//gameMgr = new GameMgr(this);
// initialize
	gfxMgr->init();
	std::cout << "init GfxMgr" << std::endl<< std::endl<< std::endl;
	inputMgr->init();
	std::cout << "init inputMgr" << std::endl<< std::endl<< std::endl;
	//entityMgr->init();
	//gameMgr->init();
// load level to play
	gfxMgr->loadLevel();
	std::cout << "loaded level GfxMgr" << std::endl<< std::endl<< std::endl;
	inputMgr->loadLevel();
	std::cout << "loaded level inputMgr" << std::endl<< std::endl<< std::endl;
	//entityMgr->loadLevel();
	//gameMgr->loadLevel();
}

void Engine::tickAll(float dt){
	gfxMgr->tick(dt);
	//std::cout << "tick GfxMgr" << std::endl<< std::endl<< std::endl;
	inputMgr->tick(dt);
	//entityMgr->Tick(dt);
	//gameMgr->tick(dt);
}

void Engine::shutdown(){
	inputMgr->stop();
	std::cout << "stopped InputMgr" << std::endl<< std::endl<< std::endl;
	gfxMgr->stop();
	std::cout << "stopped gfxMgr" << std::endl<< std::endl<< std::endl;
	//entityMgr->stop();
	//gameMgr->stop();
}
void Engine::run(){
	Ogre::Timer* timer = new Ogre::Timer();
	float oldTime = timer->getMilliseconds()/1000.0f;
	float newTime;
	float dt = 0.001f;
	while(keepRunning){
		newTime = timer->getMilliseconds()/1000.0f;
		dt = newTime - oldTime;
		oldTime = newTime;
		tickAll(dt);
		//std::cout << dt << std::endl<< std::endl<< std::endl;
	}
	shutdown();

	return;
}
