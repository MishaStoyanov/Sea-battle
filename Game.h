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
	int compEasy(); // ��������� ���� ��������, ���� ���� ����� � �������
	int compMiddle(); // ���� ����� � ������� �� ���� ����� ����(����� �� ���������), ����� ������ ��� ��������
	int compHard(); //���� �� ����� ��������� �������� ����� ���������
	void play();
	void stats();
};

