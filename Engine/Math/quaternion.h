#ifndef SLACKOFF_QUATERNION
#define SLACKOFF_QUATERNION

#include "vector3.h"

class Rotation;

class quaternion
{
public:
   static quaternion EulerToQuat(vector3 ang);
   static vector3 QuatToEuler(quaternion _quat);
   quaternion();
   quaternion(float angle, vector3 direction);
   quaternion(vector3 angles);
   ~quaternion();

   quaternion& operator=(const quaternion& other);
   quaternion operator*(const quaternion& other);

   void Normalize();
   void Conjugate();

   float r;
   vector3 v;
};
#endif