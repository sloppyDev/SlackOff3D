#include "../Engine.h"
#include "MeshManager.h"

#include <math.h>

MeshManager::MeshManager(std::vector<std::string> meshPaths, vector3 _cameraPos, quaternion _cameraQuat)
{
   // Instantiating member classes and variables
   depthClippedMesh.name = "depthClipped";
   projectedMesh.name = "projected";
   clippedMesh.name = "clipped";
   renderMesh.name = "render";

   activeMeshIndex = { 0 };

   // Loading meshes
   for (auto&& path : meshPaths)
   {
      Mesh mesh(path);
      worldMeshes.push_back(mesh);
      screenMeshes.push_back(mesh);
   }

   cameraPos = _cameraPos;
   cameraQuat = _cameraQuat;


   //worldMeshes[0].Scale(10.0f);
   worldMeshes[0].Translate(vector3(0.0f, 0.0f, 300.0f));

   float sideLength = 50.0f;
   vector3 set1 = vector3();
   vector3 set2 = vector3();
   vector3 set3 = vector3();
   vector3 frontColor = vector3(1.0f, 0.0f, 0.0f); // red
   vector3 rightColor = vector3(1.0f, 1.0f, 0.0f); // yellow
   vector3 backColor = vector3(0.0f, 1.0f, 0.0f); // green
   vector3 bottomColor = vector3(0.0f, 1.0f, 1.0f); // cyan
   vector3 leftColor = vector3(0.0f, 0.0f, 1.0f); // blue
   vector3 topColor = vector3(1.0f, 0.0f, 1.0f); // pink
   
   //// Front 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, sideLength, 0.0f);
   //set3 = vector3(sideLength, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, frontColor));

   //// Front 2
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, 0.0f);
   //set3 = vector3(sideLength, 0.0f, 0.0f);
   //AddTri(triple(set1, set2, set3, frontColor));

   //// Right 1
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, 0.0f);
   //set3 = vector3(sideLength, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, rightColor));

   //// Right 2
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(sideLength, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, rightColor));

   //// Back 1
   //set1 = vector3(sideLength, 0.0f, sideLength);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, backColor));

   //// Back 2
   //set1 = vector3(0.0f, 0.0f, sideLength);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(0.0f, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, backColor));

   //// Bottom 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(sideLength, 0.0f, 0.0f);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, bottomColor));

   //// Bottom 2
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, 0.0f, sideLength);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, bottomColor));

   //// Left 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(0.0f, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, leftColor));

   //// Left 2
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, 0.0f, sideLength);
   //set3 = vector3(0.0f, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, leftColor));

   //// Top 1
   //set1 = vector3(0.0f, sideLength, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(sideLength, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, topColor));

   //// Top 2
   //set1 = vector3(sideLength, sideLength, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(sideLength, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, topColor));
   //AddMesh("cube");
   //TranslateBy("cube", vector3(-sideLength / 2, -sideLength / 2, 100.0f));





   //// Front 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, sideLength, 0.0f);
   //set3 = vector3(sideLength, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, frontColor));

   //// Front 2
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, 0.0f);
   //set3 = vector3(sideLength, 0.0f, 0.0f);
   //AddTri(triple(set1, set2, set3, frontColor));

   //// Right 1
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, 0.0f);
   //set3 = vector3(sideLength, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, rightColor));

   //// Right 2
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(sideLength, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, rightColor));

   //// Back 1
   //set1 = vector3(sideLength, 0.0f, sideLength);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, backColor));

   //// Back 2
   //set1 = vector3(0.0f, 0.0f, sideLength);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(0.0f, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, backColor));

   //// Bottom 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(sideLength, 0.0f, 0.0f);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, bottomColor));

   //// Bottom 2
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, 0.0f, sideLength);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, bottomColor));

   //// Left 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(0.0f, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, leftColor));

   //// Left 2
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, 0.0f, sideLength);
   //set3 = vector3(0.0f, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, leftColor));

   //// Top 1
   //set1 = vector3(0.0f, sideLength, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(sideLength, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, topColor));

   //// Top 2
   //set1 = vector3(sideLength, sideLength, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(sideLength, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, topColor));
   //AddMesh("cube2");
   //TranslateBy("cube2", vector3(-sideLength / 2, -sideLength / 2, 300.0f));





   //// Front 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, sideLength, 0.0f);
   //set3 = vector3(sideLength, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, frontColor));

   //// Front 2
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, 0.0f);
   //set3 = vector3(sideLength, 0.0f, 0.0f);
   //AddTri(triple(set1, set2, set3, frontColor));

   //// Right 1
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, 0.0f);
   //set3 = vector3(sideLength, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, rightColor));

   //// Right 2
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(sideLength, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, rightColor));

   //// Back 1
   //set1 = vector3(sideLength, 0.0f, sideLength);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, backColor));

   //// Back 2
   //set1 = vector3(0.0f, 0.0f, sideLength);
   //set2 = vector3(sideLength, sideLength, sideLength);
   //set3 = vector3(0.0f, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, backColor));

   //// Bottom 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(sideLength, 0.0f, 0.0f);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, bottomColor));

   //// Bottom 2
   //set1 = vector3(sideLength, 0.0f, 0.0f);
   //set2 = vector3(sideLength, 0.0f, sideLength);
   //set3 = vector3(0.0f, 0.0f, sideLength);
   //AddTri(triple(set1, set2, set3, bottomColor));

   //// Left 1
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(0.0f, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, leftColor));

   //// Left 2
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, 0.0f, sideLength);
   //set3 = vector3(0.0f, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, leftColor));

   //// Top 1
   //set1 = vector3(0.0f, sideLength, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(sideLength, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, topColor));

   //// Top 2
   //set1 = vector3(sideLength, sideLength, 0.0f);
   //set2 = vector3(0.0f, sideLength, sideLength);
   //set3 = vector3(sideLength, sideLength, sideLength);
   //AddTri(triple(set1, set2, set3, topColor));
   //AddMesh("cube3");
   //TranslateBy("cube3", vector3(-sideLength / 2, -sideLength / 2, 100.0f));



   //// Flat Top Triangle
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, sideLength, 0.0f);
   //set3 = vector3(sideLength, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, frontColor));
   //AddMesh("triangleFlatTop");
   //TranslateBy("triangleFlatTop", vector3((-sideLength / 2) + 100.0f, -sideLength / 2, 300.0f));

   //// Flat Bottom Triangle
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(sideLength, sideLength, 0.0f);
   //set3 = vector3(sideLength, 0.0f, 0.0f);
   //AddTri(triple(set1, set2, set3, rightColor));
   //AddMesh("triangleFlatBottom");
   //TranslateBy("triangleFlatBottom", vector3(-sideLength / 2, -sideLength / 2, 300.0f));

   // Pointy Top Triangle
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(sideLength/2, sideLength, 0.0f);
   //set3 = vector3(sideLength, 0.0f, 0.0f);
   //AddTri(triple(set1, set2, set3, backColor));
   //AddMesh("trianglePointTop");
   //TranslateBy("trianglePointTop", vector3((-sideLength / 2) - 100.0f, -sideLength / 2, 300.0f));

   //// Pointy Bottom Triangle
   //set1 = vector3(0.0f, sideLength, 0.0f);
   //set2 = vector3(sideLength / 2, 0.0f, 0.0f);
   //set3 = vector3(sideLength, sideLength, 0.0f);
   //AddTri(triple(set1, set2, set3, bottomColor));
   //AddMesh("trianglePointBottom");
   //TranslateBy("trianglePointBottom", vector3(-sideLength / 2, (-sideLength / 2) - 100.0f, 300.0f));

   //// Pointy Right Triangle
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(0.0f, sideLength, 0.0f);
   //set3 = vector3(sideLength, sideLength/2, 0.0f);
   //AddTri(triple(set1, set2, set3, leftColor));
   //AddMesh("trianglePointRight");
   //TranslateBy("trianglePointRight", vector3((-sideLength / 2) + 100.0f, (-sideLength / 2) + 100.0f, 300.0f));

   //// Weird Pointy Triangle
   //set1 = vector3(0.0f, 0.0f, 0.0f);
   //set2 = vector3(-sideLength/2, sideLength, 0.0f);
   //set3 = vector3(sideLength, -sideLength/2, 0.0f);
   //AddTri(triple(set1, set2, set3, topColor));
   //AddMesh("triangleWeirdPoint");
   //TranslateBy("triangleWeirdPoint", vector3((-sideLength / 2) - 100.0f, (-sideLength / 2) + 100.0f, 300.0f));
}

