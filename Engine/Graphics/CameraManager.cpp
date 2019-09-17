#include "CameraManager.h"

CameraManager::CameraManager()
{
   pos = vector3(0.0f, 3000.0f, 700.0f);
   quat = quaternion(0.0f, vector3(0.0f, 1.0f, 0.0f));
   transRate = vector3(400.0f);
   rotRate = vector3(100.0f);
}

CameraManager::CameraManager(vector3 _pos) : CameraManager()
{
   pos = _pos;
   lastPos = pos;
}

CameraManager::CameraManager(vector3 _pos, vector3 _ang) : CameraManager(_pos)
{
   quat = quaternion::EulerToQuat(_ang);
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
}

void CameraManager::HandleInputs()
{
   vector3 translateValues = transRate * Engine::dt;
   vector3 rotateValues = rotRate * Engine::dt;

   // Translation
   if (Keyboard::Key(forwardKey)) // Forward
   {
      Translate(3, translateValues.z);
   }

   if (Keyboard::Key(leftKey)) // Left
   {
      Translate(1, -translateValues.x);
   }

   if (Keyboard::Key(backKey)) // Back
   {
      Translate(3, -translateValues.z);
   }

   if (Keyboard::Key(rightKey)) // Right
   {
      Translate(1, translateValues.x);
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
      Rotate(1, -rotateValues.x);
   }

   if (Keyboard::Key(rotLeftKey)) // Left
   {
      Rotate(2, -rotateValues.y);
   }

   if (Keyboard::Key(rotDownKey)) // Down
   {
      Rotate(1, rotateValues.x);
   }

   if (Keyboard::Key(rotRightKey)) // Right
   {
      Rotate(2, rotateValues.y);
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
   vector3 cameraTransRot;
   vector3 worldTransVec;

   switch (axis)
   {
   case 1:
   {
      cameraTransVec = vector3(magnitude, 0.0f, 0.0f);
      worldTransVec = Rotation::Rotate(cameraTransVec, quat, 0);
      pos = pos + worldTransVec;
   }
   break;
   case 2:
   {
      cameraTransVec = vector3(0.0f, magnitude, 0.0f);
      worldTransVec = Rotation::Rotate(cameraTransVec, quat, 0);
      pos = pos + worldTransVec;
   }
   break;
   case 3:
   {
      cameraTransVec = vector3(0.0f, 0.0f, magnitude);
      worldTransVec = Rotation::Rotate(cameraTransVec, quat, 0);
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
      worldRotVec = Rotation::Rotate(cameraRotVec, quat, 0);
      quaternion newQuat(worldRotVec);
      quat = newQuat*quat;
   }
   break;
   case 2:
   {
      cameraRotVec = vector3(0.0f, deg, 0.0f);
      worldRotVec = Rotation::Rotate(cameraRotVec, quat, 0);
      quaternion newQuat = quaternion(worldRotVec);
      quat = newQuat*quat;
   }
   break;
   case 3:
   {
      cameraRotVec = vector3(0.0f, 0.0f, deg);
      worldRotVec = Rotation::Rotate(cameraRotVec, quat, 0);
      quaternion newQuat(worldRotVec);
      quat = newQuat*quat;
   }
   break;
   }
}

vector3 CameraManager::GetPos()
{
   return pos;
}

quaternion CameraManager::GetQuat()
{
   return quat;
}