#include "../Engine.h"
#include "MeshManager.h"

#include <math.h>

using namespace std;

vector3 MeshManager::ASPECT_VEC = vector3(1.0f, (float)Engine::ASPECT_RATIO, 1.0f);
vector3 MeshManager::SCALE_VEC = vector3((float)Engine::SCREEN_WIDTH, (float)Engine::SCREEN_WIDTH, (float)Engine::SCREEN_WIDTH);

MeshManager::MeshManager(vector3 _cameraPos, quaternion _cameraQuat)
{
   cameraPos = _cameraPos;
   cameraQuat = _cameraQuat;

   LoadMesh("C:/Users/Joe/Desktop/weirdSpire.obj");
   ScaleMesh(meshNames[0], 10.0f);
   TranslateBy(meshNames[0], vector3(0.0f, 0.0f, 300.0f));

      
   Raster rasterer;
   float sideLength = 50.0f;
   vector3 set1 = vector3();
   vector3 set2 = vector3();
   vector3 set3 = vector3();
   vector3 frontColor = vector3(1.0f, 0.0f, 0.0f); // red
   vector3 rightColor = vector3(1.0f, 1.0f, 0.0f); // yellow
   vector3 backColor = vector3(0.0f, 1.0f, 0.0f); // green
   vector3 bottomColor = vector3(0.0f, 1.0f, 1.0f); // cyan
   vector3 leftColor = vector3(0.0f, 0.0f, 1.0f); // blue
   vector3 topColor = vector3(1.0f, 0.0f, 1.0f); // pink
   
   //// Front 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, sideLength, 0.0f);
   //set3 = vector3(sideLength, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, frontColor));

   //// Front 2
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, 0.0f);
   //set3 = vector3(sideLength, 0.0f, 0.0f);
   //AddTri(triple(set1, set2, set3, frontColor));

   //// Right 1
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, 0.0f);
   //set3 = vector3(sideLength, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, rightColor));

   //// Right 2
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(sideLength, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, rightColor));

   //// Back 1
   //set1 = vector3(sideLength, 0.0f, sideLength);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, backColor));

   //// Back 2
   //set1 = vector3(0.0f, 0.0f, sideLength);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(0.0f, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, backColor));

   //// Bottom 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(sideLength, 0.0f, 0.0f);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, bottomColor));

   //// Bottom 2
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, 0.0f, sideLength);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, bottomColor));

   //// Left 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(0.0f, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, leftColor));

   //// Left 2
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, 0.0f, sideLength);
   //set3 = vector3(0.0f, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, leftColor));

   //// Top 1
   //set1 = vector3(0.0f, sideLength, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(sideLength, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, topColor));

   //// Top 2
   //set1 = vector3(sideLength, sideLength, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(sideLength, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, topColor));
   //AddMesh("cube");
   //TranslateBy("cube", vector3(-sideLength / 2, -sideLength / 2, 100.0f));





   //// Front 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, sideLength, 0.0f);
   //set3 = vector3(sideLength, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, frontColor));

   //// Front 2
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, 0.0f);
   //set3 = vector3(sideLength, 0.0f, 0.0f);
   //AddTri(triple(set1, set2, set3, frontColor));

   //// Right 1
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, 0.0f);
   //set3 = vector3(sideLength, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, rightColor));

   //// Right 2
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(sideLength, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, rightColor));

   //// Back 1
   //set1 = vector3(sideLength, 0.0f, sideLength);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, backColor));

   //// Back 2
   //set1 = vector3(0.0f, 0.0f, sideLength);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(0.0f, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, backColor));

   //// Bottom 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(sideLength, 0.0f, 0.0f);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, bottomColor));

   //// Bottom 2
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, 0.0f, sideLength);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, bottomColor));

   //// Left 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(0.0f, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, leftColor));

   //// Left 2
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, 0.0f, sideLength);
   //set3 = vector3(0.0f, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, leftColor));

   //// Top 1
   //set1 = vector3(0.0f, sideLength, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(sideLength, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, topColor));

   //// Top 2
   //set1 = vector3(sideLength, sideLength, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(sideLength, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, topColor));
   //AddMesh("cube2");
   //TranslateBy("cube2", vector3(-sideLength / 2, -sideLength / 2, 300.0f));





   //// Front 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, sideLength, 0.0f);
   //set3 = vector3(sideLength, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, frontColor));

   //// Front 2
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, 0.0f);
   //set3 = vector3(sideLength, 0.0f, 0.0f);
   //AddTri(triple(set1, set2, set3, frontColor));

   //// Right 1
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, 0.0f);
   //set3 = vector3(sideLength, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, rightColor));

   //// Right 2
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(sideLength, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, rightColor));

   //// Back 1
   //set1 = vector3(sideLength, 0.0f, sideLength);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, backColor));

   //// Back 2
   //set1 = vector3(0.0f, 0.0f, sideLength);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(0.0f, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, backColor));

   //// Bottom 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(sideLength, 0.0f, 0.0f);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, bottomColor));

   //// Bottom 2
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, 0.0f, sideLength);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, bottomColor));

   //// Left 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(0.0f, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, leftColor));

   //// Left 2
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, 0.0f, sideLength);
   //set3 = vector3(0.0f, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, leftColor));

   //// Top 1
   //set1 = vector3(0.0f, sideLength, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(sideLength, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, topColor));

   //// Top 2
   //set1 = vector3(sideLength, sideLength, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(sideLength, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, topColor));
   //AddMesh("cube3");
   //TranslateBy("cube3", vector3(-sideLength / 2, -sideLength / 2, 100.0f));



   //// Flat Top Triangle
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, sideLength, 0.0f);
   //set3 = vector3(sideLength, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, frontColor));
   //AddMesh("triangleFlatTop");
   //TranslateBy("triangleFlatTop", vector3((-sideLength / 2) + 100.0f, -sideLength / 2, 300.0f));

   //// Flat Bottom Triangle
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, 0.0f);
   //set3 = vector3(sideLength, 0.0f, 0.0f);
   //AddTri(triple(set1, set2, set3, rightColor));
   //AddMesh("triangleFlatBottom");
   //TranslateBy("triangleFlatBottom", vector3(-sideLength / 2, -sideLength / 2, 300.0f));

   // Pointy Top Triangle
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(sideLength/2, sideLength, 0.0f);
   //set3 = vector3(sideLength, 0.0f, 0.0f);
   //AddTri(triple(set1, set2, set3, backColor));
   //AddMesh("trianglePointTop");
   //TranslateBy("trianglePointTop", vector3((-sideLength / 2) - 100.0f, -sideLength / 2, 300.0f));

   //// Pointy Bottom Triangle
   //set1 = vector3(0.0f, sideLength, 0.0f);
   //set2 = vector3(sideLength / 2, 0.0f, 0.0f);
   //set3 = vector3(sideLength, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, bottomColor));
   //AddMesh("trianglePointBottom");
   //TranslateBy("trianglePointBottom", vector3(-sideLength / 2, (-sideLength / 2) - 100.0f, 300.0f));

   //// Pointy Right Triangle
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, sideLength, 0.0f);
   //set3 = vector3(sideLength, sideLength/2, 0.0f);
   //AddTri(triple(set1, set2, set3, leftColor));
   //AddMesh("trianglePointRight");
   //TranslateBy("trianglePointRight", vector3((-sideLength / 2) + 100.0f, (-sideLength / 2) + 100.0f, 300.0f));

   //// Weird Pointy Triangle
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(-sideLength/2, sideLength, 0.0f);
   //set3 = vector3(sideLength, -sideLength/2, 0.0f);
   //AddTri(triple(set1, set2, set3, topColor));
   //AddMesh("triangleWeirdPoint");
   //TranslateBy("triangleWeirdPoint", vector3((-sideLength / 2) - 100.0f, (-sideLength / 2) + 100.0f, 300.0f));

   TransformMesh();
}

