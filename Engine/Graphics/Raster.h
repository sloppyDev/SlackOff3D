#ifndef SLACKOFF_RASTER
#define SLACKOFF_RASTER

#include "GLFW/glfw3.h"
#include "../Engine.h"
#include "../Math/triple.h"
#include "../Math/vector3.h"

#include <vector>
#include <algorithm>

class Raster
{
public:
   Raster();
   ~Raster();

   void DrawTriangle(triple tri, bool wireFrame);

private:
   float GetIntercept(float y, vector3 p1, vector3 p2);
   float GetSlope(vector3 p1, vector3 p2);
   void DrawPoint(vector3 point);
   void DrawLine(vector3 p1, vector3 p2);
   void DrawWireframe(triple tri);
   vector3 color;

   float xPixelIncrement{ 2 / (float)Engine::SCREEN_WIDTH };
   float yPixelIncrement{ 2 / (float)Engine::SCREEN_HEIGHT };

};
#endif