/*
 * UnitAI.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: jwoo
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
	//MoveTo(Entity381->ent, c->targetLocation);

	Command *temp = new Command();

	// if the command doesnt exist
	if(!c)
	{
		return NULL;
	}



	return temp;
}


void UnitAI::AddCommand(Command *c){

	//MoveTo *move;

	/*switch(c->commandType)
	{
	case COMMAND_TYPE::moveTo:
		std::cerr<<"In the command type check"<<std::endl;

		move = new MoveTo(entity, entity->targetLocation);
		std::cerr<<"Move to instantiated"<<std::endl;
		//c = move;
		break;
	case COMMAND_TYPE::follow:
		std::cerr<<"Follow instantiated"<<std::endl;
		break;

	}*/

	std::cout<<"command added to queue"<<std::endl;

	commands.push(c);



}

















