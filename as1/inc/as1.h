/*
 * As1.h
 *
 *  Created on: Jan 24, 2017
 *      Author: sushil
 */

#ifndef __As1_h_
#define __As1_h_

#include "BaseApplication.h"

class As1 : public BaseApplication
{
public:
  As1();
  virtual ~As1();
  virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);

  void MakeGround();
  void MakeSky();
  void MakeFog();
  void UpdateCamera(const Ogre::FrameEvent& fe);
  void UpdateVelocity(const Ogre::FrameEvent& fe);
  void UpdatePosition(const Ogre::FrameEvent& fe);
  void CopyPositionToSceneNode();



  //------------------------------------------------------------

  Ogre::SceneNode* cubeSceneNode;
  Ogre::SceneNode* cameraNode;
  Ogre::Vector3 velocity;
  Ogre::Vector3 position;
  float yaw;
  float deltaVelocity;
  float keyboardTimer;
  const static float keyTime = 0.01f;

protected:
  virtual void createScene();
  //virtual void createCamera();
  //virtual void createViewports();
};

#endif // #ifndef __As1_h_