MeshManager::~MeshManager()
{

}

bool MeshManager::LoadMesh(std::string fileName)
{
   std::ifstream f(fileName);
   if (!f.is_open())
   {
      return false;
   }
   
   std::vector<vector3> verts;

   while (!f.eof())
   {
      char line[128];
      f.getline(line, 128);

      std::stringstream ss;
      ss << line;

      char temp;

      if (line[0] == 'v')
      {
         vector3 v;
         ss >> temp >> v.x >> v.y >> v.z;
         verts.push_back(v);
      }

      if (line[0] == 'f')
      {
         int f[3];
         ss >> temp >> f[0] >> f[1] >> f[2];
         AddTri(triple(verts[f[0]-1], verts[f[1]-1], verts[f[2]-1]));
      }
   }

   fileName.pop_back();
   fileName.pop_back();
   fileName.pop_back();
   const char* meshName = fileName.c_str();
   AddMesh(meshName);
}

void MeshManager::AddMesh(const char* meshName)
{
   worldMeshes.push_back(activeMesh);
   meshNames.push_back(meshName);
   meshCenters.push_back(vector3());
   UpdateCenter(meshName);
   activeMesh.clear();
}

vector3 MeshManager::GetCenter(std::vector<triple> _mesh)
{
   float xAve{ 0.0f };
   float yAve{ 0.0f };
   float zAve{ 0.0f };
   int numTri{ 0 };

   for (auto&& tri : _mesh)
   {
      xAve += tri.center.x;
      yAve += tri.center.y;
      zAve += tri.center.z;
      numTri++;
   }

   xAve /= (float)numTri;
   yAve /= (float)numTri;
   zAve /= (float)numTri;

   return vector3(xAve, yAve, zAve);
}

