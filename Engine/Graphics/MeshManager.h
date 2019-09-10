#ifndef SLACKOFF_MESHMANAGER
#define SLACKOFF_MESHMANAGER

#include "GLFW/glfw3.h"
#include "../Math/vector3.h"
#include "../Math/triple.h"

#include <iostream>
#include <vector>

#define PI 3.14159

class MeshManager
{
public:
   MeshManager();
   ~MeshManager();

   void AddTri(triple in);
   void RotateTo(float rad);

   void Update();
   void Render();
   void Render(int color1, int color2, int color3);

private:
   float ang;
   std::vector<triple> mesh;
};
#endif