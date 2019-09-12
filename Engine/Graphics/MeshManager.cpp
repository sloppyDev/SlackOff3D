#include "../Engine.h"
#include "MeshManager.h"

#include <math.h>

using namespace std;

vector3 MeshManager::ASPECT_VEC = vector3(1.0f, (float)Engine::ASPECT_RATIO, 1.0f);
vector3 MeshManager::SCALE_VEC = vector3((float)Engine::SCREEN_WIDTH, (float)Engine::SCREEN_WIDTH, (float)Engine::SCREEN_WIDTH);

MeshManager::MeshManager()
{
   float sideLength = 50.0f;
   vector3 frontColor = vector3(1.0f, 0.0f, 0.0f); // red
   vector3 rightColor = vector3(1.0f, 1.0f, 0.0f); // yellow
   vector3 backColor = vector3(0.0f, 1.0f, 0.0f); // green
   vector3 bottomColor = vector3(0.0f, 1.0f, 1.0f); // cyan
   vector3 leftColor = vector3(0.0f, 0.0f, 1.0f); // blue
   vector3 topColor = vector3(1.0f, 0.0f, 1.0f); // pink
   
   // Front 1
   vector3 set1 = vector3(0.0f, 0.0f, 0.0f);
   vector3 set2 = vector3(0.0f, sideLength, 0.0f);
   vector3 set3 = vector3(sideLength, sideLength, 0.0f);
   AddTri(triple(set1, set2, set3, frontColor));

   // Front 2
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(sideLength, sideLength, 0.0f);
   set3 = vector3(sideLength, 0.0f, 0.0f);
   AddTri(triple(set1, set2, set3, frontColor));

   // Right 1
   set1 = vector3(sideLength, 0.0f, 0.0f);
   set2 = vector3(sideLength, sideLength, 0.0f);
   set3 = vector3(sideLength, sideLength, sideLength);
   AddTri(triple(set1, set2, set3, rightColor));

   // Right 2
   set1 = vector3(sideLength, 0.0f, 0.0f);
   set2 = vector3(sideLength, sideLength, sideLength);
   set3 = vector3(sideLength, 0.0f, sideLength);
   AddTri(triple(set1, set2, set3, rightColor));

   // Back 1
   set1 = vector3(sideLength, 0.0f, sideLength);
   set2 = vector3(sideLength, sideLength, sideLength);
   set3 = vector3(0.0f, 0.0f, sideLength);
   AddTri(triple(set1, set2, set3, backColor));

   // Back 2
   set1 = vector3(0.0f, 0.0f, sideLength);
   set2 = vector3(sideLength, sideLength, sideLength);
   set3 = vector3(0.0f, sideLength, sideLength);
   AddTri(triple(set1, set2, set3, backColor));

   // Bottom 1
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(sideLength, 0.0f, 0.0f);
   set3 = vector3(0.0f, 0.0f, sideLength);
   AddTri(triple(set1, set2, set3, bottomColor));

   // Bottom 2
   set1 = vector3(sideLength, 0.0f, 0.0f);
   set2 = vector3(sideLength, 0.0f, sideLength);
   set3 = vector3(0.0f, 0.0f, sideLength);
   AddTri(triple(set1, set2, set3, bottomColor));

   // Left 1
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(0.0f, sideLength, sideLength);
   set3 = vector3(0.0f, sideLength, 0.0f);
   AddTri(triple(set1, set2, set3, leftColor));

   // Left 2
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(0.0f, 0.0f, sideLength);
   set3 = vector3(0.0f, sideLength, sideLength);
   AddTri(triple(set1, set2, set3, leftColor));

   // Top 1
   set1 = vector3(0.0f, sideLength, 0.0f);
   set2 = vector3(0.0f, sideLength, sideLength);
   set3 = vector3(sideLength, sideLength, 0.0f);
   AddTri(triple(set1, set2, set3, topColor));

   // Top 2
   set1 = vector3(sideLength, sideLength, 0.0f);
   set2 = vector3(0.0f, sideLength, sideLength);
   set3 = vector3(sideLength, sideLength, sideLength);
   AddTri(triple(set1, set2, set3, topColor));
   AddMesh("cube");
   TranslateBy("cube", vector3(-sideLength / 2, -sideLength / 2, 500.0f));





   // Front 1
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(0.0f, sideLength, 0.0f);
   set3 = vector3(sideLength, sideLength, 0.0f);
   AddTri(triple(set1, set2, set3, frontColor));

   // Front 2
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(sideLength, sideLength, 0.0f);
   set3 = vector3(sideLength, 0.0f, 0.0f);
   AddTri(triple(set1, set2, set3, frontColor));

   // Right 1
   set1 = vector3(sideLength, 0.0f, 0.0f);
   set2 = vector3(sideLength, sideLength, 0.0f);
   set3 = vector3(sideLength, sideLength, sideLength);
   AddTri(triple(set1, set2, set3, rightColor));

   // Right 2
   set1 = vector3(sideLength, 0.0f, 0.0f);
   set2 = vector3(sideLength, sideLength, sideLength);
   set3 = vector3(sideLength, 0.0f, sideLength);
   AddTri(triple(set1, set2, set3, rightColor));

   // Back 1
   set1 = vector3(sideLength, 0.0f, sideLength);
   set2 = vector3(sideLength, sideLength, sideLength);
   set3 = vector3(0.0f, 0.0f, sideLength);
   AddTri(triple(set1, set2, set3, backColor));

   // Back 2
   set1 = vector3(0.0f, 0.0f, sideLength);
   set2 = vector3(sideLength, sideLength, sideLength);
   set3 = vector3(0.0f, sideLength, sideLength);
   AddTri(triple(set1, set2, set3, backColor));

   // Bottom 1
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(sideLength, 0.0f, 0.0f);
   set3 = vector3(0.0f, 0.0f, sideLength);
   AddTri(triple(set1, set2, set3, bottomColor));

   // Bottom 2
   set1 = vector3(sideLength, 0.0f, 0.0f);
   set2 = vector3(sideLength, 0.0f, sideLength);
   set3 = vector3(0.0f, 0.0f, sideLength);
   AddTri(triple(set1, set2, set3, bottomColor));

   // Left 1
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(0.0f, sideLength, sideLength);
   set3 = vector3(0.0f, sideLength, 0.0f);
   AddTri(triple(set1, set2, set3, leftColor));

   // Left 2
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(0.0f, 0.0f, sideLength);
   set3 = vector3(0.0f, sideLength, sideLength);
   AddTri(triple(set1, set2, set3, leftColor));

   // Top 1
   set1 = vector3(0.0f, sideLength, 0.0f);
   set2 = vector3(0.0f, sideLength, sideLength);
   set3 = vector3(sideLength, sideLength, 0.0f);
   AddTri(triple(set1, set2, set3, topColor));

   // Top 2
   set1 = vector3(sideLength, sideLength, 0.0f);
   set2 = vector3(0.0f, sideLength, sideLength);
   set3 = vector3(sideLength, sideLength, sideLength);
   AddTri(triple(set1, set2, set3, topColor));
   AddMesh("cube2");
   TranslateBy("cube2", vector3(-sideLength / 2, -sideLength / 2, 300.0f));





   // Front 1
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(0.0f, sideLength, 0.0f);
   set3 = vector3(sideLength, sideLength, 0.0f);
   AddTri(triple(set1, set2, set3, frontColor));

   // Front 2
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(sideLength, sideLength, 0.0f);
   set3 = vector3(sideLength, 0.0f, 0.0f);
   AddTri(triple(set1, set2, set3, frontColor));

   // Right 1
   set1 = vector3(sideLength, 0.0f, 0.0f);
   set2 = vector3(sideLength, sideLength, 0.0f);
   set3 = vector3(sideLength, sideLength, sideLength);
   AddTri(triple(set1, set2, set3, rightColor));

   // Right 2
   set1 = vector3(sideLength, 0.0f, 0.0f);
   set2 = vector3(sideLength, sideLength, sideLength);
   set3 = vector3(sideLength, 0.0f, sideLength);
   AddTri(triple(set1, set2, set3, rightColor));

   // Back 1
   set1 = vector3(sideLength, 0.0f, sideLength);
   set2 = vector3(sideLength, sideLength, sideLength);
   set3 = vector3(0.0f, 0.0f, sideLength);
   AddTri(triple(set1, set2, set3, backColor));

   // Back 2
   set1 = vector3(0.0f, 0.0f, sideLength);
   set2 = vector3(sideLength, sideLength, sideLength);
   set3 = vector3(0.0f, sideLength, sideLength);
   AddTri(triple(set1, set2, set3, backColor));

   // Bottom 1
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(sideLength, 0.0f, 0.0f);
   set3 = vector3(0.0f, 0.0f, sideLength);
   AddTri(triple(set1, set2, set3, bottomColor));

   // Bottom 2
   set1 = vector3(sideLength, 0.0f, 0.0f);
   set2 = vector3(sideLength, 0.0f, sideLength);
   set3 = vector3(0.0f, 0.0f, sideLength);
   AddTri(triple(set1, set2, set3, bottomColor));

   // Left 1
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(0.0f, sideLength, sideLength);
   set3 = vector3(0.0f, sideLength, 0.0f);
   AddTri(triple(set1, set2, set3, leftColor));

   // Left 2
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(0.0f, 0.0f, sideLength);
   set3 = vector3(0.0f, sideLength, sideLength);
   AddTri(triple(set1, set2, set3, leftColor));

   // Top 1
   set1 = vector3(0.0f, sideLength, 0.0f);
   set2 = vector3(0.0f, sideLength, sideLength);
   set3 = vector3(sideLength, sideLength, 0.0f);
   AddTri(triple(set1, set2, set3, topColor));

   // Top 2
   set1 = vector3(sideLength, sideLength, 0.0f);
   set2 = vector3(0.0f, sideLength, sideLength);
   set3 = vector3(sideLength, sideLength, sideLength);
   AddTri(triple(set1, set2, set3, topColor));
   AddMesh("cube3");
   TranslateBy("cube3", vector3(-sideLength / 2, -sideLength / 2, 100.0f));
}

