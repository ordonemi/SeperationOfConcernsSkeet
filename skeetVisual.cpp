/**********************************************************************
 * Skeet
 * No actual birds were killed in the making of this game.
 **********************************************************************/

#include <string>
#include <sstream>
#include "skeetVisual.h"
using namespace std;


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

/*********************************************
 * GUN : DISPLAY
 * Display the gun on the screen
 *********************************************/
void SkeetVisual::display()
{
    drawRectangle(storage.getGun().getPt(), M_PI_2 - storage.getGun().getAngle(), 10.0, 100.0, 1.0, 1.0, 1.0);
}

/************************************************************************
 * DRAW RECTANGLE
 * Draw a rectangle on the screen from the beginning to the end, for the gun
 *************************************************************************/
void SkeetVisual::drawRectangle(const Position& pt,
    double angle = 0.0,
    double width = 10.0,
    double height = 100.0,
    double red = 1.0,
    double green = 1.0,
    double blue = 1.0)
{
    // Get ready...
    glBegin(GL_QUADS);
    glColor3f((GLfloat)red, (GLfloat)green, (GLfloat)blue);

    // Draw the actual line
    glVertexPoint(rotate(pt, width / 2.0, height / 2.0, angle));
    glVertexPoint(rotate(pt, width / 2.0, -height / 2.0, angle));
    glVertexPoint(rotate(pt, -width / 2.0, -height / 2.0, angle));
    glVertexPoint(rotate(pt, -width / 2.0, height / 2.0, angle));
    glVertexPoint(rotate(pt, width / 2.0, height / 2.0, angle));

    // Complete drawing
    glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
    glEnd();
}

/*************************************************************************
 * DRAW TEXT
 * Draw text using a simple bitmap font
 *   INPUT  topLeft   The top left corner of the text
 *          text      The text to be displayed
 ************************************************************************/
void SkeetVisual::drawText(const Position& topLeft, const char* text) 
{
   void* pFont = GLUT_TEXT;
   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);

   // prepare to output the text from the top-left corner
   glRasterPos2f((GLfloat)topLeft.getX(), (GLfloat)topLeft.getY());

   // loop through the text
   for (const char* p = text; *p; p++)
      glutBitmapCharacter(pFont, *p);
}
void drawText(const Position & topLeft, const string & text)
{
   drawText(topLeft, text.c_str());
}

/************************
 * DRAW BULLSEYE
 * Put a bullseye on the screen
 ************************/
void SkeetVisual::drawBullseye(double angle) const
{
   // find where we are pointing
   double distance = storage.getDimension().getX();
   GLfloat x = storage.getDimension().getX() - distance * cos(angle);
   GLfloat y = distance * sin(angle);

   // draw the crosshairs
   glBegin(GL_LINES);
   glColor3f((GLfloat)0.6, (GLfloat)0.6, (GLfloat)0.6);

   // Draw the actual lines
   glVertex2f(x - 10.0, y);
   glVertex2f(x + 10.0, y);

   glVertex2f(x, y - 10.0);
   glVertex2f(x, y + 10.0);

   glColor3f((GLfloat)0.2, (GLfloat)0.2, (GLfloat)0.2);
   glVertex2f(storage.getDimension().getX(), 0.0);
   glVertex2f(x, y);

   // Complete drawing
   glEnd();
}

/************************************************************************
 * DRAW Timer
 * Draw a large timer on the screen
 *  INPUT percent     Amount of time left
 *        Foreground  Foreground color
 *        Background  Background color
 *************************************************************************/
