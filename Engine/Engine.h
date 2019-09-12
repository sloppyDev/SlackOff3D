#ifndef SLACKOFF_ENGINE
#define SLACKOFF_ENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")

#include <iostream>

class Engine
{
public:
   // Static Variables
   static const char* GAME_NAME;
   static int SCREEN_WIDTH;
   static int SCREEN_HEIGHT;
   static int SCREEN_DEPTH;
   static float ASPECT_RATIO;
   static float FOV;
   static float dt;

   // Initializations
   Engine();
   ~Engine();

   bool Initialize();
   bool Initialize(char* gameName);

   // Main Engine Frame Operations
   void Update();
   void BeginRender();
   void EndRender();

private:
   // Configuration Setup
   void SetupIO();
   void SetupGLFW();
   void SetupViewPort();

   void ShowFps();
   // Private Variables
   GLFWwindow* window;
   float lastTime;
   float lastFpsTime;
   float dtAve;
   int frameCount{ 0 };
};
#endif