#include "../Engine.h"
#include "Triangle.h"

#include <math.h>

using namespace std;

Triangle::Triangle()
{
   ang = 0;
   float sideLength = 300.0f;
   float height = sqrt(sideLength * sideLength - (sideLength / 2) * (sideLength / 2));

   vector3 set1 = vector3(-(sideLength / 2) / Engine::SCREEN_WIDTH, 0.0f, 0.0f);
   vector3 set2 = vector3(0.0f, Engine::aspectRatio * height / Engine::SCREEN_HEIGHT, 0.0f);
   vector3 set3 = vector3((sideLength / 2) / Engine::SCREEN_WIDTH, 0.0f, 0.0f);

   SetPoints(set1, set2, set3);
}

Triangle::~Triangle()
{

}

void Triangle::SetPoints(vector3 set1, vector3 set2, vector3 set3)
{
   points.p1 = set1;
   points.p2 = set2;
   points.p3 = set3;
}

void Triangle::RotateTo(float rad)
{
   points.p1.x = ((300 / 2) * cos(rad + PI)) / Engine::SCREEN_WIDTH;
   points.p1.y = ((300 / 2) * sin(rad + PI)) / Engine::SCREEN_HEIGHT;
   float height = sqrt(300 * 300 - (300 / 2) * (300 / 2));
   points.p2.x = ((height)* sin(-rad)) / Engine::SCREEN_WIDTH;
   points.p2.y = ((height)* cos(rad)) / Engine::SCREEN_HEIGHT;
   points.p3.x = ((300 / 2) * cos(rad)) / Engine::SCREEN_WIDTH;
   points.p3.y = ((300 / 2) * sin(rad)) / Engine::SCREEN_HEIGHT;
}


void Triangle::Update()
{
   float angVel = 10.0f * PI / 180;
   float dt = Engine::dt;

   float rotAng = angVel * dt;
   ang += rotAng;
   cout << ang << " " << angVel << " " << dt << endl;

   RotateTo(ang);
}

void Triangle::Render()
{
   glColor4f(1, 1, 1, 1);
   glLineWidth(2.5);
   glBegin(GL_LINES);
   {
      glVertex2f(points.p1.x, points.p1.y);
      glVertex2f(points.p2.x, points.p2.y);

      glVertex2f(points.p2.x, points.p2.y);
      glVertex2f(points.p3.x, points.p3.y);

      glVertex2f(points.p3.x, points.p3.y);
      glVertex2f(points.p1.x, points.p1.y);
   }
   glEnd();
}

void Triangle::Render(int color1, int color2, int color3)
{
   glColor4f(color1, color2, color3, 1);
   glLineWidth(2.5);
   glBegin(GL_LINES);
   {
      glVertex2f(points.p1.x, points.p1.y);
      glVertex2f(points.p2.x, points.p2.y);

      glVertex2f(points.p2.x, points.p2.y);
      glVertex2f(points.p3.x, points.p3.y);

      glVertex2f(points.p3.x, points.p3.y);
      glVertex2f(points.p1.x, points.p1.y);
   }
   glEnd();
}