MeshManager::~MeshManager()
{

}

vector3 MeshManager::GetCenter(std::vector<triple> _mesh)
{
   float xAve{ 0.0f };
   float yAve{ 0.0f };
   float zAve{ 0.0f };
   int numTri{ 0 };

   for (auto&& tri : _mesh)
   {
      xAve += tri.center.x;
      yAve += tri.center.y;
      zAve += tri.center.z;
      numTri++;
   }

   xAve /= (float)numTri;
   yAve /= (float)numTri;
   zAve /= (float)numTri;

   return vector3(xAve, yAve, zAve);
}

vector3 MeshManager::ProjectCenter(vector3 center)
{
   vector3 projectedCenter;
   float fFov = 1 / tan(Rotation::DegToRad(Engine::FOV) / 2);
   float x = center.x;
   float y = center.y;
   float z = center.z;
   x = x * (fFov / z);
   y = Engine::ASPECT_RATIO * y * (fFov / z);
   z = z * (-zFar / (zFar - zNear)) - ((zFar * zNear) / (zFar - zNear));
   projectedCenter = vector3(x, y, z);

   return projectedCenter;
}






vector3 MeshManager::ComputeNormal(triple tri)
{
   vector3 lineA = tri.p1 - tri.p2;
   vector3 lineB = tri.p3 - tri.p2;

   vector3 normal = vector3::Normalize(vector3::Cross(lineA, lineB));
   
   return normal;
}

