#include "EntityMgr.h"

EntityMgr::EntityMgr()
{
	deltaVelocity = 50.0f;
	keyboardTimer = keyTime;
	SelectedEntityIndex = 0;

}

EntityMgr::EntityMgr(Ogre::SceneManager* scenemgr)
{
	sceneManager = scenemgr;
}

EntityMgr::~EntityMgr(void)
{
}

void EntityMgr::UpdateVelocity(const OIS::KeyEvent& ke)
{
		Ogre::Quaternion shipOrientation = sceneNodes[SelectedEntityIndex]->getOrientation();
		Ogre::Vector3 forwardDefault = Ogre::Vector3::UNIT_X;
		Ogre::Vector3 currentDirection = shipOrientation * forwardDefault;

	switch (ke.key)
	{
		case OIS::KC_UP:
			EntityInfo[SelectedEntityIndex]->desiredSpeed += currentDirection * 10;
		break;

		case OIS::KC_RIGHT:
			EntityInfo[SelectedEntityIndex]->desiredHeading -= 5;
		break;
		case OIS::KC_LEFT:
			EntityInfo[SelectedEntityIndex]->desiredHeading += 5;
			break;
		case OIS::KC_DOWN:
			EntityInfo[SelectedEntityIndex]->desiredSpeed -= currentDirection * 10;
		break;

		default:
			break;
	}
}

void EntityMgr::tick(float dt)
{
	for (uint index = 0; index != entities.size(); index++)
	{
		EntityInfo[index]->tick(dt);

	}
}

void EntityMgr::CreateEntity(int type, Ogre::Vector3 pos, float heading)
{
	Ogre::Entity* tempEntity;
	Ogre::SceneNode* tempNode;
	string mesh;
	Entity381 *temp = NULL;

	if (type == EntityType::Destroyer)
	{
		temp = new Destroyer(tempNode, tempEntity, entities.size());
	}
	else if (type == EntityType::Frigate)
	{
		temp = new Frigate(tempNode, tempEntity, entities.size());
	}
	else if (type == EntityType::Alien)
	{
		temp = new AlienShip(tempNode, tempEntity, entities.size());
	}
	else if (type == EntityType::Carrier)
	{
		temp = new Carrier(tempNode, tempEntity, entities.size());
	}
	else if (type == EntityType::SpeedBoat)
	{
		temp = new SpeedBoat(tempNode, tempEntity, entities.size());
	}

	tempNode = sceneManager->getRootSceneNode()->createChildSceneNode();
	temp->sceneNodePtr = tempNode;
	tempEntity = sceneManager->createEntity(temp->meshFile);
	tempNode->attachObject(tempEntity);
	tempNode->setPosition(pos);

	sceneNodes.push_back(tempNode);
	entities.push_back(tempEntity);

	temp->heading = heading;
	temp->position = pos;

	EntityInfo.push_back(temp);
}
