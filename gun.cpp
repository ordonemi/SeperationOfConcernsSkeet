/***********************************************************************
 * Source File:
 *    GUN
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The gun at the bottom of the screen
 ************************************************************************/

#include "gun.h"

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <openGL/gl.h>    // Main OpenGL library
#include <GLUT/glut.h>    // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_18
#endif // __APPLE__

#ifdef __linux__
#include <GL/gl.h>        // Main OpenGL library
#include <GL/glut.h>      // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // __linux__

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>         // OpenGL library we copied 
#define _USE_MATH_DEFINES
#include <math.h>
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // _WIN32

 /************************************************************************
  * ROTATE
  * Rotate a given point (point) around a given origin (center) by a given
  * number of degrees (angle).
  *    INPUT  origin   The center point we will rotate around
  *           x,y      Offset from center that we will be rotating
  *           rotation Rotation in degrees
  *    OUTPUT point    The new position
  *************************************************************************/
Position rotate(const Position& origin,
   double x, double y, double rotation) 
{
   // because sine and cosine are expensive, we want to call them only once
   double cosA = cos(rotation);
   double sinA = sin(rotation);

   // start with our original point
   Position ptReturn(origin);

   // find the new values
   ptReturn.addX(x * cosA - y * sinA);
   ptReturn.addY(y * cosA + x * sinA /*center of rotation*/);

   return ptReturn;
}

/*************************************************************************
 * GL VERTEXT POINT
 * Just a more convenient format of glVertext2f
 *************************************************************************/
inline void glVertexPoint(const Position& point)
{
   glVertex2f((GLfloat)point.getX(), (GLfloat)point.getY());
}

 /*********************************************
  * GUN : DISPLAY
  * Display the gun on the screen
  *********************************************/
void Gun::display() const
{
   drawRectangle(pt, M_PI_2 - angle, 10.0, 100.0, 1.0, 1.0, 1.0);
}
