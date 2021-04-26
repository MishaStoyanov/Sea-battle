#include"StartScreen.h"
#include"GameBoard.h"
#include"Game.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
using namespace std;

int main()
{	
	srand(time(0));
	Game game;
	game.play();
	cin.get();
	cin.get();

}
