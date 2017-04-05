/*
 * Command.h
 *
 *  Created on: Apr 3, 2017
 *      Author: jwoo
 */

#ifndef INC_COMMAND_H_
#define INC_COMMAND_H_
#include <Entity381.h>
#include <inputMgr.h>
#include <Types.h>

class Command {

public:
	Command();
	Command(Entity381* ent, COMMAND_TYPE ct);
	virtual ~Command();

	virtual void init();
	virtual void tick(float dt);
	virtual bool done();

	Entity381* entity;
	COMMAND_TYPE commandType;
};

class MoveTo: public Command {

public:
	MoveTo(Entity381* ent, Ogre::Vector3 location);
	~MoveTo();

	void init();
	void tick(float dt);
	bool done();

	Ogre::Vector3 targetLocation;
	float MOVE_DISTANCE_THRESHOLD = 150;

	bool isFinished;

};



class Follow: public Command {

public:
	Follow(Entity381* ent, Entity381* boat);
	~Follow();

	void init();
	void tick(float dt);
	bool done();

	Ogre::Vector3 targetLocation;
	float MOVE_DISTANCE_THRESHOLD = 100;

	bool isFinished;
	Entity381* followedBoat;
};





#endif /* INC_COMMAND_H_ */
