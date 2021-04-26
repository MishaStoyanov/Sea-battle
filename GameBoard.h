#pragma once
#include<cstring>
#include<string>

using namespace std;
class GameBoard
{
private:
	int computerBoard[11][11];
	int personBoard[11][11];
	string name;
public:
	GameBoard();
	void onScreen();
	void computerFleet();
	void userFleet();
	bool checkVert(int mas[11][11], int ii, int jj, int kol);
	bool checkGor(int mas[11][11], int ii, int jj, int kol);
	bool isThereAShipComp(int x, int y);
	bool isThereAShipUser(int x, int y);
	bool checkCom(int x, int y);
	bool checkUser(int x, int y);
	bool ifKilledComp(int x, int y);
	bool ifKilledUser(int x, int y);
	void afterKillComp(int x, int y);
	void afterKillUser(int x, int y);
	void existComp(int x, int y);
	void existUser(int x, int y);
};

