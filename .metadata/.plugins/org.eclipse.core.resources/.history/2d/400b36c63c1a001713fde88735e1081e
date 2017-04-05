/*
 * UnitAI.h
 *
 *  Created on: Apr 3, 2017
 *      Author: jwoo
 */

#ifndef INC_UNITAI_H_
#define INC_UNITAI_H_
#include <Aspect.h>
#include <inputMgr.h>
#include <queue>
#include <Types.h>

class UnitAI: public Aspect {

public:

	std::queue<Command*> commands;

	UnitAI(Entity381* ent);
	~UnitAI();

	void Tick(float dt);
	Command* GetCommand(Command *c);
	void AddCommand(Command *c);

};


#endif /* INC_UNITAI_H_ */