void MeshManager::UpdateCenter(const char* meshName)
{
   float xAve{ 0.0f };
   float yAve{ 0.0f };
   float zAve{ 0.0f };
   int numTri{ 0 };

   vector<triple>* mesh = NULL;
   mesh = &GetMesh(meshName);
   for (auto&& tri : *mesh)
   {
      xAve += tri.center.x;
      yAve += tri.center.y;
      zAve += tri.center.z;
      numTri++;
   }
   xAve /= (float)numTri;
   yAve /= (float)numTri;
   zAve /= (float)numTri;

   GetCenter(meshName) = vector3(xAve, yAve, zAve);
}

vector<triple>& MeshManager::GetMesh(const char* meshName)
{
   unsigned int IDX{ 0 };
   for (auto i = 0; meshNames.size(); ++i)
   {
      if (meshNames[i] == meshName)
      {
         IDX = i;
         break;
      }
   }
   if (IDX < meshNames.size())
   {
      return worldMeshes[IDX];
   }
   else
   {
      return worldMeshes[0];
   }
}

vector3& MeshManager::GetCenter(const char* meshName)
{
   unsigned int IDX{ 0 };
   for (auto i = 0; meshNames.size(); ++i)
   {
      if (meshNames[i] == meshName)
      {
         IDX = i;
         break;
      }
   }
   if (IDX < meshNames.size())
   {
      return meshCenters[IDX];
   }
   else
   {
      return meshCenters[0];
   }
}

void MeshManager::AddTri(triple in)          
{
   activeMesh.push_back(in);
}

void MeshManager::TranslateBy(const char* meshName, vector3 translateVec)
{
   vector<triple>* mesh = NULL;
   mesh = &GetMesh(meshName);
   for (auto&& tri : *mesh)
   {
      tri = tri + translateVec;
   }
   UpdateCenter(meshName);
}

vector3 MeshManager::ProjectCenter(vector3 center)
{
   vector3 projectedCenter;
   float fFov = 1 / tan(Rotation::DegToRad(Engine::FOV) / 2);
   float x = center.x;
   float y = center.y;
   float z = center.z;
   x = x * (fFov / z);
   y = Engine::ASPECT_RATIO * y * (fFov / z);
   z = z * (-zFar / (zFar - zNear)) - ((zFar * zNear) / (zFar - zNear));
   projectedCenter = vector3(x, y, z);

   return projectedCenter;
}

std::vector<triple> MeshManager::ProjectMesh(vector<triple> _mesh)
{
   std::vector<triple> projectedMesh;
   float x{};
   float y{};
   float z{};

   for (auto&& tri : _mesh)
   {
      float fFov = 1 / tan(Rotation::DegToRad(Engine::FOV) / 2);
      triple projectedTri;
      // P1
      x = tri.p1.x;
      y = tri.p1.y;
      z = tri.p1.z;
      x = x * (fFov / z);
      y = Engine::ASPECT_RATIO * y * (fFov / z);
      z = z * (-zFar / (zFar - zNear)) - ((zFar * zNear) / (zFar - zNear));
      projectedTri.p1 = vector3(x, y, z);

      // P2
      x = tri.p2.x;
      y = tri.p2.y;
      z = tri.p2.z;
      x = x*(fFov / z);
      y = Engine::ASPECT_RATIO * y*(fFov / z);
      z = z*(-zFar / (zFar - zNear)) - ((zFar * zNear) / (zFar - zNear));
      projectedTri.p2 = vector3(x, y, z);

      // P3
      x = tri.p3.x;
      y = tri.p3.y;
      z = tri.p3.z;
      x = x*(fFov / z);
      y = Engine::ASPECT_RATIO * y * (fFov / z);
      z = z*(-zFar / (zFar - zNear)) - ((zFar * zNear) / (zFar - zNear));
      projectedTri.p3 = vector3(x, y, z);
      projectedTri.UpdateCenter();
      projectedTri.color = tri.color;
      projectedMesh.push_back(projectedTri);
   }
   return projectedMesh;
}

