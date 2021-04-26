#include "GameBoard.h"
#include"StartScreen.h"
#include<iostream>
#include<iomanip>
#include<ctime>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

GameBoard::GameBoard() {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			GameBoard::computerBoard[i][j] = 1;
			GameBoard::personBoard[i][j] = 1;
		}
	}

	cout << "Enter your name : "<<endl;
	cin >> GameBoard::name;
}
void GameBoard::onScreen() {
	
	system("cls");
	cout << setw(62) << "GAME BATTLESHIP"<<endl<<endl<<endl << endl << endl << endl;
	cout << setw(37) << "COMPUTER BOARD" << setw(34)<<name << "`s BOARD"<<endl;
	
	cout << endl << endl ; // 1 -  не стреляли (_), 2 - стреляли, но мимо(*), 3 - стреляли и попали(х), 4 - корaбль (о)
	cout << setw(42) << "0 1 2 3 4 5 6 7 8 9 " << setw(42) << "0 1 2 3 4 5 6 7 8 9 " << endl;
	for (int i = 0; i < 10; i++) {

		cout << endl << setw(20)<<i<<"  ";
		for (int j = 0; j < 10; j++) {
			if (GameBoard::computerBoard[i][j] == 1) cout << "_ "; else
				if (GameBoard::computerBoard[i][j] == 2) cout << "* "; else
					if (GameBoard::computerBoard[i][j] == 3) cout << "x "; else
						if (GameBoard::computerBoard[i][j] == 4) cout << "_ ";
		}
		cout << setw(20) << i << "  ";
		for (int j = 0; j < 10; j++) {
			if (GameBoard::personBoard[i][j] == 1) cout << "_ "; else
				if (GameBoard::personBoard[i][j] == 2) cout << "* "; else
					if (GameBoard::personBoard[i][j] == 3) cout << "x "; else
						if (GameBoard::personBoard[i][j] == 4) cout << "o ";
					
		}
		
	}

}

void GameBoard::computerFleet() {// 1 - kl, 2 - 3 kl, 3 - 2 kl, 4 - 1 kl; sum = 10
	int sh = 10, ii, jj, pos, current = 4, flag = 0;
	srand(time(0));




	//4 parusnik
	pos = rand() % 2 + 1; // 1 - vertikal, 2 - gorizont
	if (pos == 1) {
		ii = rand() % 10;
		jj = rand() % 10;
		while (checkVert(GameBoard::computerBoard, ii, jj, 4) != true) {
			ii = rand() % 10;
			jj = rand() % 10;
			//	cout<<"ii = "<<ii<<" jj = "<<jj<<endl;

		}
		for (int i = ii; i < ii + 4; i++)
			GameBoard::computerBoard[i][jj] = 4;

	}


	if (pos == 2) {
		ii = rand() % 10;
		jj = rand() % 10;
		while (checkGor(GameBoard::computerBoard, ii, jj, 4) != true) {
			ii = rand() % 10;
			jj = rand() % 10;
			

		}
		for (int j = jj; j < jj + 4; j++)
			GameBoard::computerBoard[ii][j] = 4;
	}





	//3 parusnik
	for (int r = 0; r < 2; r++) {
		pos = rand() % 2 + 1; // 1 - vertikal, 2 - gorizont
		if (pos == 1) {
			while (checkVert(GameBoard::computerBoard, ii, jj, 3) != true) {
				ii = rand() % 10;
				jj = rand() % 10;
			

			}
			for (int i = ii; i < ii + 3; i++)
				GameBoard::computerBoard[i][jj] = 4;

		}


		if (pos == 2) {
			while (checkGor(GameBoard::computerBoard, ii, jj, 3) != true) {
				ii = rand() % 10;
				jj = rand() % 10;
			

			}
			for (int j = jj; j < jj + 3; j++)
				GameBoard::computerBoard[ii][j] = 4;
		}
	}


	for (int r = 0; r < 3; r++) {
		pos = rand() % 2 + 1; // 1 - vertikal, 2 - gorizont
		if (pos == 1) {
			while (checkVert(GameBoard::computerBoard, ii, jj, 2) != true) {
				ii = rand() % 10;
				jj = rand() % 10;
				

			}
			for (int i = ii; i < ii + 2; i++)
				GameBoard::computerBoard[i][jj] = 4;

		}


		if (pos == 2) {
			while (checkGor(GameBoard::computerBoard, ii, jj, 2) != true) {
				ii = rand() % 10;
				jj = rand() % 10;

			}
			for (int j = jj; j < jj + 2; j++)
				GameBoard::computerBoard[ii][j] = 4;
		}
	}

	for (int r = 0; r < 4; r++) {
		pos = rand() % 2 + 1; // 1 - vertikal, 2 - gorizont
		if (pos == 1) {
			while (checkVert(GameBoard::computerBoard, ii, jj, 1) != true) {
				ii = rand() % 10;
				jj = rand() % 10;


			}
			for (int i = ii; i < ii + 1; i++)
				GameBoard::computerBoard[i][jj] = 4;

		}
		if (pos == 2) {
			while (checkGor(GameBoard::computerBoard, ii, jj, 1) != true) {
				ii = rand() % 10;
				jj = rand() % 10;
			}
			for (int j = jj; j < jj + 1; j++)
				GameBoard::computerBoard[ii][j] = 4;
		}
	}

}


