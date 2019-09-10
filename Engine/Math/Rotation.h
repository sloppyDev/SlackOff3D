#ifndef SLACKOFF_ROTATION
#define SLACKOFF_ROTATION

#include "matrix3.h"
#include "vector3.h"
#include "triple.h"

class Rotation
{
public:
   static matrix3 rot1(float angle);
   static matrix3 rot2(float angle);
   static matrix3 rot3(float angle);

   static vector3 Rotate(vector3 vec, unsigned int axis, float angle);
   static triple Rotate(triple tri, unsigned int axis, float angle);

   static float RadToDeg(float rad);
   static float DegToRad(float deg);

   Rotation();
   ~Rotation();
};
#endif