MeshManager::~MeshManager()
{

}

void MeshManager::AddMesh(const char* meshName)
{
   meshes.push_back(activeMesh);
   meshNames.push_back(meshName);
   meshCenters.push_back(vector3());
   UpdateCenter(meshName);
   activeMesh.clear();
}

void MeshManager::UpdateCenter(const char* meshName)
{
   float xAve{0.0f};
   float yAve{0.0f};
   float zAve{0.0f};
   int numTri{0};
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
      return meshes[IDX];
   }
   else
   {
      return meshes[0];
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
   x = x * (fFov / -z);
   y = y * (fFov / -z);
   z = z * (-zFar / (zFar - zNear)) - ((zFar * zNear) / (zFar - zNear));
   projectedCenter = vector3(x, y, z);

   return projectedCenter;
}

std::vector<triple> MeshManager::ProjectMesh(vector<triple> _mesh)
{
   std::vector<triple> projectedMesh;

   for (auto&& tri : _mesh)
   {
      float fFov = 1 / tan(Rotation::DegToRad(Engine::FOV) / 2);
      triple projectedTri;
      // P1
      //matrix3 zMat = matrix3(vector3(1 / tri.p1.z, 1 / tri.p1.z, 0.0f), vector3(0.0f, 1.0f, 0.0f), vector3(0.0f, 0.0f, 1.0f));
      //matrix3 projMat = matrix3(vector3(fFov, 0.0f, 0.0f), vector3(0.0f, Engine::ASPECT_RATIO * fFov, 0.0f), vector3(0.0f, 0.0f, 1.0f));
      //matrix3 multMat = zMat * projMat;
      float x = tri.p1.x;
      float y = tri.p1.y;
      float z = tri.p1.z;
      x = x * (fFov / -z);
      y = y * (fFov / -z);
      z = z * (-zFar / (zFar - zNear)) - ((zFar * zNear) / (zFar - zNear));
      projectedTri.p1 = vector3(x, y, z);

      // P2
      //zMat = matrix3(vector3(1 / tri.p2.z, 1 / tri.p2.z, 0.0f), vector3(0.0f, 1.0f, 0.0f), vector3(0.0f, 0.0f, 1.0f));
      //projMat = matrix3(vector3(fFov, 0.0f, 0.0f), vector3(0.0f, Engine::ASPECT_RATIO * fFov, 0.0f), vector3(0.0f, 0.0f, 1.0f));
      //multMat = zMat * projMat;
      x = tri.p2.x;
      y = tri.p2.y;
      z = tri.p2.z;
      x = x*(fFov / -z);
      y = y*(fFov / -z);
      z = z*(-zFar / (zFar - zNear)) - ((zFar * zNear) / (zFar - zNear));
      projectedTri.p2 = vector3(x, y, z);

      // P3
      //zMat = matrix3(vector3(1 / tri.p3.z, 1 / tri.p3.z, 0.0f), vector3(0.0f, 1.0f, 0.0f), vector3(0.0f, 0.0f, 1.0f));
      //projMat = matrix3(vector3(fFov, 0.0f, 0.0f), vector3(0.0f, Engine::ASPECT_RATIO * fFov, 0.0f), vector3(0.0f, 0.0f, 1.0f));
      //multMat = zMat * projMat;
      x = tri.p3.x;
      y = tri.p3.y;
      z = tri.p3.z;
      x = x*(fFov / -z);
      y = y*(fFov / -z);
      z = z*(-zFar / (zFar - zNear)) - ((zFar * zNear) / (zFar - zNear));
      projectedTri.p3 = vector3(x, y, z);
      projectedTri.color = tri.color;
      projectedMesh.push_back(projectedTri);
   }
   return projectedMesh;
}

