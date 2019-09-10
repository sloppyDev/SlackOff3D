#include "Engine.h"

using namespace std;

int Engine::SCREEN_WIDTH{ 1024 };
int Engine::SCREEN_HEIGHT{ 768 };
float Engine::aspectRatio{ (float)Engine::SCREEN_WIDTH / (float)Engine::SCREEN_HEIGHT };
float Engine::dt{ 0 };

Engine::Engine()
{

}

bool Engine::Initialize()
{
   if (!glfwInit())
   {
      cout << "Error initializing GLFW!" << endl;
   }

   char windowTitle[] = "Window";
   window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);

   if (window == NULL)
   {
      cout << "Error creating window" << endl;
   }

   SetupIO();
   SetupGLFW();
   SetupViewPort();

   return true;
}

bool Engine::Initialize(char* windowTitle)
{
   if (!glfwInit())
   {
      cout << "Error initializing GLFW!" << endl;
   }

   window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);

   if (window == NULL)
   {
      cout << "Error creating window!" << endl;
   }

   SetupIO();
   SetupGLFW();
   SetupViewPort();

   lastTime = (float)glfwGetTime();

   return true;
}

Engine::~Engine()
{

}

void Engine::Update()
{
   float now{ (float)glfwGetTime() };
   dt = now - lastTime;
   lastTime = now;

   glfwPollEvents();
}

void Engine::BeginRender()
{
   glClear(GL_COLOR_BUFFER_BIT);
}

void Engine::EndRender()
{
   glfwSwapBuffers(window);
}

void Engine::SetupIO()
{

}

void Engine::SetupGLFW()
{
   glfwMakeContextCurrent(window);
   int width{};
   int height{};
   glfwGetFramebufferSize(window, &width, &height);
   glfwSwapInterval(1);

   const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
   cout << mode->width << " " << mode->height << endl;
   int xPos{ (mode->width / 2) - (SCREEN_WIDTH / 2) };
   int yPos{ (mode->height / 2) - (SCREEN_HEIGHT / 2) };
   glfwSetWindowPos(window, xPos, yPos);
}

void Engine::SetupViewPort()
{
   int width{};
   int height{};
   glfwGetFramebufferSize(window, &width, &height);
   glViewport(0, 0, width, height);
}