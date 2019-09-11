#ifndef SLACKOFF_MATRIX3
#define SLACKOFF_MATRIX3

#include "vector3.h"

class matrix3
{
public:
   static matrix3 Identity();
   static matrix3 Inverse(matrix3 in);

   // Initialization
   matrix3();
   matrix3(float in);
   matrix3(vector3 in);
   matrix3(vector3 in1, vector3 in2, vector3 in3);
   ~matrix3();

   void UpdateCols();

   // Operators
   matrix3& operator=(const matrix3& other);
   matrix3 operator+(const matrix3& other);
   matrix3 operator-(const matrix3& other);
   matrix3 operator*(const matrix3& other);
   vector3 operator*(const vector3& other);
   matrix3 operator*(float in);

   vector3 row1;
   vector3 row2;
   vector3 row3;

   vector3 col1;
   vector3 col2;
   vector3 col3;
};
#endif