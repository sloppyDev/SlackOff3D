#include "triple.h"

triple::triple()
{
   p1 = vector3(0);
   p2 = vector3(0);
   p3 = vector3(0);
   center = vector3((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3, (p1.z + p2.z + p3.z) / 3);
   position = p1;
}

triple::triple(vector3 vec)
{
   p1 = vec;
   p2 = vec;
   p3 = vec;
   center = vector3((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3, (p1.z + p2.z + p3.z) / 3);
   position = p1;
}

triple::triple(vector3 _p1, vector3 _p2, vector3 _p3)
{
   p1 = _p1;
   p2 = _p2;
   p3 = _p3;
   center = vector3((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3, (p1.z + p2.z + p3.z) / 3);
   position = p1;
}

triple::~triple()
{

}

void triple::UpdateCenter()
{
   center = vector3((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3, (p1.z + p2.z + p3.z) / 3);
}