#pragma once
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "Game1.hpp"
#include "Game2.hpp"
#include "Game3.hpp"


class startGame {

	gameOne game1;
	gameTwo game2;
	gameThree game3;

public:
	startGame() {};
	~startGame() {};

	void startgame() {

		game1.gameOnePlay();
		game2.gameTwoPlay();
		game3.gameThreePlay();


	}

};