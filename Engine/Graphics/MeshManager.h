#ifndef SLACKOFF_MESHMANAGER
#define SLACKOFF_MESHMANAGER

#include "GLFW/glfw3.h"
#include "../Math/vector3.h"
#include "../Math/triple.h"
#include "../Math/Rotation.h"

#include <iostream>
#include <vector>

class MeshManager
{
public:
   MeshManager();
   ~MeshManager();

   void AddTri(triple in);
   std::vector<triple> ScaleMesh();
   void RotateBy(float rad);
   vector3 ComputeNormal(triple tri);
   bool InView(triple tri);

   void Update();
   void Render();

private:
   static vector3 SCALE_VEC;
   static vector3 ASPECT_VEC;
   float ang;
   std::vector<triple> mesh;
};
#endif