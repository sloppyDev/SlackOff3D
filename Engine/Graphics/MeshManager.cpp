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

   LoadMesh("C:/Users/Joe/Desktop/untitled.obj");
   //ScaleMesh(meshNames[0], 10.0f);
   //TranslateBy(meshNames[0], vector3(0.0f, 0.0f, 300.0f));

      
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
      vector3 lightLine = vector3::Normalize(tri.center - vector3(0.0f, 3000.0f, 700.0f));
      
      luminance = -vector3::Dot(normal, lightLine)*10;
      tri.color = vector3(luminance);
   }
}

std::vector<triple> MeshManager::Clip(std::vector<triple> _mesh, vector3 planeNorm, vector3 planePoint)
{
   std::vector<triple> clippedMesh;
   float signSum{};
   triple clippedTri1;
   triple clippedTri2;

   for (auto&& tri : _mesh)
   {
      float checkP1 = vector3::Dot(planeNorm, tri.p1 - planePoint);
      float checkP2 = vector3::Dot(planeNorm, tri.p2 - planePoint);
      float checkP3 = vector3::Dot(planeNorm, tri.p3 - planePoint);
      float checkP1Sign = (checkP1 / abs(checkP1));
      float checkP2Sign = (checkP2 / abs(checkP2));
      float checkP3Sign = (checkP3 / abs(checkP3));
      vector<float> checkVec;
      vector<vector3> pointsVec;
      checkVec.push_back(checkP1);
      checkVec.push_back(checkP2);
      checkVec.push_back(checkP3);
      pointsVec.push_back(tri.p1);
      pointsVec.push_back(tri.p2);
      pointsVec.push_back(tri.p3);

      signSum = checkP1Sign + checkP2Sign + checkP3Sign;

      if (signSum == 3)
      {
         clippedMesh.push_back(tri);
      }
      else if (signSum == -3)
      {

      }
      else if (signSum == 1) // Create a Quad
      {
         int minIdx = min_element(checkVec.begin(), checkVec.end()) - checkVec.begin();
         vector3 outPoint = pointsVec[minIdx];
         vector3 t1p1 = pointsVec[(minIdx - 1 + 3) % 3];
         vector3 t1p2;  // intersect of t1p1 and outpoint with plane
         vector3 t1p3 = pointsVec[(minIdx + 1) % 3];
         vector3 t2p1 = t1p3;
         vector3 t2p2 = t1p2; // intersect of t1p1 and outpoint with plane
         vector3 t2p3; // intersect of t2p1 and outpoint with plane

         // Triangle 1
         vector3 lineVec = (outPoint - t1p1);
         lineVec.Normalize();

         float lineProportion = (vector3::Dot((planePoint - t1p1), planeNorm)) / vector3::Dot(lineVec, planeNorm);
         t1p2 = lineVec * lineProportion + t1p1;
         t2p2 = t1p2;

         clippedTri1.p1 = t1p1;
         clippedTri1.p2 = t1p2;
         clippedTri1.p3 = t1p3;
         clippedTri1.UpdateCenter();
         //clippedTri1.color = vector3(1, 0, 0);
         clippedTri1.color = tri.color;

         // Triangle 2
         lineVec = (outPoint - t2p1);
         lineVec.Normalize();

         lineProportion = (vector3::Dot((planePoint - t2p1), planeNorm)) / vector3::Dot(lineVec, planeNorm);
         t2p3 = lineVec * lineProportion + t2p1;

         clippedTri2.p1 = t2p1;
         clippedTri2.p2 = t2p2;
         clippedTri2.p3 = t2p3;
         clippedTri2.UpdateCenter();
         //clippedTri2.color = vector3(0, 1, 0);
         clippedTri2.color = tri.color;
         clippedMesh.push_back(clippedTri1);
         clippedMesh.push_back(clippedTri2);
      }
      else // Create single new triangle
      {
         int maxIdx = max_element(checkVec.begin(), checkVec.end()) - checkVec.begin();
         vector3 inPoint = pointsVec[maxIdx];
         vector3 outPoint1 = pointsVec[(maxIdx + 1) % 3];
         vector3 outPoint2 = pointsVec[(maxIdx + 2) % 3];
         vector3 t1p1 = inPoint;
         vector3 t1p2;  // intersect of t1p1 and outpoint1 with plane
         vector3 t1p3;  // Intersect of t1p1 and outpoint2 with plan

         // Line 1
         vector3 lineVec = (outPoint1 - t1p1);
         lineVec.Normalize();

         float lineProportion = (vector3::Dot((planePoint - t1p1), planeNorm)) / vector3::Dot(lineVec, planeNorm);
         t1p2 = lineVec * lineProportion + t1p1;

         // Line 2
         lineVec = (outPoint2 - t1p1);
         lineVec.Normalize();

         lineProportion = (vector3::Dot((planePoint - t1p1), planeNorm)) / vector3::Dot(lineVec, planeNorm);
         t1p3 = lineVec * lineProportion + t1p1;

         clippedTri1.p1 = t1p1;
         clippedTri1.p2 = t1p2;
         clippedTri1.p3 = t1p3;
         clippedTri1.UpdateCenter();
         //clippedTri1.color = vector3(0, 0, 1);
         clippedTri1.color = tri.color;

         clippedMesh.push_back(clippedTri1);
      }
   }
   return clippedMesh;
}

