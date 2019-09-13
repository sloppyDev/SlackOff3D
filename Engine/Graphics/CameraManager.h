#ifndef SLACKOFF_CAMERAMANAGER
#define SLACKOFF_CAMERAMANAGER

#include "../Engine.h"
#include "../IO/Keyboard.h"
#include "../Math/vector3.h"
#include "../Math/Rotation.h"

#include <vector>

class CameraManager
{
public:
   CameraManager();
   CameraManager(vector3 _pos);
   CameraManager(vector3 _pos, vector3 _ang);
   CameraManager(vector3 _pos, vector3 _ang, vector3 _transRate);
   CameraManager(vector3 _pos, vector3 _ang, vector3 _transRate, vector3 rotRate);
   ~CameraManager();

   void Update();
   void HandleInputs();
   void Translate(int axis, float magnitude);
   void Rotate(int axis, float deg);
   std::vector<vector3> GetPose();

private:
   vector3 pos;
   vector3 ang;
   vector3 transRate;
   vector3 rotRate;

   // Translate Keys
   int forwardKey = GLFW_KEY_W;
   int leftKey = GLFW_KEY_A;
   int backKey = GLFW_KEY_S;
   int rightKey = GLFW_KEY_D;
   int upKey = GLFW_KEY_Q;
   int downKey = GLFW_KEY_E;

   // Rotate Keys
   int rotUpKey = GLFW_KEY_I;
   int rotLeftKey = GLFW_KEY_J;
   int rotDownKey = GLFW_KEY_K;
   int rotRightKey = GLFW_KEY_L;
   int rollLeftKey = GLFW_KEY_U;
   int rollRightKey = GLFW_KEY_O;
};
#endif