void GameBoard::userFleet() {
	int choice;
	int sh = 10, ii, jj, pos, current = 4, flag = 0;
	srand(time(0));
	cout << endl << endl<<"Do you wnat to set positions by yourself?(1 - yes, 2 - no)";
	cin >> choice;
	if (choice == 2) {

		//4 parusnik
		pos = rand() % 2 + 1; // 1 - vertikal, 2 - gorizont
		if (pos == 1) {
			ii = rand() % 10;
			jj = rand() % 10;
			while (checkVert(GameBoard::personBoard, ii, jj, 4) != true) {
				ii = rand() % 10;
				jj = rand() % 10;
			}
			for (int i = ii; i < ii + 4; i++)
				GameBoard::personBoard[i][jj] = 4;

		}


		if (pos == 2) {
			ii = rand() % 10;
			jj = rand() % 10;
			while (checkGor(GameBoard::personBoard, ii, jj, 4) != true) {
				ii = rand() % 10;
				jj = rand() % 10;


			}
			for (int j = jj; j < jj + 4; j++)
				GameBoard::personBoard[ii][j] = 4;
		}





		//3 parusnik
		for (int r = 0; r < 2; r++) {
			pos = rand() % 2 + 1; // 1 - vertikal, 2 - gorizont
			if (pos == 1) {
				while (checkVert(GameBoard::personBoard, ii, jj, 3) != true) {
					ii = rand() % 10;
					jj = rand() % 10;


				}
				for (int i = ii; i < ii + 3; i++)
					GameBoard::personBoard[i][jj] = 4;

			}


			if (pos == 2) {
				while (checkGor(GameBoard::personBoard, ii, jj, 3) != true) {
					ii = rand() % 10;
					jj = rand() % 10;


				}
				for (int j = jj; j < jj + 3; j++)
					GameBoard::personBoard[ii][j] = 4;
			}
		}


		for (int r = 0; r < 3; r++) {
			pos = rand() % 2 + 1; // 1 - vertikal, 2 - gorizont
			if (pos == 1) {
				while (checkVert(GameBoard::personBoard, ii, jj, 2) != true) {
					ii = rand() % 10;
					jj = rand() % 10;


				}
				for (int i = ii; i < ii + 2; i++)
					GameBoard::personBoard[i][jj] = 4;

			}


			if (pos == 2) {
				while (checkGor(GameBoard::personBoard, ii, jj, 2) != true) {
					ii = rand() % 10;
					jj = rand() % 10;

				}
				for (int j = jj; j < jj + 2; j++)
					GameBoard::personBoard[ii][j] = 4;
			}
		}

		for (int r = 0; r < 4; r++) {
			pos = rand() % 2 + 1; // 1 - vertikal, 2 - gorizont
			if (pos == 1) {
				while (checkVert(GameBoard::personBoard, ii, jj, 1) != true) {
					ii = rand() % 10;
					jj = rand() % 10;


				}
				for (int i = ii; i < ii + 1; i++)
					GameBoard::personBoard[i][jj] = 4;

			}
			if (pos == 2) {
				while (checkGor(GameBoard::personBoard, ii, jj, 1) != true) {
					ii = rand() % 10;
					jj = rand() % 10;
				}
				for (int j = jj; j < jj + 1; j++)
					GameBoard::personBoard[ii][j] = 4;
			}
		}

	} else
	if (choice == 1) {
		int flag = 0;
		char s;
		GameBoard::onScreen();
		cout <<endl<< "4-cell ship" << endl;
		cout << "Enter vertical (v) or horizontal (h)";
		cin >> s;
		while (flag != 1) {
			cout << "Enter position(x, y):";
			cin >> jj >> ii;
			if (s == 'v' && checkVert(GameBoard::personBoard, ii, jj, 4) == true) { 
				for (int i = ii; i < ii + 4; i++)
					GameBoard::personBoard[i][jj] = 4;
				break; }
			if (s == 'h' && checkGor(GameBoard::personBoard, ii, jj, 4) == true) {
				for (int j = jj; j < jj + 4; j++)
					GameBoard::personBoard[ii][j] = 4;
				break; }
			cout << "Try again!" << endl;
		}

		system("cls");
		GameBoard::onScreen();

		for (int i = 0; i < 2; i++) {
			
			cout << endl << "3-cell ship" << endl;
			cout << "Enter vertical (v) or horizontal (h)";
			cin >> s;
			while (flag != 1) {

				cout << "Enter position(x, y):";
				cin >> ii >> jj;
				if (s == 'v' && checkVert(GameBoard::personBoard, ii, jj, 3) == true) {
					for (int i = ii; i < ii + 3; i++)
						GameBoard::personBoard[i][jj] = 4;
					break;
				}
				if (s == 'h' && checkGor(GameBoard::personBoard, ii, jj, 3) == true) {
					for (int j = jj; j < jj + 3; j++)
						GameBoard::personBoard[ii][j] = 4;
					break;
				}

			}
			system("cls");
			GameBoard::onScreen();
		}

		for (int i = 0; i < 3; i++) {
			cout << endl << "2-cell ship" << endl;
			cout << "Enter vertical (v) or horizontal (h)";
			cin >> s;
			while (flag != 1) {

				cout << "Enter position(x, y):";
				cin >> ii >> jj;
				if (s == 'v' && checkVert(GameBoard::personBoard, ii, jj, 2) == true) {
					for (int i = ii; i < ii + 2; i++)
						GameBoard::personBoard[i][jj] = 4;
					break;
				}
				if (s == 'h' && checkGor(GameBoard::personBoard, ii, jj,2) == true) {
					for (int j = jj; j < jj + 2; j++)
						GameBoard::personBoard[ii][j] = 4;
					break;
				}

			}
			system("cls");
			GameBoard::onScreen();
		}

		for (int i = 0; i < 4; i++) {
			
			cout << endl << "1-cell ship" << endl;
			cout << "Enter vertical (v) or horizontal (h)";
			cin >> s;
			while (flag != 1) {

				cout << "Enter position(x, y):";
				cin >> ii >> jj;
				if (s == 'v' && checkVert(GameBoard::personBoard, ii, jj, 1) == true) {
					for (int i = ii; i < ii + 1; i++)
						GameBoard::personBoard[i][jj] = 4;
					break;
				}
				if (s == 'h' && checkGor(GameBoard::personBoard, ii, jj, 1) == true) {
					for (int j = jj; j < jj + 1; j++)
						GameBoard::personBoard[ii][j] = 4;
					break;
				}

			}
			system("cls");
			GameBoard::onScreen();
		}

	}
}

