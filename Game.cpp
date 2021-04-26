#include "Game.h"
#include"GameBoard.h"
#include<stdlib.h>
#include<iostream>
#include<ctime>
using namespace std;

Game::Game() {
	gb.computerFleet();
	sc.textScreen();
	gb.userFleet();
	gb.onScreen();
}

int Game::userGame() {
	int userX, userY;
	int flag = 0, sum = 0;
	while (1) {
		if (sumUser == 20) break;
		userShots++;
		while (2) {
			cout << endl << "Enter x and y to attack:" << endl;
			cin >> userX >> userY;
			if (userX < 0 || userX>9 || userY < 0 || userY>9) cout << "Incorrect entering! Try again" << endl; else break;
		}

		if (gb.checkCom(userX, userY) == true) {
			if (gb.isThereAShipComp(userX, userY) == true) {
				sumUser ++;
				sum++;
				if (gb.ifKilledComp(userX, userY) == true)	gb.afterKillComp(userX, userY);
					
		
				gb.onScreen(); cout << endl << "Attack succesful! Shot one more time!" << endl;
				}
			else {
				gb.onScreen();
				cout << endl << "There is no ship :(";
			//	cin.get();
				cin.get();
				return sum;
			}
		}
	}
}


int Game::compEasy() {
	srand(time(0));
	int compX = 0, compY = 0, sum =0;
	while (1) {
		if (sumComp == 20) break;
		computerShots++;
		compX = rand() % 10;
		compY = rand() % 10;
		if (gb.checkUser(compX, compY) == true) {
			if (gb.isThereAShipUser(compX, compY) == true) {
				sumComp++;
				sum++;
				if (gb.ifKilledUser(compX, compY) == true)  gb.afterKillUser(compX, compY);

				gb.onScreen(); cout << endl << "Computer attack your ship and will shot one more time!" << endl;

				cin.get();
			
			}
			else {
				gb.onScreen();
				cout << endl << "Computer didn't attack your ship, your turn." << endl;
				cin.get();
				gb.onScreen();
				return sum;
			}
		}
	}
}

int Game::compMiddle() {
	srand(time(0));
	int sum = 0, r = 0, tempX = 0, tempY = 0;

	while (1) {
		if (sumComp == 20) break;
		computerShots++;
		if (flag == 1)
		while (3) {

			while (2) {
				r = compX + rand() % 3 - 1;
				if (r > -1 && r < 10) {
					tempX = r; break;
				}
			}

			while (2) {
				r = compY + rand() % 2 - 1;
				if (r > -1 && r < 10)
				{
					tempY = r; break;
				}
			}
			if (gb.checkUser(tempX, tempY == true)) { compX = tempX; compY = tempY; break; }
		}
		else if (flag == 0) {
			compX = rand() % 10;
			compY = rand() % 10;
		}
		//cout<<endl << "COMPx = " << compX << " compY = " << compY << endl;

		if (gb.checkUser(compX, compY) == true) {
			if (gb.isThereAShipUser(compX, compY) == true) {
				
				sumComp++;
				sum++; flag = 1; // esli udaril, no ne ubil;;;; 0 - esli ne popal, ili ubil korabl
				if (gb.ifKilledUser(compX, compY) == true)
				{
					flag = 0;
					gb.afterKillUser(compX, compY);
				}
				gb.onScreen(); cout << endl << "Computer attack your ship and will shot one more time!" << endl;

				cin.get();
			
			}
			else {
				gb.onScreen();
				cout << endl << "Computer didn't attack your ship, your turn." << endl;

				cin.get();
				gb.onScreen();
				return sum;
			}
		}
		
	}

}



int Game::compHard() {
	srand(time(0));
	int sum = 0, r = 0, tempX = 0, tempY = 0;

	while (1) {
		if (sumComp == 20) break;
		computerShots++;
		if (flag == 1) {
			while (2) {
				r = rand() % 4 + 1; // 1- levo, 2 -pravo, 3- verx , 4-vniz; esli tam ne atakovana kletka i ona sushestuet
				if (r == 1 && compX + 1 < 10 && (gb.checkUser(compX + 1, compY) == true)) {compX += 1; break;}
				if (r == 2 && compX - 1 > -1 && (gb.checkUser(compX -1, compY) == true)) {compX -= 1; break;}
				if (r == 3 && compY + 1 < 10 && (gb.checkUser(compX, compY + 1) == true)) {compY += 1; break;}
				if (r == 4 && compY - 1 > -1 && (gb.checkUser(compX, compY - 1) == true)) {compY -= 1; break;}
			}
		}
		else if (flag == 0) {
			compX = rand() % 10;
			compY = rand() % 10;
		}
		if (gb.checkUser(compX, compY) == true) {
			if (gb.isThereAShipUser(compX, compY) == true) {

				sumComp++;
				sum++; flag = 1; // esli udaril, no ne ubil;;;; 0 - esli ne popal, ili ubil korabl
				if (gb.ifKilledUser(compX, compY) == true)
				{
					flag = 0;
					gb.afterKillUser(compX, compY);
				}
				gb.onScreen(); cout << endl << "Computer attack your ship and will shot one more time!" << endl;
				cin.get();
			}
			else {
				if (flag == 1) {
					if (r == 1) compX -= 1;
					if (r == 2) compX += 1;
					if (r == 3) compY -= 1;
					if (r == 4) compY += 1;
				}
				gb.onScreen();
				cout << endl << "Computer didn't attack your ship, your turn." << endl;

				cin.get();
				gb.onScreen();
				return sum;
			}
		}

	}

}



void Game::play() {
	if (sc.getLevel() == 1) {
		while (sumUser != 20 || sumComp != 20) {
		
			 userGame();
		
			cin.get();
			if (sumUser == 20) {
				system("cls"); cout << "YOU WIN!!!";
				break;
			}

			 compEasy();
		

			if (sumComp == 20) {
				system("cls");
				cout << "YOU LOSE!!!";
				break;
			}
		}
	}
	else
		if (sc.getLevel() == 2) {
			while (sumUser != 20 && sumComp != 20) {
				 userGame();
				if (sumUser == 20) {
					system("cls"); cout << "YOU WIN!!!";
					break;
				}
				cin.get();
				 compMiddle();
			

				if (sumComp == 20) {
					system("cls");
					cout << "YOU LOSE!!!";
					break;
				}
			}

		}
		else
			if (sc.getLevel() == 3) {
				while (sumUser != 20 && sumComp!=20) {
					 userGame();
					if (sumUser == 20) {
						system("cls"); cout << "YOU WIN!!!";
						break;
					}

					compHard();
				
					if (sumComp == 20) {
						system("cls");
						cout << "YOU LOSE!!!";
						break;
					}
				}

			}

	cout << endl << endl << "YOUR STATS: " << endl << "Made shots  - " << userShots << endl << "Hits - " << sumUser;
	cout <<endl<< endl << "COMP STATS:" << endl << "Made shots - " << computerShots << endl << "Hits - " << sumComp;
	cin.get();
}
