#include "triple.h"

triple::triple()
{
   p1 = vector3(0);
   p2 = vector3(0);
   p3 = vector3(0);
   center = vector3((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3, (p1.z + p2.z + p3.z) / 3);
   position = p1;
   color = vector3(1, 1, 1);
}

triple::triple(vector3 vec)
{
   p1 = vec;
   p2 = vec;
   p3 = vec;
   center = vector3((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3, (p1.z + p2.z + p3.z) / 3);
   position = p1;
   color = vector3(1, 1, 1);
}

triple::triple(vector3 _p1, vector3 _p2, vector3 _p3)
{
   p1 = _p1;
   p2 = _p2;
   p3 = _p3;
   center = vector3((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3, (p1.z + p2.z + p3.z) / 3);
   position = p1;
   color = vector3(1, 1, 1);
}

triple::triple(vector3 _p1, vector3 _p2, vector3 _p3, vector3 _color)
{
   p1 = _p1;
   p2 = _p2;
   p3 = _p3;
   center = vector3((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3, (p1.z + p2.z + p3.z) / 3);
   position = p1;
   color = _color;
}

triple::~triple()
{

}

void triple::UpdateCenter()
{
   center = vector3((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3, (p1.z + p2.z + p3.z) / 3);
}

triple& triple::operator=(const triple& other)
{
   p1 = other.p1;
   p2 = other.p2;
   p3 = other.p3;
   center = other.center;
   color = other.color;

   return *this;
}

triple triple::operator+(const vector3& other)
{
   triple newTri;

   newTri.p1 = p1 + other;
   newTri.p2 = p2 + other;
   newTri.p3 = p3 + other;
   newTri.center = center + other;
   newTri.color = color;

   return newTri;
}

triple triple::operator-(const vector3& other)
{
   triple newTri;

   newTri.p1 = p1 - other;
   newTri.p2 = p2 - other;
   newTri.p3 = p3 - other;
   newTri.center = center - other;
   newTri.color = color;

   return newTri;
}

triple triple::operator*(const vector3& other)
{
   triple newTri;

   newTri.p1 = p1 * other;
   newTri.p2 = p2 * other;
   newTri.p3 = p3 * other;
   newTri.UpdateCenter();
   newTri.color = color;

   return newTri;
}

triple triple::operator/(const vector3& other)
{
   triple newTri;

   newTri.p1 = p1 / other;
   newTri.p2 = p2 / other;
   newTri.p3 = p3 / other;
   newTri.UpdateCenter();
   newTri.color = color;

   return newTri;
}