bool MeshManager::InView(triple tri)
{
   vector3 normal = ComputeNormal(tri);
   vector3 cameraLine = vector3::Normalize(tri.center);
   if (vector3::Dot(cameraLine, normal) < 0)
   {
      return true;
   }
   return false;
}

void MeshManager::ShadeMesh(std::vector<triple>& _mesh)
{
   float luminance{ 0 };
   for (auto&& tri : _mesh)
   {
      vector3 normal = ComputeNormal(tri);
      vector3 lightLine = vector3::Normalize(tri.center - vector3(0.0f, 3000.0f, 700.0f));
      
      luminance = -vector3::Dot(normal, lightLine)*10;
      tri.color = vector3(luminance);
   }
}

void MeshManager::TransformMesh()
{
   for (auto&& tri : worldMeshes[activeMeshIndex].tris)
   {
      triple screenTri;

      screenTri = tri - cameraPos;
      screenTri = Rotation::Rotate(screenTri, cameraQuat, 1);

      screenTri.color = tri.color;
      screenTri.UpdateCenter();
      screenMeshes[activeMeshIndex].tris.push_back(screenTri);
   }
}

void MeshManager::DepthClipMesh()
{
   vector3 zPlaneNorm(0.0f, 0.0f, 1.0f);
   vector3 zPoint(0.0f, 0.0f, zNear);

   Clip(screenMeshes[activeMeshIndex], zPlaneNorm, zPoint, &depthClippedMesh);
}

void MeshManager::ProjectMesh()
{
   float x{};
   float y{};
   float z{};

   for (auto&& tri : depthClippedMesh.tris)
   {
      float fFov = 1 / tan(Rotation::DegToRad(Engine::FOV) / 2);
      triple projectedTri;
      // P1
      x = tri.p1.x;
      y = tri.p1.y;
      z = tri.p1.z;
      x = x * (fFov / z);
      y = Engine::ASPECT_RATIO * y * (fFov / z);
      z = z * (-zFar / (zFar - zNear)) - ((zFar * zNear) / (zFar - zNear));
      projectedTri.p1 = vector3(x, y, z);

      // P2
      x = tri.p2.x;
      y = tri.p2.y;
      z = tri.p2.z;
      x = x * (fFov / z);
      y = Engine::ASPECT_RATIO * y * (fFov / z);
      z = z * (-zFar / (zFar - zNear)) - ((zFar * zNear) / (zFar - zNear));
      projectedTri.p2 = vector3(x, y, z);

      // P3
      x = tri.p3.x;
      y = tri.p3.y;
      z = tri.p3.z;
      x = x * (fFov / z);
      y = Engine::ASPECT_RATIO * y * (fFov / z);
      z = z * (-zFar / (zFar - zNear)) - ((zFar * zNear) / (zFar - zNear));
      projectedTri.p3 = vector3(x, y, z);
      projectedTri.UpdateCenter();
      projectedTri.color = tri.color;

      if (InView(projectedTri))
      {
         projectedMesh.tris.push_back(projectedTri);
      }
   }
}

