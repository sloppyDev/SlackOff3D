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


