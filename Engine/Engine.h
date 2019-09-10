#ifndef SLACKOFF_ENGINE
#define SLACKOFF_ENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")

#include <iostream>

class Engine
{
public:
   // Static Variables
   static int SCREEN_WIDTH;
   static int SCREEN_HEIGHT;
   static float aspectRatio;
   static float dt;

   // Initializations
   Engine();
   ~Engine();

   bool Initialize();
   bool Initialize(char* windowTitle);

   // Main Engine Frame Operations
   void Update();
   void BeginRender();
   void EndRender();

private:
   // Configuration Setup
   void SetupIO();
   void SetupGLFW();
   void SetupViewPort();

   // Private Variables
   GLFWwindow* window;
   float lastTime;
};
#endif