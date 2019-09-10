#include "matrix3.h"

matrix3::matrix3()
{
   row1 = vector3(0);
   row2 = vector3(0);
   row3 = vector3(0);
   UpdateCols();
}

matrix3::matrix3(float in)
{
   row1 = vector3(in);
   row2 = vector3(in);
   row3 = vector3(in);
   UpdateCols();
}

matrix3::matrix3(vector3 in)
{
   row1 = in;
   row2 = in;
   row3 = in;
   UpdateCols();
}

matrix3::matrix3(vector3 in1, vector3 in2, vector3 in3)
{
   row1 = in1;
   row2 = in2;
   row3 = in3;
   UpdateCols();
}

matrix3::~matrix3()
{

}

void matrix3::UpdateCols()
{
   // Col 1
   col1.x = row1.x;
   col1.y = row2.x;
   col1.z = row3.x;

   // Col 2
   col2.x = row1.y;
   col2.y = row2.y;
   col2.z = row3.y;

   // Col 3
   col3.x = row1.z;
   col3.y = row2.z;
   col3.z = row3.z;
}

matrix3& matrix3::operator=(const matrix3& other)
{
   row1 = other.row1;
   row2 = other.row2;
   row3 = other.row3;
   UpdateCols();
}

matrix3 matrix3::operator+(const matrix3& other)
{
   matrix3 newMat;

   newMat.row1 = row1 + other.row1;
   newMat.row2 = row2 + other.row2;
   newMat.row3 = row3 + other.row3;
   newMat.UpdateCols();

   return newMat;
}

matrix3 matrix3::operator-(const matrix3& other)
{
   matrix3 newMat;

   newMat.row1 = row1 - other.row1;
   newMat.row2 = row2 - other.row2;
   newMat.row3 = row3 - other.row3;
   newMat.UpdateCols();

   return newMat;
}

matrix3 matrix3::operator*(const matrix3& other)
{
   matrix3 newMat;

   // Row 1
   float a = vector3::Dot(row1, other.col1);
   float b = vector3::Dot(row1, other.col2);
   float c = vector3::Dot(row1, other.col3);
   newMat.row1 = vector3(a, b, c);

   // Row 2
   float a = vector3::Dot(row2, other.col1);
   float b = vector3::Dot(row2, other.col2);
   float c = vector3::Dot(row2, other.col3);
   newMat.row2 = vector3(a, b, c);

   // Row 3
   float a = vector3::Dot(row3, other.col1);
   float b = vector3::Dot(row3, other.col2);
   float c = vector3::Dot(row3, other.col3);
   newMat.row3 = vector3(a, b, c);

}   