std::vector<triple> MeshManager::ScaleMesh(vector<triple> _mesh, float mult)
{
   std::vector<triple> scaledMesh;

   for (auto&& tri : _mesh)
   {
      scaledMesh.push_back(tri*mult);
   }
   return scaledMesh;
}

void MeshManager::ScaleMesh(const char* meshName, float mult)
{
   for (auto&& tri : GetMesh(meshName))
   {
      tri = tri * mult;
   }
   UpdateCenter(meshName);
}
void MeshManager::RotateBy(const char* meshName, vector3 rotVec)
{
   for (auto&& tri : GetMesh(meshName))
   {
      tri = Rotation::Rotate(tri, 1, rotVec.x);
      tri = Rotation::Rotate(tri, 2, rotVec.y);
      tri = Rotation::Rotate(tri, 3, rotVec.z);
   }
   UpdateCenter(meshName);
}

void MeshManager::RotateBy(const char* meshName, vector3 rotVec, vector3 rotPoint)
{
   vector<triple>* mesh = NULL;
   mesh = &GetMesh(meshName);
   for (auto&& tri : *mesh)
   {
      tri = Rotation::Rotate(tri, 1, rotVec.x, rotPoint);
      tri = Rotation::Rotate(tri, 2, rotVec.y, rotPoint);
      tri = Rotation::Rotate(tri, 3, rotVec.z, rotPoint);
   }
   UpdateCenter(meshName);
}

vector3 MeshManager::ComputeNormal(triple tri)
{
   vector3 lineA = tri.p1 - tri.p2;
   vector3 lineB = tri.p3 - tri.p2;

   vector3 normal = vector3::Normalize(vector3::Cross(lineA, lineB));
   
   return normal;
}

bool MeshManager::InView(triple tri)
{
   vector3 normal = ComputeNormal(tri);
   vector3 cameraLine = vector3::Normalize(tri.center);
   if (vector3::Dot(cameraLine, normal) < 0)
   {
      return true;
   }
   return false;
}

void MeshManager::ShadeMesh(std::vector<triple>& _mesh)
{
   float luminance{ 0 };
   for (auto&& tri : _mesh)
   {
      vector3 normal = ComputeNormal(tri);
      vector3 lightLine = vector3::Normalize(tri.center);
      
      luminance = -vector3::Dot(normal, lightLine)*10;
      tri.color = vector3(luminance);
   }
}

