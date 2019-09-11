#include "../Engine.h"
#include "MeshManager.h"

#include <math.h>

using namespace std;

vector3 MeshManager::ASPECT_VEC = vector3(1.0f, (float)Engine::ASPECT_RATIO, 1.0f);
vector3 MeshManager::SCALE_VEC = vector3((float)Engine::SCREEN_WIDTH, (float)Engine::SCREEN_HEIGHT, (float)Engine::SCREEN_DEPTH);

MeshManager::MeshManager()
{
   float sideLength = 200.0f;
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
   // Front 1
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(0.0f, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, 0.0f);
   set3 = vector3(sideLength / Engine::SCREEN_WIDTH, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, 0.0f);
   AddTri(triple(set1, set2, set3, frontColor));

   // Front 2
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(sideLength / Engine::SCREEN_WIDTH, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, 0.0f);
   set3 = vector3(sideLength / Engine::SCREEN_WIDTH, 0.0f, 0.0f);
   AddTri(triple(set1, set2, set3, frontColor));

   // Right 1
   set1 = vector3(sideLength / Engine::SCREEN_WIDTH, 0.0f, 0.0f);
   set2 = vector3(sideLength / Engine::SCREEN_WIDTH, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, 0.0f);
   set3 = vector3(sideLength / Engine::SCREEN_WIDTH, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, sideLength / Engine::SCREEN_DEPTH);
   AddTri(triple(set1, set2, set3, rightColor));

   // Right 2
   set1 = vector3(sideLength / Engine::SCREEN_WIDTH, 0.0f, 0.0f);
   set2 = vector3(sideLength / Engine::SCREEN_WIDTH, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, sideLength / Engine::SCREEN_DEPTH);
   set3 = vector3(sideLength / Engine::SCREEN_WIDTH, 0.0f, sideLength / Engine::SCREEN_DEPTH);
   AddTri(triple(set1, set2, set3, rightColor));

   // Back 1
   set1 = vector3(sideLength / Engine::SCREEN_WIDTH, 0.0f, sideLength / Engine::SCREEN_DEPTH);
   set2 = vector3(sideLength / Engine::SCREEN_WIDTH, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, sideLength / Engine::SCREEN_DEPTH);
   set3 = vector3(0.0f, 0.0f, sideLength / Engine::SCREEN_DEPTH);
   AddTri(triple(set1, set2, set3, backColor));

   // Back 2
   set1 = vector3(0.0f, 0.0f, sideLength / Engine::SCREEN_DEPTH);
   set2 = vector3(sideLength / Engine::SCREEN_WIDTH, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, sideLength / Engine::SCREEN_DEPTH);
   set3 = vector3(0.0f, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, sideLength / Engine::SCREEN_DEPTH);
   AddTri(triple(set1, set2, set3, backColor));

   // Bottom 1
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(sideLength / Engine::SCREEN_WIDTH, 0.0f, 0.0f);
   set3 = vector3(0.0f, 0.0f, sideLength / Engine::SCREEN_DEPTH);
   AddTri(triple(set1, set2, set3, bottomColor));

   // Bottom 2
   set1 = vector3(sideLength / Engine::SCREEN_WIDTH, 0.0f, 0.0f);
   set2 = vector3(sideLength / Engine::SCREEN_WIDTH, 0.0f, sideLength / Engine::SCREEN_DEPTH);
   set3 = vector3(0.0f, 0.0f, sideLength / Engine::SCREEN_DEPTH);
   AddTri(triple(set1, set2, set3, bottomColor));

   // Left 1
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(0.0f, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, sideLength / Engine::SCREEN_DEPTH);
   set3 = vector3(0.0f, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, 0.0f);
   AddTri(triple(set1, set2, set3, leftColor));

   // Left 2
   set1 = vector3(0.0f, 0.0f, 0.0f);
   set2 = vector3(0.0f, 0.0f, sideLength / Engine::SCREEN_DEPTH);
   set3 = vector3(0.0f, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, sideLength / Engine::SCREEN_DEPTH);
   AddTri(triple(set1, set2, set3, leftColor));

   // Top 1
   set1 = vector3(0.0f, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, 0.0f);
   set2 = vector3(0.0f, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, sideLength / Engine::SCREEN_DEPTH);
   set3 = vector3(sideLength / Engine::SCREEN_WIDTH, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, 0.0f);
   AddTri(triple(set1, set2, set3, topColor));

   // Top 2
   set1 = vector3(sideLength / Engine::SCREEN_WIDTH, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, 0.0f);
   set2 = vector3(0.0f, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, sideLength / Engine::SCREEN_DEPTH);
   set3 = vector3(sideLength / Engine::SCREEN_WIDTH, (Engine::ASPECT_RATIO * sideLength) / Engine::SCREEN_HEIGHT, sideLength / Engine::SCREEN_DEPTH);
   AddTri(triple(set1, set2, set3, topColor));
}

MeshManager::~MeshManager()
{

}

void MeshManager::AddTri(triple in)          
{
   mesh.push_back(in);
}

std::vector<triple> MeshManager::ScaleMesh()
{
   std::vector<triple> scaledMesh;
   int count = 0;
   for (auto&& tri : mesh)
   {
      if (count < 12)
      {
         triple tri1 = tri / SCALE_VEC;
         triple tri2 = tri1 * ASPECT_VEC;
         scaledMesh.push_back(tri2);
      }
      else
      {
         scaledMesh.push_back(tri);
      }
      count++;

   }
   return scaledMesh;
}

void MeshManager::RotateBy(float rad)
{
   for (auto&& tri : mesh)
   {
      tri = Rotation::Rotate(tri, 3, rad + 0.01f);
      tri = Rotation::Rotate(tri, 1, rad+ 0.02);
      //tri = Rotation::Rotate(tri, 3, rad * 0.3);
   }
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
   vector3 cameraLine = vector3::Normalize(tri.center - vector3(0));
   if (vector3::Dot(cameraLine, normal) < 0)
   {
      return true;
   }
   return false;
}
void MeshManager::Update()
{
   float angVel = 10.0f;
   float dt = Engine::dt;
   float rotAng = angVel * dt;

   RotateBy(rotAng);
}

void MeshManager::Render()
{
   
   std::vector<triple> toRender;
   std::vector<triple> scaledMesh = ScaleMesh();

   for (auto&& tri : scaledMesh)
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
   int count = 0;
   for (auto&& tri : toRender)
   {
      if (count < 12)
      {
         glColor4f(0, 1, 0, 1);
      }
      else
      {
         glColor4f(0, 0, 1, 1);
      }
      count++;
      normal = ComputeNormal(tri);
      glBegin(GL_LINES);
      {

         //glColor4f(1, 1, 1, 1);
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
   }
}