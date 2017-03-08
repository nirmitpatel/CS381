#include "BaseApplication.h"
#include "Entity381.h"
#include "EntityType.h"
#include <vector>

using namespace std;

class EntityMgr
{

public:
  EntityMgr();
  EntityMgr(Ogre::SceneManager* scenemgr);
  ~EntityMgr();

  vector<Ogre::SceneNode*> sceneNodes;
  vector<Ogre::Entity*> entities;
  Ogre::Entity *SelectedEntity;
  Ogre::Vector3 position;
  Ogre::Vector3 velocity;
  Ogre::SceneManager* sceneManager;
  vector<Entity381*> EntityInfo;

  int SelectedEntityIndex;
  float keyboardTimer;
  const static float keyTime = 0.01f;

  float deltaVelocity;

  void UpdateVelocity(const OIS::KeyEvent& ke);
  void CopyPositionToSceneNode();
  void CreateEntity(int type, Ogre::Vector3 pos, float heading);
  virtual void tick(float dt);

};