void MeshManager::ClipMesh()
{
   vector3 rightPlaneNorm(-1.0f, 0.0f, 0.0f);
   vector3 topPlaneNorm(0.0f, -1.0f, 0.0f);
   vector3 leftPlaneNorm(1.0f, 0.0f, 0.0f);
   vector3 bottomPlaneNorm(0.0f, 1.0f, 0.0f);

   vector3 rightPlanePoint(1.0f, 0.0f, 0.0f);
   vector3 topPlanePoint(0.0f, 1.0f, 0.0f);
   vector3 leftPlanePoint(-1.0f, 0.0f, 0.0f);
   vector3 bottomPlanePoint(0.0f, -1.0f, 0.0f);

   Clip(projectedMesh, rightPlaneNorm, rightPlanePoint, &clippedMesh);
   Clip(clippedMesh, topPlaneNorm, topPlanePoint, &clippedMesh);
   Clip(clippedMesh, leftPlaneNorm, leftPlanePoint, &clippedMesh);
   Clip(clippedMesh, bottomPlaneNorm, bottomPlanePoint, &clippedMesh);
}

void MeshManager::Clip(Mesh _mesh, vector3 planeNorm, vector3 planePoint, Mesh* outMesh)
{
   for (auto&& tri : _mesh.tris)
   {
      float signSum{};
      triple clippedTri1;
      triple clippedTri2;

      float checkP1 = vector3::Dot(planeNorm, tri.p1 - planePoint);
      float checkP2 = vector3::Dot(planeNorm, tri.p2 - planePoint);
      float checkP3 = vector3::Dot(planeNorm, tri.p3 - planePoint);
      float checkP1Sign = (checkP1 / abs(checkP1));
      float checkP2Sign = (checkP2 / abs(checkP2));
      float checkP3Sign = (checkP3 / abs(checkP3));
      std::vector<float> checkVec;
      std::vector<vector3> pointsVec;
      checkVec.push_back(checkP1);
      checkVec.push_back(checkP2);
      checkVec.push_back(checkP3);
      pointsVec.push_back(tri.p1);
      pointsVec.push_back(tri.p2);
      pointsVec.push_back(tri.p3);

      signSum = checkP1Sign + checkP2Sign + checkP3Sign;

      if (signSum == 3)
      {
         outMesh->tris.push_back(tri);
      }
      else if (signSum == -3)
      {

      }
      else if (signSum == 1) // Create a Quad
      {
         int minIdx = min_element(checkVec.begin(), checkVec.end()) - checkVec.begin();
         vector3 outPoint = pointsVec[minIdx];
         vector3 t1p1 = pointsVec[(minIdx - 1 + 3) % 3];
         vector3 t1p2;  // intersect of t1p1 and outpoint with plane
         vector3 t1p3 = pointsVec[(minIdx + 1) % 3];
         vector3 t2p1 = t1p3;
         vector3 t2p2 = t1p2; // intersect of t1p1 and outpoint with plane
         vector3 t2p3; // intersect of t2p1 and outpoint with plane

         // Triangle 1
         vector3 lineVec = (outPoint - t1p1);
         lineVec.Normalize();

         float lineProportion = (vector3::Dot((planePoint - t1p1), planeNorm)) / vector3::Dot(lineVec, planeNorm);
         t1p2 = lineVec * lineProportion + t1p1;
         t2p2 = t1p2;

         clippedTri1.p1 = t1p1;
         clippedTri1.p2 = t1p2;
         clippedTri1.p3 = t1p3;
         clippedTri1.UpdateCenter();
         //clippedTri1.color = vector3(1, 0, 0);
         clippedTri1.color = tri.color;

         // Triangle 2
         lineVec = (outPoint - t2p1);
         lineVec.Normalize();

         lineProportion = (vector3::Dot((planePoint - t2p1), planeNorm)) / vector3::Dot(lineVec, planeNorm);
         t2p3 = lineVec * lineProportion + t2p1;

         clippedTri2.p1 = t2p1;
         clippedTri2.p2 = t2p2;
         clippedTri2.p3 = t2p3;
         clippedTri2.UpdateCenter();
         //clippedTri2.color = vector3(0, 1, 0);
         clippedTri2.color = tri.color;
         outMesh->tris.push_back(clippedTri1);
         outMesh->tris.push_back(clippedTri2);
      }
      else // Create single new triangle
      {
         int maxIdx = max_element(checkVec.begin(), checkVec.end()) - checkVec.begin();
         vector3 inPoint = pointsVec[maxIdx];
         vector3 outPoint1 = pointsVec[(maxIdx + 1) % 3];
         vector3 outPoint2 = pointsVec[(maxIdx + 2) % 3];
         vector3 t1p1 = inPoint;
         vector3 t1p2;  // intersect of t1p1 and outpoint1 with plane
         vector3 t1p3;  // Intersect of t1p1 and outpoint2 with plan

         // Line 1
         vector3 lineVec = (outPoint1 - t1p1);
         lineVec.Normalize();

         float lineProportion = (vector3::Dot((planePoint - t1p1), planeNorm)) / vector3::Dot(lineVec, planeNorm);
         t1p2 = lineVec * lineProportion + t1p1;

         // Line 2
         lineVec = (outPoint2 - t1p1);
         lineVec.Normalize();

         lineProportion = (vector3::Dot((planePoint - t1p1), planeNorm)) / vector3::Dot(lineVec, planeNorm);
         t1p3 = lineVec * lineProportion + t1p1;

         clippedTri1.p1 = t1p1;
         clippedTri1.p2 = t1p2;
         clippedTri1.p3 = t1p3;
         clippedTri1.UpdateCenter();
         //clippedTri1.color = vector3(0, 0, 1);
         clippedTri1.color = tri.color;

         outMesh->tris.push_back(clippedTri1);
      }
   }
}