bool GameBoard::checkVert(int mas[11][11], int ii, int jj, int kol) {
	 if (ii + kol -1  > 9) return false;
	for (int i = ii - 1; i < ii + kol + 2; i++) {
		for (int j = jj - 1; j < jj + 2; j++) {
			if (i < 0 || i>9 || j < 0 || j>9) continue; else {
				if (mas[i][j] == 4) return false;
			}
	
		}
	}

	return true;
}

bool GameBoard::checkGor(int mas[11][11], int ii, int jj, int kol) {

		if (jj + kol - 1> 9) return false;
	for (int i = ii - 1; i < ii + 2; i++) {
		for (int j = jj - 1; j < jj + kol + 2; j++)
			if (i < 0 || i>9 || j < 0 || j>9) continue; else {
				if (mas[i][j] == 4) return false;
			}
	}
	return true;
}

bool GameBoard::isThereAShipComp(int x, int y) {
	if (GameBoard::computerBoard[y][x] == 4) { 
		GameBoard::computerBoard[y][x] = 3;
		return true; }
	else
	{
		GameBoard::computerBoard[y][x] = 2;
		return false;
	}
}

bool GameBoard::isThereAShipUser(int x, int y) {

	if (GameBoard::personBoard[y][x] == 4) {
		GameBoard::personBoard[y][x] = 3;
		return true;
	}
	else
	{
		GameBoard::personBoard[y][x] = 2;
		return false;
	}
}

