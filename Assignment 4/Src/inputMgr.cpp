/*
 * inputMgr.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: sushil
 */

#include "../Inc/inputMgr.h"
#include "../Inc/Command.h"
#include "../Inc/engine.h"
#include "UnitAI.h"

using namespace std;

InputMgr::InputMgr(Engine *engine) : Mgr(engine){

	// Keyboard
	keyboardTimer = keyTime;
	selectionTimer = selectionTime;

	keyboard = 0;
	mouse = 0;
	oisInputManager = 0;

	OIS::ParamList pl;
	size_t windowHandle = 0;
	std::ostringstream windowHandleStr;
	engine->gfxMgr->ogreRenderWindow->getCustomAttribute("WINDOW", &windowHandle);
	windowHandleStr << windowHandle;

	pl.insert(std::make_pair(std::string("WINDOW"), windowHandleStr.str()));

	// insert the following lines right before calling mInputSystem = OIS::InputManager::createInputSystem( paramList );
#if defined OIS_WIN32_PLATFORM
	pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND" )));
	pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));
	pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND")));
	pl.insert(std::make_pair(std::string("ityw32_keyboard"), std::string("DISCL_NONEXCLUSIVE")));
#elif defined OIS_LINUX_PLATFORM
	pl.insert(std::make_pair(std::string("x11_mouse_grab"), std::string("false")));
	pl.insert(std::make_pair(std::string("x11_mouse_hide"), std::string("false")));
	pl.insert(std::make_pair(std::string("x11_keyboard_grab"), std::string("false")));
	pl.insert(std::make_pair(std::string("XAutoRepeatOn"), std::string("true")));
#endif

	oisInputManager = OIS::InputManager::createInputSystem(pl);
	keyboard = static_cast<OIS::Keyboard*>(oisInputManager->createInputObject(OIS::OISKeyboard, true));
	mouse    = static_cast<OIS::Mouse*>(oisInputManager->createInputObject(OIS::OISMouse, true));

	keyboard->setEventCallback(this);
	mouse->setEventCallback(this);

	windowResized(engine->gfxMgr->ogreRenderWindow);
	Ogre::WindowEventUtilities::addWindowEventListener(engine->gfxMgr->ogreRenderWindow, this);

}

InputMgr::~InputMgr(){ // before gfxMgr destructor

}

void InputMgr::init(){

}

void InputMgr::loadLevel(){

}

void InputMgr::tick(float dt){

	keyboard->capture();
	mouse->capture();
	if(keyboard->isKeyDown(OIS::KC_ESCAPE))
		engine->stop();

	UpdateCamera(dt);
	UpdateDesiredSpeedHeading(dt);
	//UpdateSelection(dt);

}

void InputMgr::stop(){
	if (oisInputManager){
		oisInputManager->destroyInputObject(mouse);
		oisInputManager->destroyInputObject(keyboard);
		OIS::InputManager::destroyInputSystem(oisInputManager);
		oisInputManager = 0;
	}
}

void InputMgr::windowResized(Ogre::RenderWindow* rw){
	unsigned int width, height, depth;
	int left, top;
	rw->getMetrics(width, height, depth, left, top);

	const OIS::MouseState &ms = mouse->getMouseState();
	ms.width = width;
	ms.height = height;
}

void InputMgr::windowClosed(Ogre::RenderWindow* rw){
	//Ogre::WindowEventUtilities::removeWindowEventListener(engine->gfxMgr->ogreRenderWindow, this);
	if(rw == engine->gfxMgr->ogreRenderWindow){
		engine->stop();
	}
}

bool InputMgr::keyPressed(const OIS::KeyEvent &arg) {
	//std::cout << "Key Pressed: " << arg.key << std::endl;
	return true;
}
bool InputMgr::keyReleased(const OIS::KeyEvent &arg){
	//std::cout << "Checking key release" << std::endl;
	if (arg.key == OIS::KC_TAB){
		engine->entityMgr->SelectNextEntity();
	}
	return true;
}




