#ifndef SLACKOFF_TRIANGLE
#define SLACKOFF_TRIANGLE

#include "GLFW/glfw3.h"
#include "../Math/vector3.h"
#include "../Math/triple.h"

#include <iostream>

#define PI 3.14159

class Triangle
{
public:
   Triangle();
   ~Triangle();

   void SetPoints(vector3 set1, vector3 set2, vector3 set3);
   void RotateTo(float rad);

   void Update();
   void Render();
   void Render(int color1, int color2, int color3);

private:
   float ang;
   triple points;
};
#endif