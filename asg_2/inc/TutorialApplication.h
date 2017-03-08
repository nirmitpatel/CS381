/*
 * As1.h
 *
 *  Created on: March 4, 2017
 *      Author: Worsnop
 */

#ifndef __TutorialApplication_h_
#define __TutorialApplication_h_

#include "BaseApplication.h"
#include "EntityMgr.h"

class TutorialApplication : public BaseApplication
{
public:
	TutorialApplication();
  virtual ~TutorialApplication();
  virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);

  void MakeGround();
  void MakeSky();
  void MakeFog();
  void SetupLight();
  void SetupCamera();

  void UpdateCamera(const Ogre::FrameEvent& fe);
  void UpdateSelection();

  virtual bool keyPressed(const OIS::KeyEvent& ke);
  virtual bool keyReleased(const OIS::KeyEvent& ke);


  //------------------------------------------------------------

  EntityMgr* EntityManager;
  Ogre::SceneNode* cameraNode;

  float move = 400.0f;
  float rotate;
  float yaw;
  float dt = 25.0f;

  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

protected:
  virtual void createScene();

};

#endif // #ifndef __As1_h_