std::vector<triple> MeshManager::DepthClipMesh(std::vector<triple> _mesh)
{
   vector3 zPlaneNorm(0.0f, 0.0f, 1.0f);
   vector3 zPoint(0.0f, 0.0f, zNear);

   std::vector<triple> clippedMesh = Clip(_mesh, zPlaneNorm, zPoint);
   return clippedMesh;
}

std::vector<triple> MeshManager::ClipMesh(std::vector<triple> _mesh)
{
   vector3 rightPlaneNorm(-1.0f, 0.0f, 0.0f);
   vector3 topPlaneNorm(0.0f, -1.0f, 0.0f);
   vector3 leftPlaneNorm(1.0f, 0.0f, 0.0f);
   vector3 bottomPlaneNorm(0.0f, 1.0f, 0.0f);

   vector3 rightPlanePoint(1.0f, 0.0f, 0.0f);
   vector3 topPlanePoint(0.0f, 1.0f, 0.0f);
   vector3 leftPlanePoint(-1.0f, 0.0f, 0.0f);
   vector3 bottomPlanePoint(0.0f, -1.0f, 0.0f);

   std::vector<triple> clippedMesh = Clip(_mesh, rightPlaneNorm, rightPlanePoint); // Right Plane
   clippedMesh = Clip(clippedMesh, topPlaneNorm, topPlanePoint); // Top Plane
   clippedMesh = Clip(clippedMesh, leftPlaneNorm, leftPlanePoint); // Left Plane
   clippedMesh = Clip(clippedMesh, bottomPlaneNorm, bottomPlanePoint); // Bottom Plane

   return clippedMesh;
}

void MeshManager::Update(vector3 _cameraPos, quaternion _cameraQuat)
{
   cameraPos = _cameraPos;
   cameraQuat = _cameraQuat;

   TransformMesh();
   vector3 meshCenter = GetCenter(screenMeshes[0]);

   /*std::cout << "\rPOS: X: " << cameraPos.x << ", Y: " << cameraPos.y << ", Z: " << cameraPos.z << "                                                  " << std::endl;
   std::cout << "WORLD SPACE MESH CENTER: X: " << meshCenters[0].x << ", Y: " << meshCenters[0].y << ", Z: " << meshCenters[0].z << "                                                 " << std::endl;
   std::cout << "SCREEN SPACE MESH CENTER: X: " << meshCenter.x << ", Y: " << meshCenter.y << ", Z: " << meshCenter.z << "                                                 " << std::endl;
   std::cout << "QUAT: R: " << cameraQuat.r << ", X: " << cameraQuat.v.x << ", Y: " << cameraQuat.v.y << ", Z: " << cameraQuat.v.z << "                                             " << "\x1b[A\x1b[A\x1b[A";
*/


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
   std::vector<triple> clippedMesh;

   int count = 0;
   for (auto&& mesh : screenMeshes)
   {
      std::vector<triple> toRender;
      depthClippedMesh = DepthClipMesh(mesh);
      projectedMesh = ProjectMesh(depthClippedMesh);
      clippedMesh = ClipMesh(projectedMesh);

      for (auto&& tri : clippedMesh)
      {
         if (InView(tri))
         {
            toRender.push_back(tri);
         }
      }
      //ShadeMesh(toRender);
      
      std::sort(toRender.begin(), toRender.end(), [](triple& tri1, triple& tri2)
         {
            return (tri2.center.z > tri1.center.z);
         });

      for (auto&& tri : toRender)
      {
         rasterer.DrawTriangle(tri, true);
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