#pragma once
#include"GameBoard.h"
#include"StartScreen.h"
class Game
{
private:
	int sumUser = 0, sumComp = 0;
	int compX = -1, compY = -1 , flag =0 ;
	int computerShots = 0, userShots = 0;
	GameBoard gb;
	StartScreen sc;
public:

	Game();
	int userGame();
	int compEasy(); // компьютер бьет рандомно, даже если попал в корабль
	int compMiddle(); // если попал в корабль то бьет около него(может по диагонали), может забыть что атаковал
	int compHard(); //бьет по самым возможным позициям после попадания
	void play();
	void stats();
};