bool GameBoard::checkCom(int x, int y) {
	if (GameBoard::computerBoard[y][x] ==2  || GameBoard::computerBoard[y][x] == 3) {
		cout << "Already attacked this cell!";
		return false;
	}
	else return true;
}
bool GameBoard::checkUser(int x, int y) {
if (GameBoard::personBoard[y][x] == 2 || GameBoard::personBoard[y][x] == 3) 
		return false;
	else return true;
}

bool GameBoard::ifKilledComp(int x, int y) {
	int sum = 0;
	if (GameBoard::computerBoard[y + 1][x] != 4 || y + 1> 10) sum++;
	if (GameBoard::computerBoard[y - 1][x] != 4 || y - 1< 0) sum++;
	if (GameBoard::computerBoard[y][x + 1] != 4 || x + 1 > 10) sum++;
	if (GameBoard::computerBoard[y][x - 1] != 4 || x - 1< 0) sum++;
	if (sum == 4) return true; else return false;
}

bool GameBoard::ifKilledUser(int x, int y) {
	int sum = 0;
	if (GameBoard::personBoard[y + 1][x] != 4 || y + 1 > 10) sum++;
	if (GameBoard::personBoard[y - 1][x] != 4 || y - 1 < 0) sum++;
	if (GameBoard::personBoard[y][x + 1] != 4 || x + 1 > 10) sum++;
	if (GameBoard::personBoard[y][x - 1] != 4 || x - 1 < 0) sum++;
	if (sum == 4) return true; else return false;
}

void GameBoard::afterKillComp(int x, int y) {
	int kol = 0;
	if (GameBoard::computerBoard[y + 1][x] == 3 ) { //если корбаль по вертикали и верхняя клетка первая

		existComp(y - 1, x - 1);
		existComp(y - 1, x );
		existComp(y - 1, x + 1);
		while (1) {
			if (GameBoard::computerBoard[y + 1][x] == 3 ) {
				existComp(y, x - 1);
				existComp(y, x + 1);
				y++;
			}
			else break;
		}
		existComp(y, x - 1);
		existComp(y, x + 1);
		existComp(y + 1, x - 1);
		existComp(y + 1, x);
		existComp(y + 1, x + 1);


	}
	else 
		if (GameBoard::computerBoard[y - 1][x] == 3 ) { //если корабль по вертикали и нижняя клетка первая

			existComp(y + 1, x - 1);
			existComp(y + 1, x);
			existComp(y + 1, x + 1);
	

		
			while (1) {
				if (GameBoard::computerBoard[y - 1][x] == 3) {
					existComp(y, x - 1);
					existComp(y, x + 1);
					y--;
				}
			
				else break;
			}
			existComp(y, x - 1);
			existComp(y, x + 1);
			existComp(y - 1, x - 1);
			existComp(y - 1, x);
			existComp(y - 1, x + 1);
		}

	
	else 
		if (GameBoard::computerBoard[y][x - 1] == 3) { //если корабль по горизонтали и правая клетка первая

			existComp(y - 1, x + 1);
			existComp(y, x + 1);
			existComp(y + 1, x + 1);

			while (1) {
				if (GameBoard::computerBoard[y][x - 1] == 3 ) {
					existComp(y - 1, x);
					existComp(y + 1, x);
					x--;
				}
				else break;
			}
			existComp(y - 1, x);
			existComp(y + 1, x);

			existComp(y - 1, x - 1);
			existComp(y, x - 1);
			existComp(y + 1, x - 1);
				
		} 
	else	
		if (GameBoard::computerBoard[y][x + 1] == 3) {//если корабль по горизонтали и левая клетка первая

			existComp(y - 1, x - 1);
			existComp(y, x - 1);
			existComp(y + 1, x - 1);
			while (1) {
				if ( x + 1 < 10 && GameBoard::computerBoard[y][x + 1] == 3 ) {
					existComp(y - 1, x);
					existComp(y + 1, x);
					x++;

				}
				else break;
			}
			existComp(y - 1, x);
			existComp(y + 1, x);
			existComp(y - 1, x + 1);
			existComp(y, x + 1);
			existComp(y + 1, x + 1);
		}
		else { // clushay 1-pakubnix
			for (int i = y - 1; i < y + 2; i++)
				for (int j = x - 1; j < x + 2; j++)
					if (i < 0 || i >9 || j < 0 || j>9 || (i == y && j == x)) i = i; else
					{
						GameBoard::computerBoard[i][j] = 2;
					}

		}



}


