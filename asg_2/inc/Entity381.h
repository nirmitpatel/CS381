
#include "BaseApplication.h"
#include <vector>
#include <string>

using namespace std;

class Aspect;

class Entity381
{

public:

	Entity381(Ogre::SceneNode* scenePtr, Ogre::Entity* entityPtr);

    void tick(float dt);

	int entityId;
	string entityName;
	string meshFile;

	Ogre::Vector3 minSpeed;
	Ogre::Vector3 maxSpeed;
	Ogre::Vector3 speed;
	Ogre::Vector3 desiredSpeed;
	Ogre::Vector3 position;
	Ogre::Vector3 velocity;

	float desiredHeading;
	float heading;
	float turningRate;
	float acceleration;
	int isTurning;

	Ogre::SceneNode* sceneNodePtr;
	Ogre::Entity* EntityPtr;

	vector<Aspect*> aspects;
};

class Destroyer : public Entity381
{

public:

	Destroyer(Ogre::SceneNode* scenePtr, Ogre::Entity* entityPtr, int entityID);

};

class Carrier : public Entity381
{

public:

	Carrier(Ogre::SceneNode* scenePtr, Ogre::Entity* entityPtr, int entityID);

};

class SpeedBoat : public Entity381
{

public:

	SpeedBoat(Ogre::SceneNode* scenePtr, Ogre::Entity* entityPtr, int entityID);

};

class Frigate : public Entity381
{

public:

	Frigate(Ogre::SceneNode* scenePtr, Ogre::Entity* entityPtr, int entityID);

};

class AlienShip : public Entity381
{

public:

	AlienShip(Ogre::SceneNode* scenePtr, Ogre::Entity* entityPtr, int entityID);
};

class Aspect
{

public:

	Aspect(Entity381* ptr);

	Entity381* EntityInfo;
	virtual void tick(float dt);
};


class Physics : public Aspect
{

public:

	Physics(Entity381* ptr);

	void tick(float dt);
};

class Renderable : public Aspect
{

public:

	Renderable(Entity381* ptr);

	void tick(float dt);
};


