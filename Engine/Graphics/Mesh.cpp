#include "Mesh.h"

/////////////////////////
// ---- CONSTRUCTORS ----
/////////////////////////
Mesh::Mesh()
{

}

Mesh::Mesh(const char* meshName)
{
   name = meshName;
}

Mesh::Mesh(std::string _objPath)
{
   objPath = _objPath;
   LoadMesh();
}

Mesh::Mesh(std::string _objPath, vector3 initialTranslation) : Mesh(_objPath)
{
   Translate(initialTranslation);
}

Mesh::Mesh(std::string _objPath, vector3 initialTranslation, vector3 initialRotation) : Mesh(_objPath, initialTranslation)
{
   Rotate(initialRotation);
}
 
// ---- DESTRUCTOR ----
Mesh::~Mesh()
{

}

///////////////////////////
// ---- PUBLIC METHODS ----
///////////////////////////
void Mesh::Translate( vector3 translateVec)
{
   for (auto&& tri : tris)
   {
      tri = tri + translateVec;
   }
   UpdateCenter();
}

void Mesh::Rotate(vector3 rotVec)
{
   quat = quaternion(rotVec);
   for (auto&& tri : tris)
   {
      tri = Rotation::Rotate(tri, quat, 0);
   }
   UpdateCenter();
}

void Mesh::Rotate(vector3 rotVec, vector3 rotPoint)
{
   quat = quaternion(rotVec);

   Translate(rotPoint * -1);

   for (auto&& tri : tris)
   {
      tri = Rotation::Rotate(tri, quat, 0);
   }

   Translate(rotPoint);
   UpdateCenter();
}

void Mesh::Scale(float mult)
{
   for (auto&& tri : tris)
   {
      tri = tri * mult;
   }
   UpdateCenter();
}

////////////////////////////
// ---- PRIVATE METHODS ----
////////////////////////////
bool Mesh::LoadMesh()
{
   std::ifstream f(objPath);
   if (!f.is_open())
   {
      return false;
   }

   std::vector<vector3> verts;

   while (!f.eof())
   {
      char line[128];
      f.getline(line, 128);

      std::stringstream ss;
      ss << line;

      char temp;

      if (line[0] == 'v')
      {
         vector3 v;
         ss >> temp >> v.x >> v.y >> v.z;
         verts.push_back(v);
      }

      if (line[0] == 'f')
      {
         int f[3];
         ss >> temp >> f[0] >> f[1] >> f[2];
         AddTri(triple(verts[f[0] - 1], verts[f[1] - 1], verts[f[2] - 1]));
      }
   }

   std::string baseFileName = objPath.substr(objPath.find_last_of("/\\") + 1);
   std::string::size_type const extIdx(baseFileName.find_last_of('.'));
   name = (std::string)baseFileName.substr(0, extIdx);

   UpdateCenter();
}

void Mesh::AddTri(triple in)
{
   tris.push_back(in);
}

void Mesh::UpdateCenter()
{
   float xAve{ 0.0f };
   float yAve{ 0.0f };
   float zAve{ 0.0f };
   int numTri{ 0 };

   for (auto&& tri : tris)
   {
      xAve += tri.center.x;
      yAve += tri.center.y;
      zAve += tri.center.z;
      numTri++;
   }
   xAve /= (float)numTri;
   yAve /= (float)numTri;
   zAve /= (float)numTri;

   center = vector3(xAve, yAve, zAve);
}