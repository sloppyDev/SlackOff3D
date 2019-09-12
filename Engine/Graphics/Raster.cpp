#include "Raster.h"

Raster::Raster()
{

}

Raster::~Raster()
{

}

void Raster::DrawTriangle(triple tri, bool wireframe)
{
   color = tri.color;
   std::vector<float> xVec;
   std::vector<float> yVec;
   float x1 = tri.p1.x;
   xVec.push_back(x1);
   float x2 = tri.p2.x;
   xVec.push_back(x2);
   float x3 = tri.p3.x;
   xVec.push_back(x3);

   float y1 = tri.p1.y;
   yVec.push_back(y1);
   float y2 = tri.p2.y;
   yVec.push_back(y2);
   float y3 = tri.p3.y;
   yVec.push_back(y3);

   float xMax{ 0 };
   float yMax{-100000};
   float xMin{ 0 };
   float yMin{100000};
   float xOther{ 100000 };
   float yOther{ 100000 };
   int minIdx{ 0 };
   int maxIdx{ 0 };
   int triType{ -1 }; // 0 -> flat top, 1 -> flat bottom, 2 -> other

   maxIdx = std::max_element(yVec.begin(), yVec.end()) - yVec.begin();
   yMax = *std::max_element(yVec.begin(), yVec.end());
   xMax = xVec[maxIdx];
   minIdx = std::min_element(yVec.begin(), yVec.end()) - yVec.begin();
   yMin = *std::min_element(yVec.begin(), yVec.end());
   xMin = xVec[minIdx];


   int otherIdx = 3 - (maxIdx + minIdx);
   xOther = xVec[otherIdx];
   yOther = yVec[otherIdx];

   if (yOther == yMax)
   {
      triType = 0;
   }
   else if (yOther == yMin)
   {
      triType = 1;
   }
   else
   {
      triType = 2;
   }

   // Rasterizing
   float yDraw = yMax;
   vector3 intercept1;
   vector3 intercept2;

   switch (triType)
   {
   case 0: // Flat Top
   {
      vector3 topP1 = vector3(xMax, yMax, 0.0f);
      vector3 topP2 = vector3(xOther, yOther, 0.0f);
      vector3 bottomP = vector3(xMin, yMin, 0.0f);

      DrawLine(topP1, topP2);
      yDraw -= yPixelIncrement;
      
      while (yDraw > yMin)
      {
         intercept1.x = GetIntercept(yDraw, topP1, bottomP);
         intercept2.x = GetIntercept(yDraw, topP2, bottomP);
         intercept1.y = yDraw;
         intercept2.y = yDraw;
         DrawLine(intercept1, intercept2);

         yDraw -= yPixelIncrement;
      }
       
      DrawPoint(bottomP);
   }
   break;
   case 1: // Flat Bottom
   {
      vector3 topP = vector3(xMax, yMax, 0.0f);
      vector3 bottomP1 = vector3(xMin, yMin, 0.0f);
      vector3 bottomP2 = vector3(xOther, yOther, 0.0f);

      DrawPoint(topP);
      yDraw -= yPixelIncrement;

      while (yDraw > yMin)
      {
         intercept1.x = GetIntercept(yDraw, topP, bottomP1);
         intercept2.x = GetIntercept(yDraw, topP, bottomP2);
         intercept1.y = yDraw;
         intercept2.y = yDraw;
         DrawLine(intercept1, intercept2);

         yDraw -= yPixelIncrement;
      }

      DrawLine(bottomP1, bottomP2);
   }
   break;
   case 2: // Other
   {
      vector3 topP = vector3(xMax, yMax, 0.0f);
      vector3 bottomP = vector3(xMin, yMin, 0.0f);
      vector3 midP = vector3(xOther, yOther, 0.0f);

      DrawPoint(topP);
      yDraw -= yPixelIncrement;

      while (yDraw > yOther)
      {
         intercept1.x = GetIntercept(yDraw, topP, bottomP);
         intercept2.x = GetIntercept(yDraw, topP, midP);
         intercept1.y = yDraw;
         intercept2.y = yDraw;
         DrawLine(intercept1, intercept2);

         yDraw -= yPixelIncrement;
      }
      while (yDraw > yMin)
      {
         intercept1.x = GetIntercept(yDraw, topP, bottomP);
         intercept2.x = GetIntercept(yDraw, midP, bottomP);
         intercept1.y = yDraw;
         intercept2.y = yDraw;
         DrawLine(intercept1, intercept2);

         yDraw -= yPixelIncrement;
      }
      
      DrawPoint(bottomP);
   }
   break;
   }

   // Wireframe
   if (wireframe)
   {
      DrawWireframe(tri);
   }

}

float Raster::GetIntercept(float y, vector3 p1, vector3 p2)
{
   float x1 = p1.x;
   float x2 = p2.x;
   float y1 = p1.y;
   float y2 = p2.y;

   float intercept{};
   float slope = GetSlope(p1, p2);
   float shiftX{};

   if (y1 < y2)
   {
      shiftX = x1;
      intercept = (y - y1) / slope;
   }
   else
   {
      shiftX = x2;
      intercept = (y - y2) / slope;
   }

   return intercept + shiftX;
}

float Raster::GetSlope(vector3 p1, vector3 p2)
{
   float x1 = p1.x;
   float x2 = p2.x;
   float y1 = p1.y;
   float y2 = p2.y;

   float slope{};

   if (x1 < x2)
   {
      slope = (y2 - y1) / (x2 - x1);
   }
   else
   {
      slope = (y1 - y2) / (x1 - x2);
   }

   return slope;
}

void Raster::DrawPoint(vector3 point)
{

   glPointSize(1.0f);
   glBegin(GL_POINTS);
   {
      glColor4f(color.x, color.y, color.z, 1);
      glVertex2f(point.x, point.y);
   }
   glEnd();
}

void Raster::DrawLine(vector3 p1, vector3 p2)
{
   float leftX{ 0 };
   float leftY{ 0 };
   float rightX{ 0 };
   float rightY{ 0 };

   if (p1.x < p2.x)
   {
      leftX = p1.x;
      leftY = p1.y;
      rightX = p2.x;
      rightY = p2.y;
   }
   else 
   {
      leftX = p2.x;
      leftY = p2.y;
      rightX = p1.x;
      rightY = p1.y;
   }

   glLineWidth(1.5);
   float xDraw = leftX;
   glBegin(GL_LINES);
   {
      glColor4f(color.x, color.y, color.z, 1);
      glVertex2f(leftX, leftY);
      glVertex2f(rightX, rightY);
   }
   glEnd();

   //glBegin(GL_POINTS);
   //{
   //   glColor4f(color.x, color.y, color.z, 1);
   //   while (xDraw < rightX)
   //   {
   //      glVertex2f(xDraw, leftY);
   //      xDraw += xPixelIncrement;
   //   }
   //}
   //glEnd();
}

void Raster::DrawWireframe(triple tri)
{
   glColor4f(0, 0, 0, 1);
   glLineWidth(2.5f);
   glBegin(GL_LINES);
   {
      glVertex2f(tri.p1.x, tri.p1.y);
      glVertex2f(tri.p2.x, tri.p2.y);

      glVertex2f(tri.p2.x, tri.p2.y);
      glVertex2f(tri.p3.x, tri.p3.y);

      glVertex2f(tri.p3.x, tri.p3.y);
      glVertex2f(tri.p1.x, tri.p1.y);
   }
   glEnd();
}