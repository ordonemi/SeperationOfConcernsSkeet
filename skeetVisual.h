/***********************************************************************
 * Header File:
 *    Skeet Visual
 * Author:
 *    Gabriel Hellabrand, Emilio Ordonez
 * Summary:
 *    The interface component of the game
 ************************************************************************/
#include "skeetStorage.h"
#include "skeetLogic.h"
#include "flyer.h"
#include "uiInteract.h"
#pragma once

/*************************************************************************
 * Skeet Visual
 * The interface class
 *************************************************************************/
class SkeetVisual {
public:
    void drawLevel();
    void drawBackground(double redBack, double greenBack, double blueBack) const;
    void drawStatus() const;
    void drawTimer(double percent,
        double redFore, double greenFore, double blueFore,
        double redBack, double greenBack, double blueBack) const;
    void drawBullseye(double angle) const;
    void interact(const UserInput& ui);

    bool isPlaying() { return storage.isPlaying(); }
    bool isGameOver() { return storage.isGameOver(); }
    void drawRectangle(const Position& pt,
        double angle = 0.0,
        double width = 10.0,
        double height = 100.0,
        double red = 1.0,
        double green = 1.0,
        double blue = 1.0);
    void drawText(const Position& topLeft, const char* text);
    void display();
    void startLogic() { logic.animate(); }

private:
    SkeetStorage storage;
    SkeetLogic logic;
    bool bullseye;
    UserInput ui;

    void gunInteract(int clockwise, int counterclockwise);
    void reset() { storage.reset() };
    void inputMissile(bool isUp, bool isDown, bool isB, Flyer* f);
};
