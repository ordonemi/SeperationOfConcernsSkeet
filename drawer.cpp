//
//  drawer.cpp
//  Lab03
//
//  Created by Andre Regino Paniagua on 11/06/24.
//

#define GL_SILENCE_DEPRECATION
#include "drawer.h"
#include <cassert>
#include <openGL/gl.h>    // Main OpenGL library
#include <GLUT/glut.h>    // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_18

void PointDrawer :: drawPoints(Position pt, int value, float age)
{
   if (value == 0)
      return;

   void* pFont = GLUT_TEXT;

   // set the color
   GLfloat red   = (value <= 0.0 ? 1.0 : 0.0) * age;
   GLfloat green = (value <= 0.0 ? 0.0 : 1.0) * age;
   GLfloat blue  = 0.0;
   glColor3f(red, green, blue);

   // specify the position
   glRasterPos2f((GLfloat)pt.getX(), (GLfloat)pt.getY());

   // draw the digits
   int number = (value > 0 ? value : -value);
   if (number / 10 != 0)
      glutBitmapCharacter(pFont, (char)(number / 10) + '0');
   glutBitmapCharacter(pFont, (char)(number % 10) + '0');
};


/***************************************************************/
/***************************************************************/
/*            EFFECTS DRAWER              */
/***************************************************************/
/***************************************************************/

void DrawFragment :: drawEffects(Position pt, Velocity v, double age, double size, Position ptEnd)
{
   // Draw this sucker
   glBegin(GL_TRIANGLE_FAN);
   
   // the color is a function of age - fading to black
   glColor3f((GLfloat)age, (GLfloat)age, (GLfloat)age);
   
   // draw the fragment
   glVertex2f((GLfloat)(pt.getX() - size), (GLfloat)(pt.getY() - size));
   glVertex2f((GLfloat)(pt.getX() + size), (GLfloat)(pt.getY() - size));
   glVertex2f((GLfloat)(pt.getX() + size), (GLfloat)(pt.getY() + size));
   glVertex2f((GLfloat)(pt.getX() - size), (GLfloat)(pt.getY() + size));
   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
   glEnd();
};

void DrawStreek :: drawEffects(Position pt, Velocity v, double age, double size, Position ptEnd)
{
   // Draw this sucker
   glBegin(GL_LINES);
   glColor3f((GLfloat)age, (GLfloat)age, (GLfloat)age);

   // Draw the actual line
   glVertex2f((GLfloat)pt.getX(), (GLfloat)pt.getY());
   glVertex2f((GLfloat)ptEnd.getX(), (GLfloat)ptEnd.getY());

   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
   glEnd();
   
};

void DrawExhaust :: drawEffects(Position pt, Velocity v, double age, double size, Position ptEnd)
{
   
   // Draw this sucker
   glBegin(GL_LINES);
   glColor3f((GLfloat)age, (GLfloat)age, (GLfloat)age);

   // Draw the actual line
   glVertex2f((GLfloat)pt.getX(), (GLfloat)pt.getY());
   glVertex2f((GLfloat)ptEnd.getX(), (GLfloat)ptEnd.getY());

   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
   glEnd();
};

/***************************************************************/
/***************************************************************/
/*            BULLET DRAWER              */
/***************************************************************/
/***************************************************************/

/************************************************
 * GL VERTEXT POINT
 * Just a more convenient format of glVertext2f
 *************************************************************************/
inline void glVertexPoint(const Position& point)
{
   glVertex2f((GLfloat)point.getX(), (GLfloat)point.getY());
}

/**************************************
 * DRAW LINE
 * Draw a line on the screen from the beginning to the end.
 *************************************************************************/
void BulletDrawer :: drawLine(const Position& begin, const Position& end,
              double red, double green, double blue) const
{
// Get ready...
glBegin(GL_LINES);
glColor3f((GLfloat)red, (GLfloat)green, (GLfloat)blue);

// Draw the actual line
glVertexPoint(begin);
glVertexPoint(end);

// Complete drawing
glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
glEnd();
}

/***********************************************
 * DRAW DOT
 * Draw a single point (square actually on the screen, r pixels by r pixels
 *************************************************************************/