void GameBoard::afterKillUser(int x, int y) {
	if (GameBoard::personBoard[y + 1][x] == 3) { //если корбаль по вертикали и верхняя клетка первая

		existUser(y - 1, x - 1);
		existUser(y - 1, x);
		existUser(y - 1, x + 1);
		while (1) {
			if (GameBoard::personBoard[y + 1][x] == 3) {
				existUser(y, x - 1);
				existUser(y, x + 1);
				y++;
			}
			else break;
		}
		existUser(y, x - 1);
		existUser(y, x + 1);
		existUser(y + 1, x - 1);
		existUser(y + 1, x);
		existUser(y + 1, x + 1);


	}
	else
		if (GameBoard::personBoard[y - 1][x] == 3) { //если корабль по вертикали и нижняя клетка первая

			existUser(y + 1, x - 1);
			existUser(y + 1, x);
			existUser(y + 1, x + 1);



			while (1) {
				if (GameBoard::personBoard[y - 1][x] == 3) {
					existUser(y, x - 1);
					existUser(y, x + 1);
					y--;
				}

				else break;
			}
			existUser(y, x - 1);
			existUser(y, x + 1);
			existUser(y - 1, x - 1);
			existUser(y - 1, x);
			existUser(y - 1, x + 1);
		}


		else
			if (GameBoard::personBoard[y][x - 1] == 3) { //если корабль по горизонтали и правая клетка первая

				existUser(y - 1, x + 1);
				existUser(y, x + 1);
				existUser(y + 1, x + 1);

				while (1) {
					if (GameBoard::personBoard[y][x - 1] == 3) {
						existUser(y - 1, x);
						existUser(y + 1, x);
						x--;
					}
					else break;
				}
				existUser(y - 1, x);
				existUser(y + 1, x);

				existUser(y - 1, x - 1);
				existUser(y, x - 1);
				existUser(y + 1, x - 1);

			}
			else
				if (GameBoard::personBoard[y][x + 1] == 3) {//если корабль по горизонтали и левая клетка первая

					existUser(y - 1, x - 1);
					existUser(y, x - 1);
					existUser(y + 1, x - 1);
					while (1) {
						if (x + 1 < 10 && GameBoard::personBoard[y][x + 1] == 3) {
							existUser(y - 1, x);
							existUser(y + 1, x);
							x++;

						}
						else break;
					}
					existUser(y - 1, x);
					existUser(y + 1, x);
					existUser(y - 1, x + 1);
					existUser(y, x + 1);
					existUser(y + 1, x + 1);
				}
				else { // clushay 1-pakubnix
					for (int i = y - 1; i < y + 2; i++)
						for (int j = x - 1; j < x + 2; j++)
							if (i < 0 || i >9 || j < 0 || j>9 || (i == y && j == x)) i = i; else
							{
								GameBoard::personBoard[i][j] = 2;
							}


				}


} 

void GameBoard::existComp(int x, int y) {
	int i = 0;
	if (x > 10 || x < 0 || y> 10 || y < 0) i = 0; else GameBoard::computerBoard[x][y] = 2;
}


void GameBoard::existUser(int x, int y) {
	int i = 0;
	if (x > 10 || x < 0 || y> 10 || y < 0) i = 0; else GameBoard::personBoard[x][y] = 2;
}