#include "vector3.h"

#include <math.h>

// Initialization
vector3::vector3()
{
   x = 0;
   y = 0;
   z = 0;
}

vector3::vector3(const vector3& other)
{
   x = other.x;
   y = other.y;
   z = other.z;
}

vector3::vector3(float in)
{
   x = in;
   y = in;
   z = in;
}

vector3::vector3(float _x, float _y, float _z)
{
   x = _x;
   y = _y;
   z = _z;
}

vector3::~vector3()
{

}

float vector3::Dot(vector3 a, vector3 b)
{
   float dotProd = a.x * b.x + a.y * b.y + a.z * b.z;

   return dotProd;
}

vector3 vector3::Cross(vector3 a, vector3 b)
{
   float s1 = a.y * b.z - a.z * b.y;
   float s2 = a.z * b.x - a.x * b.z;
   float s3 = a.x * b.y - a.y * b.x;

   return vector3(s1, s2, s3);
}

// Operators
vector3& vector3::operator=(const vector3& other)
{
   x = other.x;
   y = other.y;
   z = other.z;

   return *this;
}

vector3 vector3::operator+(const vector3& other)
{
   vector3 newVec;

   newVec.x = x + other.x;
   newVec.y = y + other.y;
   newVec.z = z + other.z;

   return newVec;
}

vector3 vector3::operator-(const vector3& other)
{
   vector3 newVec;

   newVec.x = x - other.x;
   newVec.y = y - other.y;
   newVec.z = z - other.z;

   return newVec;
}

vector3 vector3::operator*(const vector3& other)
{
   vector3 newVec;

   newVec.x = x * other.x;
   newVec.y = y * other.y;
   newVec.z = z * other.z;

   return newVec;
}

vector3 vector3::operator*(float in)
{
   vector3 newVec;

   newVec.x = x * in;
   newVec.y = y * in;
   newVec.z = z * in;

   return newVec;
}

vector3 vector3::operator/(const vector3& other)
{
   vector3 newVec;

   newVec.x = x / other.x;
   newVec.y = y / other.y;
   newVec.z = z / other.z;

   return newVec;
}

vector3 vector3::operator/(float in)
{
   vector3 newVec;

   newVec.x = x / in;
   newVec.y = y / in;
   newVec.z = z / in;

   return newVec;
}

bool vector3::operator==(const vector3& other)
{
   bool a = (x == other.x);
   bool b = (y == other.y);
   bool c = (z == other.z);

   return (a && b && c);
}

bool vector3::operator!=(const vector3& other)
{
   return !operator==(other);
}