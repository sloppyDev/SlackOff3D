#ifndef SLACKOFF_MESHMANAGER
#define SLACKOFF_MESHMANAGER

#include "GLFW/glfw3.h"
#include "Mesh.h"
#include "Raster.h"
#include "../Math/vector3.h"
#include "../Math/triple.h"
#include "../Math/Rotation.h"
#include "../Math/Quaternion.h"


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class MeshManager
{
public:
   MeshManager(std::vector<std::string> meshPaths, vector3 _cameraPos, quaternion _cameraQuat);
   ~MeshManager();

   void ShadeMesh(std::vector<triple>& _mesh);
   vector3 ProjectCenter(vector3 center);

   vector3 ComputeNormal(triple tri);
   bool InView(triple tri);
   void DepthClipMesh();
   void ProjectMesh();
   void ClipMesh();
   void Clip(Mesh _mesh, vector3 planeNorm, vector3 planePoint, Mesh* outMesh);

   void Update(vector3 _cameraPos, quaternion _cameraQuat);
   void Render();

   void TransformMesh();
   vector3 GetCenter(std::vector<triple> _mesh);

private:
   Raster rasterer;

   float ang;
   std::vector<Mesh> worldMeshes;
   std::vector<Mesh> screenMeshes;
   int activeMeshIndex;

   Mesh depthClippedMesh;
   Mesh projectedMesh;
   Mesh clippedMesh;
   Mesh renderMesh;

   float zFar = (float)Engine::SCREEN_DEPTH;
   float zNear = 1.0f;

   vector3 cameraPos;
   quaternion cameraQuat;
};
#endif