bool InputMgr::mouseMoved(const OIS::MouseEvent &arg){
    return true;
}
bool InputMgr::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id) {


	//engine->entityMgr->selectedEntity->aspects[2]->AddCommand(command);


	if (mouse->getMouseState().buttonDown (OIS::MB_Left)){

		// get window height and width
		Ogre::Real screenWidth = Ogre::Root::getSingleton().getAutoCreatedWindow()->getWidth();
		Ogre::Real screenHeight = Ogre::Root::getSingleton().getAutoCreatedWindow()->getHeight();

		OIS::MouseState arg = mouse->getMouseState();

		// Convert to 0-1 offset
		Ogre::Real offsetX = arg.X.abs / screenWidth;
		Ogre::Real offsetY = arg.Y.abs / screenHeight;

		//set up the ray
		Ogre::Ray mouseRay = engine->gfxMgr->ogreCamera->getCameraToViewportRay(offsetX, offsetY);

		// check if the ray intersects out plane
		// intersects will return whether it intersects or not (return bool value) and
		// what distance ( the real value) along the ray the intersection is
		std::pair<bool, float> result = mouseRay.intersects(engine->gameMgr->mPlane);
		if(result.first)
		{
			//if the ray intersects the plane, we have a distance value
			// telling us how far from the ray origin the intersection occurred
			// the last thing we need is the point of the intersection
			// Ray provides us getPoint() function which returns the point
			// along the ray, supplying it with a distance value
			// get the point where the intersection is

		point = mouseRay.getPoint(result.second);
		cerr << "Left mouse click: "<<point << endl;


		closestBoat = engine->entityMgr->closestBoat(point);
		Ogre::Real temp = closestBoat->pos.distance(point);

		if( temp <= 100 ){
			engine->entityMgr->selectedEntity->isSelected = false;
			engine->entityMgr->selectedEntity = closestBoat;
			engine->entityMgr->selectedEntity->isSelected = true;
			}
		}
	}





	if (mouse->getMouseState().buttonDown (OIS::MB_Right)){
		// get window height and width
		Ogre::Real screenWidth = Ogre::Root::getSingleton().getAutoCreatedWindow()->getWidth();
		Ogre::Real screenHeight = Ogre::Root::getSingleton().getAutoCreatedWindow()->getHeight();

		OIS::MouseState arg = mouse->getMouseState();

		// Convert to 0-1 offset
		Ogre::Real offsetX = arg.X.abs / screenWidth;
		Ogre::Real offsetY = arg.Y.abs / screenHeight;

		//set up the ray
		Ogre::Ray mouseRay = engine->gfxMgr->ogreCamera->getCameraToViewportRay(offsetX, offsetY);

		// check if the ray intersects out plane
		// intersects will return whether it intersects or not (return bool value) and
		// what distance ( the real value) along the ray the intersection is
		std::pair<bool, float> result = mouseRay.intersects(engine->gameMgr->mPlane);
		if(result.first)
		{
			//if the ray intersects the plane, we have a distance value
			// telling us how far from the ray origin the intersection occurred
			// the last thing we need is the point of the intersection
			// Ray provides us getPoint() function which returns the point
			// along the ray, supplying it with a distance value
			// get the point where the intersection is
			point = mouseRay.getPoint(result.second);
			cerr << "Right mouse click: "<<point << endl;
			engine->entityMgr->selectedEntity->targetLocation = point;
			//move->targetLocation = point;
		}

		// Get our closest boat position
		closestBoat = engine->entityMgr->closestBoat(point);
		Ogre::Real temp = closestBoat->pos.distance(point);

		// if our target destination is within range of desired boat
		if( temp <= 100 ) // follow
		{
			// assign entity to follow
			engine->entityMgr->selectedEntity->targetLocation = closestBoat->pos;
			Follow *follow = new Follow(engine->entityMgr->selectedEntity, closestBoat);

			engine->entityMgr->selectedEntity->aspects[2]->AddCommand(follow);
			//engine->entityMgr->selectedEntity->aspects.push_back(a);
		}
		else // move to location
		{
			MoveTo* move = new MoveTo (engine->entityMgr->selectedEntity, point);
			//UnitAI *a = new UnitAI(engine->entityMgr->selectedEntity);
			engine->entityMgr->selectedEntity->aspects[2]->AddCommand(move);
			//engine->entityMgr->selectedEntity->aspects.push_back(a);
		}
	}

	return true;
}

bool InputMgr::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id){
    return true;
}

