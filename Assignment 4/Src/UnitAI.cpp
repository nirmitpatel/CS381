/*
 * UnitAI.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: nirmitp
 */
#include <UnitAI.h>
#include <engine.h>

UnitAI::UnitAI(Entity381* ent) : Aspect(ent){

}

UnitAI::~UnitAI(){

}

void UnitAI::Tick(float dt){

	if(commands.front() == NULL)
	{
		return;
	}

	for(unsigned int i = 0; i<commands.size(); i++)
	{

		if(!commands.front()->done())
		{
			commands.front()->tick(dt);
		}
		else
		{
			std::cerr<<"Queue Popped"<<std::endl;
			commands.pop();
		}
	}
}

Command * UnitAI::GetCommand(Command *c){

	Command *temp = new Command();

	// if the command doesnt exist
	if(!c)
	{
		return NULL;
	}



	return temp;
}


void UnitAI::AddCommand(Command *c){

	std::cout<<"command added to queue"<<std::endl;

	commands.push(c);
}

















