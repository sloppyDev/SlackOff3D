#include "Engine/Engine.h"

#include "Engine/Graphics/Triangle.h"

using namespace std;

int main()
{
   cout << "WELCOME" << endl;
   Engine engine;
   engine.Initialize();
   Triangle triangle;

   while (true)
   {
      engine.Update();
      triangle.Update();

      engine.BeginRender();
      triangle.Render();
      engine.EndRender();
   }

   return 0;
}