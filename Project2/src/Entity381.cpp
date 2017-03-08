/*
 * Entity381.cpp
 *
 *  Created on: Mar 1, 2017
 *      Author: mcbaker
 */


#include "Entity381.h"
//#include "Aspect.h"


void Entity381::Tick(float dt)
{
	for(int i =0 ; i<2; i++)
	{
		aspectList[i]->Tick(dt);
	}
}

Entity381::Entity381(void){
	entityID =0;
	entityName = " ";
	minSpeed =0.0;
	maxSpeed =0.0;
	speed =0.0;
	heading =0.0;
	desiredSpeed =0.0;
	desiredHeading =0.0;
	acceleration =0.0;
	turningRate =0.0;

	meshFileName = "";
	position = Ogre::Vector3::ZERO;
	des = Ogre::Vector3(0, 0, 0);
	velocity = Ogre::Vector3::ZERO;

	ogreSceneNode = NULL;
	ogreEntity = NULL;
	isSelected = false;

	Aspect *physics;
	physics = new PhysicsAspect(this);

	Aspect *renderable;
	renderable = new RenderAspect(this);

	aspectList.push_back(physics);
	aspectList.push_back(renderable);
}

Destroyer::Destroyer(void){
	Entity381::entityID=1;
	Entity381::entityName = "Destroyer";
	Entity381::maxSpeed = 40;
	Entity381::minSpeed = 10;
	Entity381::acceleration = 1;
	spe = Ogre::Vector3(0, 0, 0);
	Entity381::turningRate = 10;
	Entity381::meshFileName = "ddg51.mesh";
}

Carrier::Carrier(void){

	Entity381::entityID=1;
	Entity381::entityName = "Carrier";
	Entity381::maxSpeed = 4.0;
	Entity381::acceleration = 0.1;
	Entity381::turningRate = .5;
	Entity381::meshFileName = "cvn68.mesh";
}

Speedboat::Speedboat(void){

	Entity381::entityID=1;
	Entity381::entityName = "Speedboat";
	Entity381::maxSpeed = 8.0;
	Entity381::acceleration = 0.4;
	Entity381::turningRate = 2;
	Entity381::meshFileName = "cigarette.mesh";
}


Frigate::Frigate(void){

	Entity381::entityID=1;
	Entity381::entityName = "Frigate";
	Entity381::maxSpeed = 8.0;
	Entity381::acceleration = 0.3;
	Entity381::turningRate = 3;
	Entity381::meshFileName = "sleek.mesh";
}

Alien::Alien(void){

	Entity381::entityID=1;
	Entity381::entityName = "Alien";
	Entity381::maxSpeed = 10.0;
	Entity381::acceleration = 1.0;
	Entity381::turningRate = 5;
	Entity381::meshFileName = "alienship.mesh";
}









Aspect::Aspect()
{

}
Aspect::Aspect(Entity381* ent)
{
	entity = ent;
}
Aspect::~Aspect()
{

}

void Aspect::Tick(float dt)
{

}


PhysicsAspect::PhysicsAspect()
{

}
PhysicsAspect::PhysicsAspect(Entity381* ent)
{
	entity = ent;
}

PhysicsAspect::~PhysicsAspect()
{
}

void PhysicsAspect::Tick(float dt)
{
	Ogre::Quaternion shipOrientation = entity->ogreSceneNode->getOrientation();
	Ogre::Vector3 forwardDefault = Ogre::Vector3::UNIT_X;
	Ogre::Vector3 currentDirection = shipOrientation * forwardDefault;


	entity->position = entity->position + (entity->velocity * dt);


	if(entity->des > entity->spe)
	{
		entity->spe += entity->acceleration;

		if(entity->des < entity->spe)
		{
			entity->spe = entity->maxSpeed;
		}
	}

	else if(entity->des < entity->spe)
	{
		entity->spe -= entity->acceleration;

		if(entity->des > entity->spe)
			{
				entity->spe = entity->minSpeed;
			}
	}



	if(entity->desiredHeading > entity->heading)
	{
		entity->heading += entity->turningRate;

		entity->ogreSceneNode->yaw(Ogre::Degree(-(entity->turningRate)));
		entity->isTurning = 1;
	}

	else if(entity->desiredHeading < entity->heading)
	{
		entity->heading -= entity->turningRate;

		entity->ogreSceneNode->yaw(Ogre::Degree(entity->turningRate));
		entity->isTurning = -1;
	}
	else
	entity->isTurning = 0;


	entity->ogreSceneNode->translate(entity->velocity*dt, Ogre::Node::TS_LOCAL);
	entity->ogreSceneNode->rotate(Ogre::Vector3::UNIT_Y, Ogre::Degree(entity->turningRate * entity->isTurning));

}


RenderAspect::RenderAspect()
{

}

RenderAspect::RenderAspect(Entity381* ent)
{

}

RenderAspect::~RenderAspect()
{

}


void RenderAspect:: Tick(float dt)
{
	//entity->ogreSceneNode->setPosition(entity->position);
	//entity->ogreSceneNode->yaw(Ogre::Degree(-5));
}








