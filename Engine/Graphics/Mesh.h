#ifndef SLACKOFF_MESH
#define SLACKOFF_MESH

#include "../Math/vector3.h"
#include "../Math/triple.h"
#include "../Math/Rotation.h"
#include "../Math/quaternion.h"

#include <vector>
#include <fstream>
#include <sstream>

class Mesh
{
public:
   Mesh();
   Mesh(const char* meshName);
   Mesh(std::string _objPath);
   Mesh(std::string _objPath, vector3 initialTranslation);
   Mesh(std::string _objPath, vector3 initialTranslation, vector3 initialRotation);
   ~Mesh();

   void Translate(vector3 translateVec);
   void Rotate(vector3 rotVec);
   void Rotate(vector3 rotVec, vector3 rotPoint);
   void Scale(float mult);

public:
   std::string name;

   std::vector<triple> tris;
   vector3 center;
   quaternion quat;

private:
   bool LoadMesh();
   void AddTri(triple tri);
   void UpdateCenter();

private:
   std::string objPath;

};
#endif
