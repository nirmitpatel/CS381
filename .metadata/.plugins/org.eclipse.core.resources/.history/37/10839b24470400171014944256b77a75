#include "Entity381.h"

Entity381::Entity381(Ogre::SceneNode* scenePtr, Ogre::Entity* entityPtr)
{
	sceneNodePtr = scenePtr;
	EntityPtr = entityPtr;

	Physics* physicsAspect = new Physics(this);
	Renderable* renderAspect = new Renderable(this);

	aspects.push_back(physicsAspect);
	aspects.push_back(renderAspect);

	isTurning = 0;
}

void Entity381::tick(float dt)
{
	for (uint index = 0; index != aspects.size(); index++)
	{
		aspects[index]->tick(dt);
	}
}

Destroyer::Destroyer(Ogre::SceneNode* scenePtr, Ogre::Entity* entityPtr, int entityID) : Entity381(scenePtr, entityPtr)
{
	entityId = entityID;
	entityName = "Destroyer";
	meshFile = "ddg51.mesh";

	acceleration = 3;
	desiredSpeed = Ogre::Vector3(0, 0, 0);
	speed = Ogre::Vector3(0, 0, 0);
	maxSpeed = 40;

	desiredHeading = 0;
	heading = 0;
	turningRate = 0.05f;
}

Carrier::Carrier(Ogre::SceneNode* scenePtr, Ogre::Entity* entityPtr, int entityID) : Entity381(scenePtr, entityPtr)
{
	entityId = entityID;
	entityName = "Carrier";
	meshFile = "cvn68.mesh";

	acceleration = 1;
	desiredSpeed = Ogre::Vector3(0, 0, 0);
	speed = Ogre::Vector3(0, 0, 0);
	maxSpeed = 100;

	desiredHeading = 0;
	heading = 0;
	turningRate = 0.01f;
}

SpeedBoat::SpeedBoat(Ogre::SceneNode* scenePtr, Ogre::Entity* entityPtr, int entityID) : Entity381(scenePtr, entityPtr)
{
	entityId = entityID;
	entityName = "SpeedBoat";
	meshFile = "cigarette.mesh";

	acceleration = 10;
	desiredSpeed = Ogre::Vector3(0, 0, 0);
	speed = Ogre::Vector3(0, 0, 0);
	maxSpeed = 40;

	desiredHeading = 0;
	heading = 0;
	turningRate = 0.1f;
}

Frigate::Frigate(Ogre::SceneNode* scenePtr, Ogre::Entity* entityPtr, int entityID) : Entity381(scenePtr, entityPtr)
{
	entityId = entityID;
	entityName = "Frigate";
	meshFile = "sleek.mesh";

	acceleration = 5;
	desiredSpeed = Ogre::Vector3(0, 0, 0);
	speed = Ogre::Vector3(0, 0, 0);
	maxSpeed = 40;

	desiredHeading = 0;
	heading = 0;
	turningRate = 0.1f;
}

AlienShip::AlienShip(Ogre::SceneNode* scenePtr, Ogre::Entity* entityPtr, int entityID) : Entity381(scenePtr, entityPtr)
{
	entityId = entityID;
	meshFile = "alienship.mesh";

	acceleration = 10;
	desiredSpeed = Ogre::Vector3(0, 0, 0);
	speed = Ogre::Vector3(0, 0, 0);
	maxSpeed = 100;

	desiredHeading = 0;
	heading = 0;
	turningRate = 0.1f;
}

void Aspect::tick(float dt)
{
}

Aspect::Aspect(Entity381* ptr)
{
	EntityInfo = ptr;
}

Physics::Physics(Entity381* ptr) : Aspect(ptr)
{
}

void Physics::tick(float dt)
{
	Ogre::Quaternion shipOrientation = EntityInfo->sceneNodePtr->getOrientation();
	Ogre::Vector3 forwardDefault = Ogre::Vector3::UNIT_X;
	Ogre::Vector3 currentDirection = shipOrientation * forwardDefault;

	//forward
	if (EntityInfo->speed.length() < EntityInfo->desiredSpeed.length() && EntityInfo->speed < EntityInfo->maxSpeed)
	{
		EntityInfo->speed += EntityInfo->acceleration * currentDirection;
	}
	else if (EntityInfo->speed.length() > EntityInfo->desiredSpeed.length())
	{
		EntityInfo->speed -= EntityInfo->acceleration * currentDirection;
	}

	//turning
	if (EntityInfo->heading < EntityInfo->desiredHeading)
	{
		EntityInfo->isTurning = 1;
		EntityInfo->heading += EntityInfo->turningRate;

		EntityInfo->speed *= Ogre::Vector3(0.8, 0.8, 0.8);
	}
	else if (EntityInfo->heading > EntityInfo->desiredHeading)
	{
		EntityInfo->isTurning = -1;
		EntityInfo->heading -= EntityInfo->turningRate;

		EntityInfo->speed *= Ogre::Vector3(0.8, 0.8, 0.8);
	}
	else
	{
		EntityInfo->isTurning = 0;
	}
	std::cerr << "ENTIY TICK END";
}

Renderable::Renderable(Entity381* ptr) : Aspect(ptr)
{
}

void Renderable::tick(float dt)
{
	EntityInfo->sceneNodePtr->translate(EntityInfo->speed * dt);
	EntityInfo->sceneNodePtr->rotate(Ogre::Vector3::UNIT_Y, Ogre::Degree(EntityInfo->turningRate * EntityInfo->isTurning));
}