void SkeetVisual::drawTimer(double percent,
                     double redFore, double greenFore, double blueFore,
                     double redBack, double greenBack, double blueBack) const
{
   double radians;

   GLfloat length = (GLfloat)storage.getDimension().getX();
   GLfloat half = length / (GLfloat)2.0;

   // do the background stuff
   drawBackground(redBack, greenBack, blueBack);

   // foreground stuff
   radians = percent * M_PI * 2.0;
   GLfloat x_extent = half + length * (GLfloat)sin(radians);
   GLfloat y_extent = half + length * (GLfloat)cos(radians);

   // get read to draw the triangles
   glBegin(GL_TRIANGLE_FAN);
   glColor3f((GLfloat)redFore /* red % */, (GLfloat)greenFore /* green % */, (GLfloat)blueFore /* blue % */);
   glVertex2f(half, half);

   // fill in the triangles, one eight at a time
   switch ((int)(percent * 8.0))
   {
   case 7: // 315 - 360
      glVertex2f(half, length);
      glVertex2f(length, length);
      glVertex2f(length, 0.0);
      glVertex2f(0.0, 0.0);
      glVertex2f(0.0, length);
      break;
   case 6: // 270 - 315
      glVertex2f(half, length);
      glVertex2f(length, length);
      glVertex2f(length, 0.0);
      glVertex2f(0.0, 0.0);
      glVertex2f(0.0, half);
      break;
   case 5: // 225 - 270
      glVertex2f(half, length);
      glVertex2f(length, length);
      glVertex2f(length, 0.0);
      glVertex2f(0.0, 0.0);
      break;
   case 4: // 180 - 225
      glVertex2f(half, length);
      glVertex2f(length, length);
      glVertex2f(length, 0.0);
      glVertex2f(half, 0.0);
      break;
   case 3: // 135 - 180
      glVertex2f(half, length);
      glVertex2f(length, length);
      glVertex2f(length, half);
      glVertex2f(length, 0.0);
      break;
   case 2: // 90 - 135 degrees
      glVertex2f(half, length);
      glVertex2f(length, length);
      glVertex2f(length, half);
      break;
   case 1: // 45 - 90 degrees
      glVertex2f(half, length);
      glVertex2f(length, length);
      break;
   case 0: // 0 - 45 degrees
      glVertex2f(half, length);
      break;
   }
   glVertex2f(x_extent, y_extent);

   // complete drawing
   glEnd();

   // draw the red line now
   glBegin(GL_LINES);
   glColor3f((GLfloat)0.6, (GLfloat)0.0, (GLfloat)0.0);
   glVertex2f(half, half);
   glVertex2f(x_extent, y_extent);
   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
   glEnd();
}

/************************
 * SKEET DRAW STATUS
 * place the status message on the center of the screen
 ************************/
void SkeetVisual::drawStatus() const
{
    // output the text information
    ostringstream sout;
    if (storage.isGameOver())
    {
        // draw the end of game message
        drawText(Position(storage.getDimension().getX() / 2 - 30, storage.getDimension().getY() / 2 + 10),
            "Game Over");

        // draw end of game status
        drawText(Position(storage.getDimension().getX() / 2 - 30, storage.getDimension().getY() / 2 - 10),
            storage.getTimeText());
    }
    else
    {
        // output the status timer
        drawTimer(1.0 - storage.getPercentLeft(),
            (storage.getLevel() - 0.0) * .1, 0.0, 0.0,
            (storage.getLevel() - 1.0) * .1, 0.0, 0.0);

        // draw the message giving a countdown
        sout << "Level " << storage.getLevel()
            << " begins in " << storage.secondsLeft() << " seconds";
        drawText(Position(storage.getDimension().getX() / 2 - 110, storage.getDimension().getY() / 2 - 10),
            sout.str());
    }
}

/************************************************************************
 * DRAW Background
 * Fill in the background
 *  INPUT color   Background color
 *************************************************************************/
void SkeetVisual::drawBackground(double redBack, double greenBack, double blueBack) const
{
   glBegin(GL_TRIANGLE_FAN);

   // two rectangles is the fastest way to fill the screen.
   glColor3f((GLfloat)redBack /* red % */, (GLfloat)greenBack /* green % */, (GLfloat)blueBack /* blue % */);
   glVertex2f((GLfloat)0.0, (GLfloat)0.0);
   glVertex2f((GLfloat)storage.getDimension().getX(), (GLfloat)0.0);
   glVertex2f((GLfloat)storage.getDimension().getX(), (GLfloat)storage.getDimension().getY());
   glVertex2f((GLfloat)0.0, (GLfloat)storage.getDimension().getY());

   glEnd();
}

/**********************************************
 * SKEET DRAW LEVEL
 * output everything that will be on the screen
 **********************************************/
