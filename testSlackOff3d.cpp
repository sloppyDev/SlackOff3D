#include "Engine/Engine.h"

#include "Engine/Graphics/MeshManager.h"

using namespace std;

int main()
{
   cout << "WELCOME" << endl;
   Engine engine;
   engine.Initialize();
   MeshManager meshManager;

   while (true)
   {
      engine.Update();
      meshManager.Update();

      engine.BeginRender();
      meshManager.Render();
      engine.EndRender();
   }

   return 0;
}