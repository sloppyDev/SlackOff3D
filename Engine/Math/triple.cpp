#include "triple.h"

triple::triple()
{
   p1 = vector3(0);
   p2 = vector3(0);
   p3 = vector3(0);
}

triple::triple(vector3 vec)
{
   p1 = vec;
   p2 = vec;
   p3 = vec;
}

triple::triple(vector3 _p1, vector3 _p2, vector3 _p3)
{
   p1 = _p1;
   p2 = _p2;
   p3 = _p3;
}

triple::~triple()
{

}