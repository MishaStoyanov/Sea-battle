#include "StartScreen.h"
#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

StartScreen::StartScreen(){}

int StartScreen::getLevel(){
	return StartScreen::level;
}

void StartScreen::setLevel(int l) {
	StartScreen::level = l;
}

void StartScreen::textScreen() {
	int temp;
	system("cls");
	
	cout << setw(40) << "GAME BATTLESHIP" << endl;
	cout << "Choose your level:" << endl << "1.Easy" << endl << "2.Middle"<<endl << "3.Hard"<< endl;
	cin >> temp;
	if (temp < 1 || temp>3) {
		while (1) {
			cout << "Incorect entering! Try one more time."<<endl;
			cin >> temp;
			if (temp > 0 && temp < 4) break;
			}
		}
	level = temp;
	system("cls");
}

