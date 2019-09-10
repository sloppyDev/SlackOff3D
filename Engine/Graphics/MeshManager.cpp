#include "../Engine.h"
#include "MeshManager.h"

#include <math.h>

using namespace std;

MeshManager::MeshManager()
{
   ang = 0;
   float sideLength = 300.0f;
   float height = sqrt(sideLength * sideLength - (sideLength / 2) * (sideLength / 2));

   vector3 set1 = vector3(-(sideLength / 2) / Engine::SCREEN_WIDTH, 0.0f, 0.0f);
   vector3 set2 = vector3(0.0f, Engine::aspectRatio * height / Engine::SCREEN_HEIGHT, 0.0f);
   vector3 set3 = vector3((sideLength / 2) / Engine::SCREEN_WIDTH, 0.0f, 0.0f);

   AddTri(triple(set1, set2, set3));

   set1 = vector3((-(sideLength / 2) / Engine::SCREEN_WIDTH)+0.2, 0.0f+0.2f, 0.0f);
   set2 = vector3(0.0f + 0.2, Engine::aspectRatio * height / Engine::SCREEN_HEIGHT+0.2f, 0.0f);
   set3 = vector3(((sideLength / 2) / Engine::SCREEN_WIDTH) + 0.2, 0.0f+0.2f, 0.0f);

   AddTri(triple(set1, set2, set3));
}

MeshManager::~MeshManager()
{

}

void MeshManager::AddTri(triple in)
{
   mesh.push_back(in);
}

void MeshManager::RotateTo(float rad)
{
   float y{};
   int count{};
   for (auto&& tri : mesh)
   {
      if (count == 0)
      {
         y = tri.p1.y;
      }
      else
      {
         cout << y - tri.p1.y << endl;
      }
      count++;

      tri.p1.x = (((300 / 2) * cos(rad + PI)) / Engine::SCREEN_WIDTH) + tri.position.x;
      tri.p1.y = (((300 / 2) * sin(rad + PI)) / Engine::SCREEN_HEIGHT) + tri.position.y;
      float height = sqrt(300 * 300 - (300 / 2) * (300 / 2));
      tri.p2.x = (((height)* sin(-rad)) / Engine::SCREEN_WIDTH) + tri.position.x;
      tri.p2.y = (((height)* cos(rad)) / Engine::SCREEN_HEIGHT) + tri.position.y;
      tri.p3.x = (((300 / 2) * cos(rad)) / Engine::SCREEN_WIDTH) + tri.position.x;
      tri.p3.y = (((300 / 2) * sin(rad)) / Engine::SCREEN_HEIGHT) + tri.position.y;

      tri.UpdateCenter();
   }
}


void MeshManager::Update()
{
   float angVel = 100.0f * PI / 180;
   float dt = Engine::dt;

   float rotAng = angVel * dt;
   ang += rotAng;

   RotateTo(ang);
}

void MeshManager::Render()
{
   for (auto&& tri : mesh)
   {

      glColor4f(1, 1, 1, 1);
      glLineWidth(2.5);
      glBegin(GL_LINES);
      {
         glVertex2f(tri.p1.x, tri.p1.y);
         glVertex2f(tri.p2.x, tri.p2.y);

         glVertex2f(tri.p2.x, tri.p2.y);
         glVertex2f(tri.p3.x, tri.p3.y);

         glVertex2f(tri.p3.x, tri.p3.y);
         glVertex2f(tri.p1.x, tri.p1.y);
      }
      glEnd();
      glPointSize(5);
      glBegin(GL_POINTS);
      {
         glVertex3f(tri.center.x, tri.center.y, tri.center.z);
      }
      glEnd();
   }
}

void MeshManager::Render(int color1, int color2, int color3)
{
   for (auto&& tri : mesh)
   {
      glColor4f(1, 1, 1, 1);
      glLineWidth(2.5);
      glBegin(GL_LINES);
      {
         glVertex2f(tri.p1.x, tri.p1.y);
         glVertex2f(tri.p2.x, tri.p2.y);

         glVertex2f(tri.p2.x, tri.p2.y);
         glVertex2f(tri.p3.x, tri.p3.y);

         glVertex2f(tri.p3.x, tri.p3.y);
         glVertex2f(tri.p1.x, tri.p1.y);
      }
      glEnd();
      glPointSize(5);
      glBegin(GL_POINTS);
      {
         glVertex3f(tri.center.x, tri.center.y, tri.center.z);
      }
      glEnd();
   }
}