// Game specific input handling
void InputMgr::UpdateCamera(float dt){
	float move = 100.0f;
	float rotate = 0.1f;
	Ogre::Vector3 temp;

	Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

	temp = engine->gfxMgr->cameraNode->getPosition();

	  if (keyboard->isKeyDown(OIS::KC_W))
	  {
		  if (keyboard->isKeyDown(OIS::KC_LSHIFT))
			  dirVec.z -= 2 * move;
		  else
			  dirVec.z -= move;
	  }

	  if (keyboard->isKeyDown(OIS::KC_S))
	  {
		  if (keyboard->isKeyDown(OIS::KC_LSHIFT))
			  dirVec.z += 2 * move;
		  else
			  dirVec.z += move;
	  }

	  if (keyboard->isKeyDown(OIS::KC_R))
	  {
		  if (keyboard->isKeyDown(OIS::KC_LSHIFT))
		  {
			  dirVec.y += 2 * move;
		  }
		  else
		  {
			  dirVec.y += move;
		  }
	  }

	  if (keyboard->isKeyDown(OIS::KC_F))
	  {
		  if(temp.y >= 10)
		  {
			  if (keyboard->isKeyDown(OIS::KC_LSHIFT))
			  {
				  dirVec.y -= 2 * move;
			  }
			  else
			  {
				  dirVec.y -= move;
			  }
		  }
	  }

	  if (keyboard->isKeyDown(OIS::KC_A))
	  {
		  if (keyboard->isKeyDown(OIS::KC_LSHIFT))
			  dirVec.x -= 2 * move;
		  else
			  dirVec.x -= move;
	  }

	  if (keyboard->isKeyDown(OIS::KC_D))
	  {
		  if (keyboard->isKeyDown(OIS::KC_LSHIFT))
			  dirVec.x += 2 * move;
		  else
			  dirVec.x += move;
	  }

	  if (keyboard->isKeyDown(OIS::KC_Z))
	  {
		  if (keyboard->isKeyDown(OIS::KC_LSHIFT))
			  engine->gfxMgr->cameraNode->yaw(Ogre::Degree(2 * rotate));
		  else
		  engine->gfxMgr->cameraNode->yaw(Ogre::Degree(0.5 * rotate));
	  }

	  if (keyboard->isKeyDown(OIS::KC_X))
	  {
		  if (keyboard->isKeyDown(OIS::KC_LSHIFT))
			  engine->gfxMgr->cameraNode->yaw(Ogre::Degree(2 * -rotate));
		  else
			  engine->gfxMgr->cameraNode->yaw(Ogre::Degree(0.5 * -rotate));
	  }

	  if (keyboard->isKeyDown(OIS::KC_Q))
	  {
		  if (keyboard->isKeyDown(OIS::KC_LSHIFT))
			  engine->gfxMgr->cameraNode->pitch(Ogre::Degree(2 * rotate));
		  else
			  engine->gfxMgr->cameraNode->pitch(Ogre::Degree(0.5 * rotate));
	  }

	  if (keyboard->isKeyDown(OIS::KC_E))
	  {
		  if (keyboard->isKeyDown(OIS::KC_LSHIFT))
			  engine->gfxMgr->cameraNode->pitch(Ogre::Degree(2 * -rotate));
		  else
			  engine->gfxMgr->cameraNode->pitch(Ogre::Degree(0.5 * -rotate));
	  }

	  engine->gfxMgr->cameraNode->translate(dirVec * dt, Ogre::Node::TS_WORLD);

}

void InputMgr::UpdateDesiredSpeedHeading(float dt){
	keyboardTimer -= dt;

	if(engine->entityMgr->selectedEntity){

		if((keyboardTimer < 0) && keyboard->isKeyDown(OIS::KC_NUMPAD8)){
			keyboardTimer = keyTime;
			engine->entityMgr->selectedEntity->desiredSpeed += 10;
		}
		if((keyboardTimer < 0) && keyboard->isKeyDown(OIS::KC_NUMPAD2)){
			keyboardTimer = keyTime;
			engine->entityMgr->selectedEntity->desiredSpeed -= 10;
		}
		engine->entityMgr->selectedEntity->desiredSpeed =
				std::max(engine->entityMgr->selectedEntity->minSpeed,
						std::min(engine->entityMgr->selectedEntity->maxSpeed,
								engine->entityMgr->selectedEntity->desiredSpeed));


		if((keyboardTimer < 0) && keyboard->isKeyDown(OIS::KC_NUMPAD4)){
			keyboardTimer = keyTime;
			//std::cout << std::endl << engine->entityMgr->selectedEntity->heading << std::endl << std::endl;
			engine->entityMgr->selectedEntity->desiredHeading -= 0.3f;
			cout << endl << engine->entityMgr->selectedEntity->desiredHeading << endl << endl;
		}
		if((keyboardTimer < 0) && keyboard->isKeyDown(OIS::KC_NUMPAD6)){
			keyboardTimer = keyTime;
			engine->entityMgr->selectedEntity->desiredHeading += 0.3f;
		}
		//entityMgr->selectedEntity->desiredHeading = FixAngle(entityMgr->selectedEntity->desiredHeading);
	}

}

void InputMgr::UpdateSelection(float dt){
	selectionTimer -= dt;
	if(selectionTimer < 0 && keyboard->isKeyDown(OIS::KC_TAB)){
		selectionTimer = this->selectionTime;
		engine->entityMgr->SelectNextEntity();
	}
}




