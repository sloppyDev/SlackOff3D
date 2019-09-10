#ifndef SLACKOFF_TRIPLE
#define SLACKOFF_TRIPLE

#include "vector3.h"

class triple
{
public:
   triple();
   triple(vector3 vec);
   triple(vector3 _p1, vector3 _p2, vector3 _p3);
   ~triple();

   void UpdateCenter();

   vector3 p1;
   vector3 p2;
   vector3 p3;
   vector3 center;
   vector3 position;
};
#endif