std::vector<triple> MeshManager::ScaleMesh(vector<triple> _mesh)
{
   std::vector<triple> scaledMesh;

   for (auto&& tri : _mesh)
   {
      triple tri1 = tri / SCALE_VEC;
      triple tri2 = tri1 * ASPECT_VEC;
      scaledMesh.push_back(tri2);
   }
   return scaledMesh;
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

   vector3 normal = vector3::Cross(lineA, lineB);
   
   return normal;
}

bool MeshManager::InView(triple tri)
{
   vector3 normal = ComputeNormal(tri);
   vector3 cameraLine = vector3::Normalize(tri.center - vector3(0.0f, 0.0f, 1000.0f));
   if (vector3::Dot(cameraLine, normal) < 0)
   {
      return true;
   }
   return false;
}
void MeshManager::Update()
{
   vector3 angVel = vector3(20.0f, 20.0f, 20.0f);
   vector3 angVel2 = vector3(-20.0f, -20.0f, 20.0f);
   float dt = Engine::dt;
   vector3 rotVec = angVel * dt;
   vector3 rotVec2 = angVel2 * dt;

   const char* meshName = "cube";
   RotateBy(meshName, rotVec, GetCenter(meshName));
   TranslateBy(meshName, vector3(0.0f, 0.0f, 0.1f));
   meshName = "cube2";
   RotateBy(meshName, rotVec2, GetCenter(meshName));
   TranslateBy(meshName, vector3(0.0f, 0.1f, 0.1f));
   meshName = "cube3";
   RotateBy(meshName, rotVec, GetCenter(meshName));
   TranslateBy(meshName, vector3(0.1f, 0.0f, 0.1f));
}

