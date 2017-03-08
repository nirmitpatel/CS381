/*
 * As2.h

 *
 *  Created on: Mar 1, 2017
 *      Author: mcbaker
 */

#ifndef INC_AS2_H_
#define INC_AS2_H_

#include "BaseApplication.h"
#include "EntityMgr.h"
#include "Entity381.h"

class As2 : public BaseApplication
{
public:
  As2();
  virtual ~As2();
  virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);

  void MakeGround();
  void MakeSky();
  void MakeFog();
  void UpdateCamera(const Ogre::FrameEvent& fe);
  void UpdateVelocity(const Ogre::FrameEvent& fe);
  //void UpdatePosition(const Ogre::FrameEvent& fe);
  //void CopyPositionToSceneNode(const Ogre::FrameEvent& fe);
  void updateHeading(Entity381 boat);
  EntityMgr* entityMgr;
  void Selection();


  //------------------------------------------------------------

  Ogre::SceneNode* cubeSceneNode;
  Ogre::SceneNode* cameraNode;
  Ogre::Vector3 velocity;
  Ogre::Vector3 position;
  float yaw;
  float deltaVelocity;
  float keyboardTimer;
  const static float keyTime = 0.01f;
  int selected = 0;

protected:
  virtual void createScene();
};

#endif /* INC_AS2_H_ */