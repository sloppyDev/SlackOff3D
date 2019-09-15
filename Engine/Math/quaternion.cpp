#include "quaternion.h"
#include "Rotation.h"

#include <cmath>


quaternion::quaternion()
{
   r = 1;
   v = vector3();
}

quaternion::quaternion(float angle, vector3 direction)
{
   float rad = Rotation::DegToRad(angle);

   r = cos(rad / 2);
   direction.Normalize();
   v = direction * sin(rad / 2);
   this->Normalize();
}

quaternion::quaternion(vector3 angles)
{
   vector3 rotAxisX(1.0f, 0.0f, 0.0f);
   vector3 rotAxisY(0.0f, 1.0f, 0.0f);
   vector3 rotAxisZ(0.0f, 0.0f, 1.0f);
   quaternion quatX(angles.x, rotAxisX);
   quaternion quatY(angles.y, rotAxisY);
   quaternion quatZ(angles.z, rotAxisZ);
   quaternion newQuat = quatY * quatX * quatZ;

   this->r = newQuat.r;
   this->v = newQuat.v;
}

quaternion::~quaternion()
{

}

quaternion& quaternion::operator=(const quaternion& other)
{
   r = other.r;
   v = other.v;

   return *this;
}

quaternion quaternion::operator*(const quaternion& other)
{
   float rNew;
   vector3 vNew;

   float r1 = r;
   float r2 = other.r;
   vector3 v1 = v;
   vector3 v2 = other.v;

   rNew = r1 * r2 - vector3::Dot(v1, v2);
   vector3 cross = vector3::Cross(v1, v2);
   vNew = v2 * r1 + v1 * r2 + cross;

   quaternion newQuat;

   newQuat.r = rNew;
   newQuat.v = vNew;

   return newQuat;
}

quaternion quaternion::EulerToQuat(vector3 ang)
{
   float phi = Rotation::DegToRad(ang.x);
   float theta = Rotation::DegToRad(ang.y);
   float psi = Rotation::DegToRad(ang.z);

   float q0 = cos(psi / 2) * cos(theta / 2) * cos(psi / 2) + sin(psi / 2) * sin(theta / 2) * sin(psi / 2);
   float q1 = cos(psi / 2) * cos(theta / 2) * sin(psi / 2) - sin(psi / 2) * sin(theta / 2) * cos(psi / 2);
   float q2 = cos(psi / 2) * sin(theta / 2) * cos(psi / 2) + sin(psi / 2) * cos(theta / 2) * sin(psi / 2);
   float q3 = sin(psi / 2) * cos(theta / 2) * cos(psi / 2) - cos(psi / 2) * sin(theta / 2) * sin(psi / 2);

   vector3 vNew(q1, q2, q3);
   quaternion newQuat(q0, vNew);

   return newQuat;
}

vector3 quaternion::QuatToEuler(quaternion _quat)
{
   float psiVal1 = 2 * _quat.v.x * _quat.v.y + 2 * _quat.r * _quat.v.z;
   float psiVal2 = 1 - 2 * _quat.v.y * _quat.v.y - 2 * _quat.v.z * _quat.v.z;
   float thetaVal = 2 * _quat.r * _quat.v.y - 2 * _quat.v.z * _quat.v.x;
   float phiVal1 = 2 * _quat.r * _quat.v.x + 2 * _quat.v.y * _quat.v.z;
   float phiVal2 = 1 - 2 * _quat.v.x * _quat.v.x - 2 * _quat.v.y * _quat.v.y;

   float psi = Rotation::RadToDeg(atan2(psiVal1, psiVal2));
   float theta = Rotation::RadToDeg(-asin(thetaVal));
   float phi = Rotation::RadToDeg(atan2(phiVal1, phiVal2));

   vector3 euler(phi, theta, psi);

   return euler;
}

void quaternion::Normalize()
{
   float squaredVals = r * r + v.x * v.x + v.y * v.y + v.z * v.z;
   float magnitude = sqrt(squaredVals);

   r = r / magnitude;
   v = v / magnitude;
}

void quaternion::Conjugate()
{
   v = v * -1;
}