void MeshManager::Render()
{
   std::vector<triple> projectedMesh;
   vector3 projectedCenter;

   int count = 0;
   for (auto&& mesh : meshes)
   {
      std::vector<triple> toRender;
      projectedMesh = ProjectMesh(mesh);
      projectedCenter = ProjectCenter(meshCenters[count]);

      for (auto&& tri : projectedMesh)
      {
         if (InView(tri))
         {
            toRender.push_back(tri);
         }
      }
      vector3 normal;
      glColor4f(1, 1, 1, 1);
      glLineWidth(2.5);
      glPointSize(2.5);
      glEnd();
      for (auto&& tri : toRender)
      {
         normal = ComputeNormal(tri);
         glBegin(GL_LINES);
         {

            glColor4f(tri.color.x, tri.color.y, tri.color.z, 1);
            glVertex2f(tri.p1.x, tri.p1.y);
            glVertex2f(tri.p2.x, tri.p2.y);

            glVertex2f(tri.p2.x, tri.p2.y);
            glVertex2f(tri.p3.x, tri.p3.y);

            glVertex2f(tri.p3.x, tri.p3.y);
            glVertex2f(tri.p1.x, tri.p1.y);

            //glColor4f(tri.color.x, tri.color.y, tri.color.z, 1);
            //glVertex2f(normal.x + tri.center.x, normal.y + tri.center.y);
            //glVertex2f(tri.center.x, tri.center.y);

         }
         glEnd();
         glBegin(GL_POINTS);
         {
            glColor4f(1, 1, 1, 1);
            glVertex2f(projectedCenter.x, projectedCenter.y);
         }
         glEnd();
      }
      count++;
   }

}