std::vector<triple> MeshManager::DepthClipMesh(std::vector<triple> _mesh)
{
   std::vector<triple> clippedMesh;
   float signSum{};
   triple clippedTri1;
   triple clippedTri2;
   vector3 zNorm(0.0f, 0.0f, 1.0f);
   vector3 zPoint(0.0f, 0.0f, zNear);

   for (auto&& tri : _mesh)
   {
      float zCheckP1 = tri.p1.z - zNorm.z;
      float zCheckP2 = tri.p2.z - zNorm.z;
      float zCheckP3 = tri.p3.z - zNorm.z;
      float zCheckP1Sign = (zCheckP1 / abs(zCheckP1));
      float zCheckP2Sign = (zCheckP2 / abs(zCheckP2));
      float zCheckP3Sign = (zCheckP3 / abs(zCheckP3));

      signSum = zCheckP1Sign + zCheckP2Sign + zCheckP3Sign;

      if (signSum == 3)
      {
         clippedMesh.push_back(tri);
      }
      else if (signSum > -3 && signSum < 3)
      {
         if (zCheckP1Sign > 0)
         {
            if (zCheckP2Sign < 0 && zCheckP3Sign < 0) // 2 New Points from P1
            {
               clippedTri1.p1 = tri.p1;

               // P1 to P2
               vector3 lineVec = (tri.p2 - tri.p1);
               lineVec.Normalize();

               float lineProportion = (vector3::Dot((zPoint - tri.p1), zNorm)) / vector3::Dot(lineVec, zNorm);
               clippedTri1.p2 = lineVec * lineProportion + tri.p1;

               // P1 to P3
               lineVec = (tri.p3 - tri.p1);
               lineVec.Normalize();

               lineProportion = (vector3::Dot((zPoint - tri.p1), zNorm)) / vector3::Dot(lineVec, zNorm);
               clippedTri1.p3 = lineVec * lineProportion + tri.p1;
               clippedMesh.push_back(clippedTri1);
            }
            else if (zCheckP2Sign > 0 && zCheckP3Sign < 0) // 2 New Triangles with P1 and P2
            {
               clippedTri1.p1 = tri.p1;
               clippedTri1.p2 = tri.p2;
               clippedTri2.p1 = tri.p1;

               // P2 to NewTri1P3
               vector3 lineVec = (tri.p2 - tri.p1);
               lineVec.Normalize();

               float lineProportion = (vector3::Dot((zPoint - tri.p2), zNorm)) / vector3::Dot(lineVec, zNorm);
               clippedTri1.p3 = lineVec * lineProportion + tri.p2;
               clippedTri2.p2 = clippedTri1.p3;

               // P1 to NewTri2P2
               lineVec = (tri.p3 - tri.p1);
               lineVec.Normalize();

               lineProportion = (vector3::Dot((zPoint - tri.p1), zNorm)) / vector3::Dot(lineVec, zNorm);
               clippedTri2.p3 = lineVec * lineProportion + tri.p1;

               clippedMesh.push_back(clippedTri1);
               clippedMesh.push_back(clippedTri2);
            }
            else if (zCheckP3Sign > 0 && zCheckP2Sign < 0) // 2 New Triangles with P1 and P3
            {
               clippedTri1.p1 = tri.p1;
               clippedTri1.p3 = tri.p3;
               clippedTri2.p1 = tri.p1;

               // P3 to NewTri1P2
               vector3 lineVec = (tri.p2 - tri.p3);
               lineVec.Normalize();

               float lineProportion = (vector3::Dot((zPoint - tri.p3), zNorm)) / vector3::Dot(lineVec, zNorm);
               clippedTri1.p2 = lineVec * lineProportion + tri.p3;
               clippedTri2.p3 = clippedTri1.p3;

               // P1 to NewTri2P2
               lineVec = (tri.p2 - tri.p1);
               lineVec.Normalize();

               lineProportion = (vector3::Dot((zPoint - tri.p1), zNorm)) / vector3::Dot(lineVec, zNorm);
               clippedTri2.p2 = lineVec * lineProportion + tri.p1;

               clippedMesh.push_back(clippedTri1);
               clippedMesh.push_back(clippedTri2);
            }
         }

         if (zCheckP2Sign > 0)
         {
            if (zCheckP1Sign < 0 && zCheckP3Sign < 0) // 2 New Points from P2
            {
               clippedTri1.p2 = tri.p2;

               // P2 to P1
               vector3 lineVec = (tri.p1 - tri.p2);
               lineVec.Normalize();

               float lineProportion = (vector3::Dot((zPoint - tri.p2), zNorm)) / vector3::Dot(lineVec, zNorm);
               clippedTri1.p1 = lineVec * lineProportion + tri.p2;

               // P2 to P3
               lineVec = (tri.p3 - tri.p2);
               lineVec.Normalize();

               lineProportion = (vector3::Dot((zPoint - tri.p2), zNorm)) / vector3::Dot(lineVec, zNorm);
               clippedTri1.p3 = lineVec * lineProportion + tri.p2;
               clippedMesh.push_back(clippedTri1);
            }
         }
         if (zCheckP3Sign > 0)
         {
            if (zCheckP1Sign < 0 && zCheckP3Sign < 0) // 2 New Points from P3
            {
               clippedTri1.p3 = tri.p3;

               // P3 to P1
               vector3 lineVec = (tri.p1 - tri.p3);
               lineVec.Normalize();

               float lineProportion = (vector3::Dot((zPoint - tri.p3), zNorm)) / vector3::Dot(lineVec, zNorm);
               clippedTri1.p1 = lineVec * lineProportion + tri.p3;

               // P2 to P3
               lineVec = (tri.p2 - tri.p3);
               lineVec.Normalize();

               lineProportion = (vector3::Dot((zPoint - tri.p3), zNorm)) / vector3::Dot(lineVec, zNorm);
               clippedTri1.p2 = lineVec * lineProportion + tri.p3;
               clippedMesh.push_back(clippedTri1);
            }
         }
      }
      else
      {
         clippedMesh.push_back(tri);
      }

   }

   return clippedMesh;
}

