/***********************************************************************
 * Header File:
 *    SkeetLogic : Class that holds game logic
 * Author:
 *    Emilio Ordonez
 * Summary:
 *    Handles moving components of game
 ************************************************************************/

#pragma once
// INCLUDE STORAGE HEADER FILE
class SkeetLogic
{
public:
	void move();
	void animate(); // Flyer& it
	void spawn();
	void fire();
private:
	//SkeetStorage storage;
};