void SkeetVisual::drawLevel()
{
   // output the background
   drawBackground(storage.getLevel() * .1, 0.0, 0.0);
   
   // draw the bullseye
   if (bullseye)
      drawBullseye(storage.getGun().getAngle());

   // output the gun
   display();
         
   // output the birds, bullets, and fragments
   for (auto it = storage.getPointIterator(); it != storage.getPointEnd(); ++it)
       (*it)->getDrawer()->drawPoints((*it)->getPosition(), (*it)->getValue(), (*it)->getAge());
   for (auto it = storage.getBulletIterator(); it != storage.getBulletEnd(); ++it)
       (*it)->getDrawer()->draw((*it)->getPosition(), (*it)->getRadius(), (*it)->getVelocity());
   for (auto it = storage.getEffectIterator(); it != storage.getEffectEnd(); ++it)
       (*it)->getDrawer()->drawEffects();
   for (auto it = storage.getBirdIterator(); it != storage.getBirdEnd(); ++it)
       (*it)->getDrawer()->draw((*it)->getPosition(), (*it)->getRadius(), (*it)->getVelocity());
   
   // status
   drawText(Position(10,                         storage.getDimension().getY() - 30), storage.getScoreText());
   drawText(Position(storage.getDimension().getX() / 2 - 30, storage.getDimension().getY() - 30), storage.getTimeText());
   drawText(Position(storage.getDimension().getX() - 110, storage.getDimension().getY() - 30), storage.getHitRatioText());
}

/*********************************************
 * SKEET VISUAL : GUN INTERACT
 * Move the gun
 *********************************************/
void SkeetVisual::gunInteract(int clockwise, int counterclockwise)
{
    // move it
    if (clockwise > 0)
    {
        if (clockwise > 10)
        {
            storage.getGun().setAngle(storage.getGun().getAngle() + 0.06);
        }
        else
        {
            storage.getGun().setAngle(storage.getGun().getAngle() + 0.025);
        }
        if (storage.getGun().getAngle() > M_PI_2)
            storage.getGun().setAngle(M_PI_2);
    }
    if (counterclockwise > 0)
    {
        if (clockwise > 10)
        {
            storage.getGun().setAngle(storage.getGun().getAngle() - 0.06);
        }
        else
        {
            storage.getGun().setAngle(storage.getGun().getAngle() - 0.025);
        }
        if (storage.getGun().getAngle() < 0.0)
            storage.getGun().setAngle(0.0);
    }
}

/*******************************
 * SKEET VISUAL : MOVE MISSILE
 ********************************/
void SkeetVisual::inputMissile(bool isUp, bool isDown, bool isB, Flyer* f)
{
    if (isUp)
        f->getVelocity().turn(0.04);
    if (isDown)
        f->getVelocity().turn(-0.04);
}

/************************
 * SKEET VISUAL INTERACT
 * handle all user input
 ************************/
void SkeetVisual::interact(const UserInput & ui)
{
   // reset the game
   if (storage.isGameOver() && ui.isSpace())
   {
       reset();
       return;
   }

   // gather input from the interface
   gunInteract(ui.isUp() + ui.isRight(), ui.isDown() + ui.isLeft());
   Flyer *p = nullptr;

   // a pellet can be shot at any time
   if (ui.isSpace())
   {
       p = new Flyer();
       p->setMover(new MovePellet());
       p->setDrawer(new DrawPellet());
       p->setType(PELLET);
       p->setInitial(storage.getGun().getAngle());
   }
   // missiles can be shot at level 2 and higher
   else if (ui.isM() && storage.getLevel() > 1)
   {
       p = new Flyer(MISSILE);
       p->setMover(new MoveMissile());
       p->setDrawer(new DrawMissile());
       P->setType(MISSILE);
       p->setInitial(storage.getGun().getAngle());
   }
   // bombs can be shot at level 3 and higher
   else if (ui.isB() && storage.getLevel() > 2)
   {
       p = new Flyer();
       p->setMover(new MoveBomb());
       p->setDrawer(new DrawBomb());
       P->setType(BOMB);
       p->setInitial(storage.getGun().getAngle());
   }
   
   bullseye = ui.isShift();

   // add something if something has been added
   if (nullptr != p)
       logic.fire(p);
   
   // send movement information to all the bullets. Only the missile cares.
   for (auto it = storage.getBulletIterator(); it != storage.getBulletEnd(); ++it)
   {
       if ((*it)->getType() == MISSILE)
       {
           inputMissile(ui.isUp() + ui.isRight(), ui.isDown() + ui.isLeft(), ui.isB(), (*it));
       }
   }
}