void MeshManager::Update(vector3 _cameraPos, quaternion _cameraQuat)
{
   cameraPos = _cameraPos;
   cameraQuat = _cameraQuat;

   TransformMesh();
   vector3 meshCenter = GetCenter(screenMeshes[0]);

   std::cout << "\rPOS: X: " << cameraPos.x << ", Y: " << cameraPos.y << ", Z: " << cameraPos.z << "                                                  " << std::endl;
   std::cout << "WORLD SPACE MESH CENTER: X: " << meshCenters[0].x << ", Y: " << meshCenters[0].y << ", Z: " << meshCenters[0].z << "                                                 " << std::endl;
   std::cout << "SCREEN SPACE MESH CENTER: X: " << meshCenter.x << ", Y: " << meshCenter.y << ", Z: " << meshCenter.z << "                                                 " << std::endl;
   std::cout << "QUAT: R: " << cameraQuat.r << ", X: " << cameraQuat.v.x << ", Y: " << cameraQuat.v.y << ", Z: " << cameraQuat.v.z << "                                             " << "\x1b[A\x1b[A\x1b[A";



   //vector3 angVel = vector3(20.0f, 20.0f, -20.0f);
   //vector3 angVel2 = vector3(-20.0f, -20.0f, 20.0f);
   //float dt = Engine::dt;
   //vector3 rotVec = angVel * dt;
   //vector3 rotVec2 = angVel2 * dt;

   //const char* meshName = meshNames[0];
   //RotateBy(meshName, rotVec, GetCenter(meshName));
   //meshName = meshNames[1];
   //RotateBy(meshName, rotVec, GetCenter(meshName));
   //meshName = meshNames[2];
   //RotateBy(meshName, rotVec, GetCenter(meshName));
   //meshName = meshNames[3];
   //RotateBy(meshName, rotVec, GetCenter(meshName));
   //meshName = meshNames[4];
   //RotateBy(meshName, rotVec, GetCenter(meshName));
   //const char* meshName = "cube";
   //RotateBy(meshName, rotVec, GetCenter(meshName));
   //meshName = "cube2";
   //RotateBy(meshName, rotVec2, GetCenter(meshName));
   //meshName = "cube3";
   //RotateBy(meshName, rotVec, GetCenter(meshName));
   //TranslateBy(meshName, vector3(0.0f, 0.0f, 0.1f));
}

void MeshManager::Render()
{
   std::vector<triple> depthClippedMesh;
   std::vector<triple> projectedMesh;
   vector3 projectedCenter;
   std::vector<triple> clippedMesh;

   int count = 0;
   for (auto&& mesh : screenMeshes)
   {
      std::vector<triple> toRender;
      //depthClippedMesh = DepthClipMesh(mesh);
      projectedMesh = ProjectMesh(mesh);
      projectedCenter = ProjectCenter(meshCenters[count]);

      for (auto&& tri : projectedMesh)
      {
         if (InView(tri))
         {
            toRender.push_back(tri);
         }
      }
      ShadeMesh(toRender);
      
      std::sort(toRender.begin(), toRender.end(), [](triple& tri1, triple& tri2)
         {
            return (tri2.center.z > tri1.center.z);
         });

      for (auto&& tri : toRender)
      {
         rasterer.DrawTriangle(tri, false);
      }
   }

}

void MeshManager::TransformMesh()
{
   screenMeshes.clear();
   triple tempTri;
   for (auto&& mesh : worldMeshes)
   {
      std::vector<triple> newMesh;
      for (auto&& tri : mesh)
      {
         tempTri = tri - cameraPos;
         tempTri = Rotation::Rotate(tempTri, cameraQuat, 1);

         tempTri.color = tri.color;
         tempTri.UpdateCenter();
         newMesh.push_back(tempTri);
      }
      screenMeshes.push_back(newMesh);
   }
}