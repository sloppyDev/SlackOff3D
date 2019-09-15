#include "Engine/Engine.h"

#include "Engine/Graphics/MeshManager.h"
#include "Engine/Graphics/CameraManager.h"

using namespace std;

int main()
{
   cout << "SlackOff3D Test" << endl;
   Engine engine;
   engine.Initialize();
   CameraManager cameraManager;
   MeshManager meshManager(cameraManager.GetPos(), cameraManager.GetQuat());


   while (true)
   {
      engine.Update();
      cameraManager.Update();
      meshManager.Update(cameraManager.GetPos(), cameraManager.GetQuat());

      engine.BeginRender();
      meshManager.Render();
      engine.EndRender();
   }

   return 0;
}