void BulletDrawer :: drawDot(const Position& point, double radius,
                     double red, double green, double blue) const
{
   // Get ready, get set...
   glBegin(GL_TRIANGLE_FAN);
   glColor3f((GLfloat)red, (GLfloat)green, (GLfloat)blue);
   double r = radius / 2.0;

   // Go...
   glVertex2f((GLfloat)(point.getX() - r), (GLfloat)(point.getY() - r));
   glVertex2f((GLfloat)(point.getX() + r), (GLfloat)(point.getY() - r));
   glVertex2f((GLfloat)(point.getX() + r), (GLfloat)(point.getY() + r));
   glVertex2f((GLfloat)(point.getX() - r), (GLfloat)(point.getY() + r));

   // Done!  OK, that was a bit too dramatic
   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
   glEnd();
}



void DrawPellet ::draw(Position pt, double radius, Velocity v )
{
   drawDot(pt, 3.0, 1.0, 1.0, 0.0);
};

void DrawBomb :: draw(Position pt, double radius, Velocity v )
{
   drawDot(pt, radius + 2.0, 0.50, 0.50, 0.00);
   drawDot(pt, radius + 1.0, 0.75, 0.75, 0.00);
   drawDot(pt, radius + 0.0, 0.87, 0.87, 0.00);
   drawDot(pt, radius - 1.0, 1.00, 1.00, 0.00);
};

void DrawShrapnel :: draw(Position pt, double radius, Velocity v )
{
   drawDot(pt, radius, 1.0, 1.0, 0.0);
};

void DrawMissile :: draw(Position pt, double radius, Velocity v )
{
   // missile is a line with a dot at the end so it looks like fins.
   Position ptNext(pt);
   ptNext.add(v);
   drawLine(pt, ptNext, 1.0, 1.0, 0.0);
   drawDot(pt, 3.0, 1.0, 1.0, 1.0);
};



/***************************************************************/
/***************************************************************/
/*            BIRD DRAWER              */
/***************************************************************/
/***************************************************************/



void BirdDrawer :: drawDisk(const Position& center, double radius,
              double red, double green, double blue) const 
{
   assert(radius > 1.0);
   const double increment = M_PI / radius;  // bigger the circle, the more increments

   // begin drawing
   glBegin(GL_TRIANGLES);
   glColor3f((GLfloat)red /* red % */, (GLfloat)green /* green % */, (GLfloat)blue /* blue % */);

   // three points: center, pt1, pt2
   Position pt1;
   pt1.setX(center.getX() + (radius * cos(0.0)));
   pt1.setY(center.getY() + (radius * sin(0.0)));
   Position pt2(pt1);

   // go around the circle
   for (double radians = increment;
      radians <= M_PI * 2.0 + .5;
      radians += increment)
   {
      pt2.setX(center.getX() + (radius * cos(radians)));
      pt2.setY(center.getY() + (radius * sin(radians)));

      glVertex2f((GLfloat)center.getX(), (GLfloat)center.getY());
      glVertex2f((GLfloat)pt1.getX(), (GLfloat)pt1.getY());
      glVertex2f((GLfloat)pt2.getX(), (GLfloat)pt2.getY());

      pt1 = pt2;
   }

   // complete drawing
   glEnd();
}



void DrawRegular :: draw(Position pt, double radius, Velocity v )
{
   drawDisk(pt, radius - 0.0, 1.0, 1.0, 1.0); // white outline
   drawDisk(pt, radius - 3.0, 0.0, 0.0, 1.0); // blue center
};

void DrawFloater :: draw(Position pt, double radius, Velocity v )
{
   drawDisk(pt, radius - 0.0, 0.0, 0.0, 1.0); // blue outline
   drawDisk(pt, radius - 4.0, 1.0, 1.0, 1.0); // white center
};

void DrawSinker :: draw(Position pt, double radius, Velocity v )
{
   drawDisk(pt, radius - 0.0, 0.0, 0.0, 0.8);
   drawDisk(pt, radius - 4.0, 0.0, 0.0, 0.0);
};

void DrawCrazy :: draw(Position pt, double radius, Velocity v )
{
   drawDisk(pt, radius * 1.0, 0.0, 0.0, 1.0); // bright blue outside
   drawDisk(pt, radius * 0.8, 0.2, 0.2, 1.0);
   drawDisk(pt, radius * 0.6, 0.4, 0.4, 1.0);
   drawDisk(pt, radius * 0.4, 0.6, 0.6, 1.0);
   drawDisk(pt, radius * 0.2, 0.8, 0.8, 1.0); // almost white inside
};