void MeshManager::Update(vector3 _cameraPos, quaternion _cameraQuat)
{
   cameraPos = _cameraPos;
   cameraQuat = _cameraQuat;

   /*std::cout << "\rPOS: X: " << cameraPos.x << ", Y: " << cameraPos.y << ", Z: " << cameraPos.z << "                                                  " << std::endl;
   std::cout << "WORLD SPACE MESH CENTER: X: " << meshCenters[0].x << ", Y: " << meshCenters[0].y << ", Z: " << meshCenters[0].z << "                                                 " << std::endl;
   std::cout << "SCREEN SPACE MESH CENTER: X: " << meshCenter.x << ", Y: " << meshCenter.y << ", Z: " << meshCenter.z << "                                                 " << std::endl;
   std::cout << "QUAT: R: " << cameraQuat.r << ", X: " << cameraQuat.v.x << ", Y: " << cameraQuat.v.y << ", Z: " << cameraQuat.v.z << "                                             " << "\x1b[A\x1b[A\x1b[A";
*/


   //vector3 angVel = vector3(20.0f, 20.0f, -20.0f);
   //vector3 angVel2 = vector3(-20.0f, -20.0f, 20.0f);
   //float dt = Engine::dt;
   //vector3 rotVec = angVel * dt;
   //vector3 rotVec2 = angVel2 * dt;

   //const char* meshName = meshNames[0];
   //RotateBy(meshName, rotVec, GetCenter(meshName));
   //meshName = meshNames[1];
   //RotateBy(meshName, rotVec, GetCenter(meshName));
   //meshName = meshNames[2];
   //RotateBy(meshName, rotVec, GetCenter(meshName));
   //meshName = meshNames[3];
   //RotateBy(meshName, rotVec, GetCenter(meshName));
   //meshName = meshNames[4];
   //RotateBy(meshName, rotVec, GetCenter(meshName));
   //const char* meshName = "cube";
   //RotateBy(meshName, rotVec, GetCenter(meshName));
   //meshName = "cube2";
   //RotateBy(meshName, rotVec2, GetCenter(meshName));
   //meshName = "cube3";
   //RotateBy(meshName, rotVec, GetCenter(meshName));
   //TranslateBy(meshName, vector3(0.0f, 0.0f, 0.1f));
}

void MeshManager::Render()
{


   for (int i = 0; i < worldMeshes.size(); i++)
   {
      screenMeshes[i].tris.clear();
      depthClippedMesh.tris.clear();
      projectedMesh.tris.clear();
      clippedMesh.tris.clear();
      renderMesh.tris.clear();

      activeMeshIndex = i;

      TransformMesh();
      DepthClipMesh();
      ProjectMesh();
      ClipMesh();

      for (auto&& tri : clippedMesh.tris)
      {
         if (InView(tri))
         {
            renderMesh.tris.push_back(tri);
         }
      }

      std::sort(renderMesh.tris.begin(), renderMesh.tris.end(), [](triple& tri1, triple& tri2)
         {
            return (tri2.center.z > tri1.center.z);
         });

      for (auto&& tri : renderMesh.tris)
      {
         rasterer.DrawTriangle(tri, true);
      }
      //ShadeMesh(toRender);
   }
}