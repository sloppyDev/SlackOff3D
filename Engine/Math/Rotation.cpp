#include "Rotation.h"

#include <math.h>

matrix3 Rotation::rot1(float angle)
{
   vector3 row1 = vector3(1.0f, 0.0f, 0.0f);
   vector3 row2 = vector3(0.0f, (float)cos(angle), -(float)sin(angle));
   vector3 row3 = vector3(0.0f, (float)sin(angle), (float)cos(angle));

   matrix3 newMat = matrix3(row1, row2, row3);

   return newMat;
}

matrix3 Rotation::rot2(float angle)
{
   vector3 row1 = vector3((float)cos(angle), 0.0f, (float)sin(angle));
   vector3 row2 = vector3(0.0f, 1.0f, 0.0f);
   vector3 row3 = vector3(-(float)sin(angle), 0.0f, (float)cos(angle));

   matrix3 newMat = matrix3(row1, row2, row3);

   return newMat;
}

matrix3 Rotation::rot3(float angle)
{
   vector3 row1 = vector3((float)cos(angle), (float)sin(angle), 0.0f);
   vector3 row2 = vector3(-(float)sin(angle), (float)cos(angle), 0.0f);
   vector3 row3 = vector3(0.0f, 0.0f, 1.0f);

   matrix3 newMat = matrix3(row1, row2, row3);

   return newMat;
}

vector3 Rotation::Rotate(vector3 vec, vector3 angVec)
{
   vector3 rotVec = Rotate(vec, 3, angVec.z);
   rotVec = Rotate(rotVec, 2, angVec.y);
   rotVec = Rotate(rotVec, 1, angVec.x);

   return rotVec;
}

vector3 Rotation::Rotate(vector3 vec, quaternion quat, int mode) // mode == 0 -> standard, mode == 1 -> inverse
{
   vector3 rotVec;

   if (mode == 1)
   {
      quat.Conjugate();
   }

   float m11 = 2 * quat.r * quat.r + 2 * quat.v.x * quat.v.x - 1;
   float m12 = 2 * quat.v.x * quat.v.y - 2 * quat.r * quat.v.z;
   float m13 = 2 * quat.v.x * quat.v.z + 2 * quat.r * quat.v.y;

   float m21 = 2 * quat.v.x * quat.v.y + 2 * quat.r * quat.v.z;
   float m22 = 2 * quat.r * quat.r + 2 * quat.v.y * quat.v.y - 1;
   float m23 = 2 * quat.v.y * quat.v.z - 2 * quat.r * quat.v.x;

   float m31 = 2 * quat.v.x * quat.v.z - 2 * quat.r * quat.v.y;
   float m32 = 2 * quat.v.y * quat.v.z + 2 * quat.r * quat.v.x;
   float m33 = 2 * quat.r * quat.r + 2 * quat.v.z * quat.v.z - 1;

   matrix3 Q(vector3(m11, m12, m13), vector3(m21, m22, m23), vector3(m31, m32, m33));

   rotVec = Q * vec;

   return rotVec;
}

triple Rotation::Rotate(triple tri, quaternion quat, int mode) // mode == 0 -> leave r, mode == 1 -> r = r*-1
{
   vector3 rotP1;
   vector3 rotP2;
   vector3 rotP3;

   rotP1 = Rotate(tri.p1, quat, mode);
   rotP2 = Rotate(tri.p2, quat, mode);
   rotP3 = Rotate(tri.p3, quat, mode);

   triple newTri(rotP1, rotP2, rotP3);

   return newTri;
}

vector3 Rotation::Rotate(vector3 vec, unsigned int axis, float angle)
{
   float rad = DegToRad(angle);
   switch (axis)
   {
   case 1:
   {
      vector3 rotVec = rot1(rad) * vec;
      return rotVec;
   }
   break;
   case 2:
   {
      vector3 rotVec = rot2(rad) * vec;
      return rotVec;
   }
   break;
   case 3:
   {
      vector3 rotVec = rot3(rad) * vec;
      return rotVec;
   }
   break;
   default:
      return vec;
   }
}

vector3 Rotation::Rotate(vector3 vec, unsigned int axis, float angle, vector3 rotPoint)
{
   vector3 zeroedVec = vec - rotPoint;
   
   vector3 newVec = Rotate(zeroedVec, axis, angle);

   return (newVec + rotPoint);
}

triple Rotation::Rotate(triple tri, unsigned int axis, float angle)
{
   vector3 rotP1 = Rotate(tri.p1, axis, angle);
   vector3 rotP2 = Rotate(tri.p2, axis, angle);
   vector3 rotP3 = Rotate(tri.p3, axis, angle);

   return triple(rotP1, rotP2, rotP3, tri.color);
}

triple Rotation::Rotate(triple tri, unsigned int axis, float angle, vector3 rotPoint)
{
   triple zeroedTri = tri - rotPoint;
   triple newTri = Rotate(zeroedTri, axis, angle);
   triple rotTri = newTri + rotPoint;
   rotTri.color = tri.color;

   return rotTri;
}

float Rotation::RadToDeg(float rad)
{
   float deg = (rad * 180.0f) / PI;
   
   return deg;
}

float Rotation::DegToRad(float deg)
{
   float rad = (deg * PI) / 180.0f;

   return rad;
}

Rotation::Rotation()
{

}

Rotation::~Rotation()
{

}


