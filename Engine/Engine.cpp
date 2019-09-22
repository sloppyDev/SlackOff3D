#include "Engine.h"

#include <sstream>
using namespace std;

const char* Engine::GAME_NAME{ "SlackOff3D" };
int Engine::SCREEN_WIDTH{ 1024 };
int Engine::SCREEN_HEIGHT{ 768 };
int Engine::SCREEN_DEPTH{ 10 };
float Engine::ASPECT_RATIO{ (float)Engine::SCREEN_WIDTH / (float)Engine::SCREEN_HEIGHT };
float Engine::FOV{ 90 };
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

   GAME_NAME = windowTitle;

   SetupIO();
   SetupGLFW();
   SetupViewPort();

   lastTime = (float)glfwGetTime();
   lastFpsTime = lastTime;

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

   ShowFps();

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
   glfwSetCursorPosCallback(window, Mouse::MousePosCallback);
   glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);
   glfwSetKeyCallback(window, Keyboard::KeyCallback);
}

void Engine::SetupGLFW()
{
   glfwMakeContextCurrent(window);
   int width{};
   int height{};
   glfwGetFramebufferSize(window, &width, &height);
   glfwSwapInterval(1);

   const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
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

void Engine::ShowFps()
{
   float now = (float)glfwGetTime();
   dtAve += dt;
   frameCount++;
   if ((now - lastFpsTime) >= 1.0)
   {
      stringstream ss;
      ss << GAME_NAME << " [" << 1/(dtAve/frameCount) << " FPS]";

      frameCount = 0;
      dtAve = 0;

      glfwSetWindowTitle(window, ss.str().c_str());
      lastFpsTime = now;
   }
}