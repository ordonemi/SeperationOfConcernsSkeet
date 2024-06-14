/***********************************************************************
 * Header File:
 *    Skeet Visual
 * Author:
 *    Gabriel Hellabrand, Emilio Ordonez
 * Summary:
 *    The interface component of the game
 ************************************************************************/
#include "skeetStorage.h"
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
    void interact();

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

private:
    SkeetStorage storage;
    bool bullseye;
};
