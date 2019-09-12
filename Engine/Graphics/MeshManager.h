#ifndef SLACKOFF_MESHMANAGER
#define SLACKOFF_MESHMANAGER

#include "GLFW/glfw3.h"
#include "../Math/vector3.h"
#include "../Math/triple.h"
#include "../Math/Rotation.h"
#include "Raster.h"

#include <iostream>
#include <vector>

class MeshManager
{
public:
   MeshManager();
   ~MeshManager();

   void ShadeMesh(std::vector<triple>& _mesh);
   void AddMesh(const char* meshName);
   void UpdateCenter(const char* meshName);
   std::vector<triple>& GetMesh(const char* meshName);
   vector3& GetCenter(const char* meshName);
   void AddTri(triple in);
   void TranslateBy(const char* meshName, vector3 translateVec);
   vector3 ProjectCenter(vector3 center);
   std::vector<triple> ProjectMesh(std::vector<triple> _mesh);
   std::vector<triple> ScaleMesh(std::vector<triple> _mesh);
   void RotateBy(const char* meshName, vector3 rotVec);
   void RotateBy(const char* meshName, vector3 rotVec, vector3 rotPoint);
   vector3 ComputeNormal(triple tri);
   bool InView(triple tri);

   void Update();
   void Render();

private:
   Raster rasterer;
   static vector3 SCALE_VEC;
   static vector3 ASPECT_VEC;
   float ang;
   std::vector<triple> activeMesh;
   std::vector<std::vector<triple>> meshes;
   std::vector<const char*> meshNames;
   std::vector<vector3> meshCenters;
   float zFar = (float)Engine::SCREEN_DEPTH;
   float zNear = 1.0f;
};
#endif