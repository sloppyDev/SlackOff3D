#include "CameraManager.h"

CameraManager::CameraManager()
{
   pos = vector3(0.0f, 0.0f, -1.0f);
   ang = vector3();
   transRate = vector3(100.0f);
   rotRate = vector3(100.0f);
}

CameraManager::CameraManager(vector3 _pos) : CameraManager()
{
   pos = _pos;
}

CameraManager::CameraManager(vector3 _pos, vector3 _ang) : CameraManager(_pos)
{
   ang = _ang;
}

CameraManager::CameraManager(vector3 _pos, vector3 _ang, vector3 _transRate) : CameraManager(_pos, _ang)
{
   transRate = _transRate;
}

CameraManager::CameraManager(vector3 _pos, vector3 _ang, vector3 _transRate, vector3 _rotRate) : CameraManager(_pos, _ang, _transRate)
{
   rotRate = _rotRate;
}

CameraManager::~CameraManager()
{

}

void CameraManager::Update()
{
   HandleInputs();
   //std::cout << "POS: X: " << pos.x << "Y: " << pos.y << "Z: " << pos.z << std::endl;
   //std::cout << "ANG: X: " << ang.x << "Y: " << ang.y << "Z: " << ang.z << std::endl << std::endl;
}

void CameraManager::HandleInputs()
{
   vector3 translateValues = transRate * Engine::dt;
   vector3 rotateValues = rotRate * Engine::dt;

   // Translation
   if (Keyboard::Key(forwardKey)) // Forward
   {
      Translate(3, -translateValues.z);
   }

   if (Keyboard::Key(leftKey)) // Left
   {
      Translate(1, translateValues.x);
   }

   if (Keyboard::Key(backKey)) // Down
   {
      Translate(3, translateValues.z);
   }

   if (Keyboard::Key(rightKey)) // Right
   {
      Translate(1, -translateValues.x);
   }

   if (Keyboard::Key(upKey)) // Up
   {
      Translate(2, translateValues.y);
   }

   if (Keyboard::Key(downKey)) // Down
   {
      Translate(2, -translateValues.y);
   }

   // Rotation
   if (Keyboard::Key(rotUpKey)) // Up
   {
      Rotate(1, rotateValues.x);
   }

   if (Keyboard::Key(rotLeftKey)) // Left
   {
      Rotate(2, rotateValues.y);
   }

   if (Keyboard::Key(rotDownKey)) // Down
   {
      Rotate(1, -rotateValues.x);
   }

   if (Keyboard::Key(rotRightKey)) // Right
   {
      Rotate(2, -rotateValues.y);
   }

   if (Keyboard::Key(rollLeftKey)) // Roll Left
   {
      Rotate(3, rotateValues.z);
   }

   if (Keyboard::Key(rollRightKey)) // Roll Right
   {
      Rotate(3, -rotateValues.z);
   }
}

void CameraManager::Translate(int axis, float magnitude)
{
   vector3 cameraTransVec;
   vector3 worldTransVec;

   switch (axis)
   {
   case 1:
   {
      cameraTransVec = vector3(magnitude, 0.0f, 0.0f);
      worldTransVec = Rotation::Rotate(cameraTransVec, ang*-1);
      pos = pos + worldTransVec;
   }
   break;
   case 2:
   {
      cameraTransVec = vector3(0.0f, magnitude, 0.0f);
      worldTransVec = Rotation::Rotate(cameraTransVec, ang*-1);
      pos = pos + worldTransVec;
   }
   break;
   case 3:
   {
      cameraTransVec = vector3(0.0f, 0.0f, magnitude);
      worldTransVec = Rotation::Rotate(cameraTransVec, ang*-1);
      pos = pos + worldTransVec;
   }
   break;
   }
}

void CameraManager::Rotate(int axis, float deg)
{
   vector3 cameraRotVec;
   vector3 worldRotVec;

   switch (axis)
   {
   case 1:
   {
      cameraRotVec = vector3(deg, 0.0f, 0.0f);
      worldRotVec = Rotation::Rotate(cameraRotVec, ang);
      worldRotVec = cameraRotVec;
      ang = ang + worldRotVec;
   }
   break;
   case 2:
   {
      cameraRotVec = vector3(0.0f, deg, 0.0f);
      worldRotVec = Rotation::Rotate(cameraRotVec, ang);
      worldRotVec = cameraRotVec;
      ang = ang + worldRotVec;
   }
   break;
   case 3:
   {
      cameraRotVec = vector3(0.0f, 0.0f, deg);
      worldRotVec = Rotation::Rotate(cameraRotVec, ang);
      worldRotVec = cameraRotVec;
      ang = ang + worldRotVec;
   }
   break;
   }
}

std::vector<vector3> CameraManager::GetPose()
{
   std::vector<vector3> poseVec;

   poseVec.push_back(pos);
   poseVec.push_back(ang);

   return poseVec;
}