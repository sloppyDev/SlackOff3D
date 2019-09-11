#ifndef SLACKOFF_VECTOR3
#define SLACKOFF_VECTOR3

class matrix3;

class vector3
{
public:
   static float Dot(vector3 a, vector3 b);
   static vector3 Cross(vector3 a, vector3 b);
   static vector3 Project(vector3 a, vector3 b);
   static float Magnitude(vector3 in);
   static vector3 Normalize(vector3 in);

   // Initialization
   vector3();
   vector3(const vector3& other);
   vector3(float in);
   vector3(float _x, float _y, float _z);
   ~vector3();

   // Math Operators
   vector3& operator=(const vector3& other);
   vector3 operator+(const vector3& other);
   vector3 operator-(const vector3& other);
   vector3 operator*(const matrix3& other);
   vector3 operator*(const vector3& other);
   vector3 operator*(float in);
   vector3 operator/(const vector3& other);
   vector3 operator/(float in);

   // Logic Operators
   bool operator==(const vector3& other);
   bool operator!=(const vector3& other);

   // Stored Elements
   float x;
   float y;
   float z;
};
#endif