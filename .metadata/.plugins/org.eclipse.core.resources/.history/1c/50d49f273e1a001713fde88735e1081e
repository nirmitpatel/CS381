/*
 * Command.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: jwoo
 */
#include <Command.h>

using namespace std;

Command::Command()
{

}

Command::Command(Entity381* ent, COMMAND_TYPE ct){
	//std::cout << "Constuctor command created" << std::endl << std::endl;
	entity = ent;
}


Command::~Command(){

}


void Command::init(){

}



void Command::tick(float dt){

}


bool Command::done(){

}



MoveTo::MoveTo(Entity381* ent, Ogre::Vector3 location) : Command(ent, commandType){


	std::cerr<<"Move to instantiated"<<std::endl;
	targetLocation = location;
	isFinished = false;
}


MoveTo::~MoveTo(){

}


void MoveTo::init(){/*
	std::cout << " this is 1" << std::endl << std::endl;
	std::cout << "target: " << targetLocation << "pos: " << entity->pos << std::endl << std::endl;
	if (targetLocation != entity->pos){
		std::cout << "2" << std::endl << std::endl;
		entity->desiredSpeed = entity->maxSpeed;
		std::cout << "3" << std::endl << std::endl;
	}
	std::cout << "4" << std::endl << std::endl;*/
}



void MoveTo::tick(float dt){

	// Calculate distance
	//Ogre::Real distance = Ogre::Math::Sqrt(deltaVec.x * deltaVec.x + deltaVec.y * deltaVec.y);
	Ogre::Real distance = targetLocation.distance(entity->pos);

	//std::cerr<<"Our target location is: "<< targetLocation<<std::endl;

	//std::cerr<<"The distance between the ship and dest is: "<<distance<<std::endl;

	// if the ships within threshold
	if(distance < MOVE_DISTANCE_THRESHOLD)
	{
		std::cerr<<"the ship is at its destination"<<std::endl;
		// slow down
		entity->desiredSpeed = 0;
		entity->vel = Ogre::Vector3::ZERO;

		// and now command is finished
		isFinished = true;
		return;
	}
	//std::cerr<<"The position of our entity is "<< entity->pos<<std::endl;

	// get proper heading to face destination
	//Ogre::Radian angle = Ogre::Math::ATan2(targetLocation.z, targetLocation.x);
	Ogre::Vector3 difference = targetLocation - entity->pos;
	Ogre::Radian angle = Ogre::Math::ATan2(difference.z, difference.x);
	float heading = angle.valueRadians();
	//cout << "This is the distance: " << distance << endl;
	//entity->desiredSpeed = entity->maxSpeed;

	/*if(angle >= Ogre::Math::TWO_PI)
	{
		angle -= Ogre::Math::TWO_PI;
	}
	else if(angle <= Ogre::Math::TWO_PI)
	{
		angle += Ogre::Math::TWO_PI;
	}*/

	if(heading < 0)
	{
		heading += Ogre::Math::TWO_PI;
	}
	else if (heading >= Ogre::Math::TWO_PI)
	{
		heading -= Ogre::Math::TWO_PI;
	}


	// set the proper heading
	//if(angle.valueRadians() < 0)
			//entity->desiredHeading = angle.valueRadians() * -1;
	//else
	entity->desiredHeading = heading;

	//std::cerr<<"Desired Heading: "<<entity->desiredHeading<<std::endl;
	//cout << "our angle is " << heading << endl;
	//cout << targetLocation << endl;


	// accelerate to max speed possible toward the destination
	entity->desiredSpeed = entity->maxSpeed;
}


bool MoveTo::done(){

	return isFinished;
}


Follow::Follow(Entity381* ent, Entity381* boat) : Command(ent, commandType){
	isFinished = false;
	followedBoat = boat;

	std::cerr<<"Follow instantiated"<<std::endl;
}


Follow::~Follow(){

}


void Follow::init(){

}



void Follow::tick(float dt){



	targetLocation = followedBoat->pos;

	Ogre::Real distance = targetLocation.distance(entity->pos);

	//std::cerr<<"The distance between the ship and dest is: "<<distance<<std::endl;

	// if the ships within threshold
	if(distance < MOVE_DISTANCE_THRESHOLD)
	{
		std::cerr<<"the ship is at its destination"<<std::endl;
		// slow down
		entity->desiredSpeed = 0;
		entity->vel = Ogre::Vector3::ZERO;

		// and now command is finished
		isFinished = true;
		return;
	}
	//std::cerr<<"The position of our entity is "<< entity->pos<<std::endl;

	// get proper heading to face destination
	//Ogre::Radian angle = Ogre::Math::ATan2(targetLocation.z, targetLocation.x);
	Ogre::Vector3 difference = targetLocation - entity->pos;
	Ogre::Radian angle = Ogre::Math::ATan2(difference.z, difference.x);

	// set the proper heading
	entity->desiredHeading = angle.valueRadians();
	//std::cerr<<"Desired Heading: "<<entity->desiredHeading<<std::endl;

	// accelerate to max speed possible toward the destination
	entity->desiredSpeed = entity->maxSpeed;
}


bool Follow::done(){

	return isFinished;
}








