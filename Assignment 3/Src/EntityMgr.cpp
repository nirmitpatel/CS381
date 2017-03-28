/*
 * EntityMgr.cpp
 *
 *  Created on: Feb 22, 2017
 *      Author: sushil
 */


#include <EntityMgr.h>
#include <Types.h>


EntityMgr::EntityMgr(Ogre::SceneManager *ogreSM) : Mgr(engine){
	ogreSceneMgr = ogreSM;
	entities.clear();
	selectedEntity = 0;
}

EntityMgr::~EntityMgr(){
	entities.clear();
}

void EntityMgr::CreateOgreEntityAndNode(Entity381 *ent){

	if(ent) {
		ent->ogreEntity = ogreSceneMgr->createEntity(ent->meshfile);
		ent->ogreSceneNode = ogreSceneMgr->getRootSceneNode()->createChildSceneNode(ent->pos);
		ent->ogreSceneNode->attachObject(ent->ogreEntity);
		ent->ogreSceneNode->yaw(Ogre::Radian(ent->heading));
	}

}

Entity381* EntityMgr::CreateEntity(EntityType entityType, Ogre::Vector3 position, float heading){

	Entity381 *ent = 0;// = new Entity381(entityType, position, heading);
	switch(entityType){
	case EntityType::ALIEN:
		ent = new Alien(position, heading);
		break;
	case EntityType::CIGARETTE:
		ent = new Cigarette(position, heading);
		break;
	case EntityType::DDG:
		ent = new Ddg(position, heading);
		break;
	case EntityType::CVN:
		ent = new Cvn(position, heading);
		break;
	case EntityType::FRIGATE:
		ent = new Frigate(position, heading);
		break;
	default:
		ent = new Ddg(position, heading);
		break;
	}

	CreateOgreEntityAndNode(ent);
	entities.push_front(ent);
	return ent;
}

void EntityMgr::Tick(float dt){

	for (std::list<Entity381 *>::const_iterator it = entities.begin(); it != entities.end(); ++it){
		(*it)->Tick(dt);
		if ((*it)->isSelected)
			this->selectedEntity = (*it);
	}
}

void EntityMgr::SelectNextEntity(){
	int n = 0;

	for (std::list<Entity381 *>::const_iterator it = entities.begin(); it != entities.end(); ++it){
		n++;
		if((*it)->isSelected){
			(*it)->isSelected = false;
			it++;
			if(it == entities.end()){
				std::cout << "End of ents" << std::endl;
				selectedEntity = *(entities.begin());
			} else {
				selectedEntity = *it;
				std::cout << "End of ents" << std::endl;
			}
			selectedEntity->isSelected = true;
			break;
		}
	}
}

EntityMgr::EntityMgr(Engine* engine) : Mgr(engine){

	Entity381 * ent;
	int x = 0;
	ent = entityMgr->CreateEntity(EntityType::DDG, Ogre::Vector3(x, 0, 0), 0);
	std::cout << "Created: " << ent->meshfile << std::endl;
	x = x+200;
	ent = entityMgr->CreateEntity(EntityType::CIGARETTE, Ogre::Vector3(x, 0, 0), 0);
	std::cout << "Created: " << ent->meshfile << std::endl;
	x = x+200;
	ent = entityMgr->CreateEntity(EntityType::ALIEN, Ogre::Vector3(x, 0, 0), 0);
	std::cout << "Created: " << ent->meshfile << std::endl;
	x = x+200;
	ent = entityMgr->CreateEntity(EntityType::CVN, Ogre::Vector3(x, 0, 0), 0);
	std::cout << "Created: " << ent->meshfile << std::endl;
	x = x+300;
	ent = entityMgr->CreateEntity(EntityType::FRIGATE, Ogre::Vector3(x, 0, 0), 0);
	std::cout << "Created: " << ent->meshfile << std::endl;


	ent->isSelected = true;

}




void EntityMgr::init(){

}

void EntityMgr::loadLevel(){

}

void EntityMgr::stop(){

}














