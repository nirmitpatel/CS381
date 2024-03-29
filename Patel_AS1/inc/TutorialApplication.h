/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.h
Name: Nirmit Patel
Class: CS 381
Date: February 22, 2017
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/
Tutorial Framework (for Ogre 1.9)
http://www.ogre3d.org/wiki/
-----------------------------------------------------------------------------
*/

#ifndef __TutorialApplication_h_
#define __TutorialApplication_h_

#include "BaseApplication.h"

//---------------------------------------------------------------------------

class TutorialApplication : public BaseApplication
{
public:
    TutorialApplication(void);
    virtual ~TutorialApplication(void);

protected:
    virtual void createScene(void);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);
    Ogre::Vector3 updateVelocity();
    Ogre::Vector3 updatePosition();
    int velocity;
    Ogre::Vector3 vector;

private:
    bool processUnbufferedInput(const Ogre::FrameEvent& fe);

    Ogre::SceneNode* mCamNode;
    Ogre::Vector3 mDirection;
    Ogre::Real mMove;

    virtual bool keyPressed(const OIS::KeyEvent& ke);
    virtual bool keyReleased(const OIS::KeyEvent& ke);
};

//---------------------------------------------------------------------------

#endif // #ifndef __TutorialApplication_h_

//---------------------------------------------------------------------------
