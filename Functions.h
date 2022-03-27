#pragma once


#include <iostream>
#include <iomanip>
#include<Windows.h>
using namespace std;

void mysetcolor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}



void ShowMenu()
{
	system("Color 0A");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                          ________________________________________________________________________________________________________________" << endl << endl;

	cout << "                         |       '########:::::'###::::'########:'########:'##:::::::'########::'######::'##::::'##:'####:'########::      |      " << endl;
	cout << "                         |        ##.... ##:::'## ##:::... ##..::... ##..:: ##::::::: ##.....::'##... ##: ##:::: ##:. ##:: ##.... ##:      |      " << endl;
	cout << "                         |        ##:::: ##::'##:. ##::::: ##::::::: ##:::: ##::::::: ##::::::: ##:::..:: ##:::: ##:: ##:: ##:::: ##:      |      " << endl;
	cout << "                         |        ########::'##:::. ##:::: ##::::::: ##:::: ##::::::: ######:::. ######:: #########:: ##:: ########::      |      " << endl;
	cout << "                         |        ##.... ##: #########:::: ##::::::: ##:::: ##::::::: ##...:::::..... ##: ##.... ##:: ##:: ##.....:::      |      " << endl;
	cout << "                         |        ##:::: ##: ##.... ##:::: ##::::::: ##:::: ##::::::: ##:::::::'##::: ##: ##:::: ##:: ##:: ##::::::::      |      " << endl;
	cout << "                         |        ########:: ##:::: ##:::: ##::::::: ##:::: ########: ########:. ######:: ##:::: ##:'####: ##::::::::      |      " << endl;
	cout << "                         |       ........:::..:::::..:::::..::::::::..:::::........::........:::......:::..:::::..::....::..:::::::::      |      " << endl;
	cout << "                          ________________________________________________________________________________________________________________" << endl << endl;

	cout << endl;
	cout << endl;
	cout << "                                                                              -Welcome-" << endl << endl;
	cout << "                                                                      _________________________" << endl;
	cout << "                                                                     |                         |" << endl;
	cout << "                                                                     |                         |" << endl;
	cout << "                                                                     |       " << char(254) << " Auto (a)        | " << endl;
	cout << "                                                                     |       " << char(254) << " Rules (r)       | " << endl;
	cout << "                                                                     |       " << char(254) << " Manual (m)      | " << endl;
	cout << "                                                                     |                         |" << endl;
	cout << "                                                                     |_________________________|" << endl;


}


void ShowDescribtion() {
	cout << endl;
	mysetcolor(4, 0);
	cout << "      GAME DESCRIBTION..." << endl;
	mysetcolor(2, 0);
	cout << endl;
	cout << "     _____________________________________________________________________________________________________________________________________________________" << endl << endl;
	cout << "    | The game is played on four grids, two for each player. The grids are typically square – usually 10x10 – and the individual squares in the grid are  |" << endl;
	cout << "    | identified by letter and number. On one grid the player arranges ships and records the shots by the opponent. On the other grid, the player         |" << endl;
	cout << "    | records their own shots.                                                                                                                            |" << endl;
	cout << "    |                                                                                                                                                     |" << endl;
	cout << "    |                                                                                                                                                     |" << endl;
	cout << "    |                                                                                                                                                     |" << endl;
	cout << "    | Before play begins, each player secretly arranges their ships on their primary grid. Each ship occupies a number of consecutive squares on the      |" << endl;
	cout << "    | grid, arranged either horizontally or vertically. The number of squares for each ship is determined by the type of ship. The ships cannot overlap   |" << endl;
	cout << "    | (i.e., only one ship can occupy any given square in the grid). The types and numbers of ships allowed are the same for each player. These may       |" << endl;
	cout << "    | vary depending on the rules. The ships should be hidden from players sight and it's not allowed to see each other's pieces. The game is a           |" << endl;
	cout << "    | discovery game which players need to discover their opponents ship positions.                                                                       |" << endl;
	cout << "    |                                                                                                                                                     |" << endl;
	cout << "    | 1+ --> Ships.                                                                                                                                       |" << endl;
	cout << "    | 0 --> Empty Areas.                                                                                                                                  |" << endl;
	cout << "     _____________________________________________________________________________________________________________________________________________________" << endl << endl;


}


const int s = 14;
int game[s][s] = {};
int comp[s][s] = {};
int mask[s][s] = {};
int ships_id = 1;
const int shipmasscount = 10;
int Ships[shipmasscount] = {};
int x = 0;
int shipcount = 0;
char y = ' ';
int ships_id2 = 1;
int Ships2[10] = {};
int shipcount2 = 0;
void Nickname() {
	cout << "                                                                                                                                           " << endl;
	cout << "                                                                                                                                           " << endl;
	cout << "                                                                                                                                           " << endl;
	cout << "                                                                                                                                           " << endl;
	cout << "        Please Enter your nicname--> ";
}



void Loading() {
	cout << "                                                                                                                                           " << endl;
	cout << "                                                                                                                                           " << endl;
	cout << "                                                                                                                                           " << endl;
	cout << "                                                                                                                                           " << endl;
	cout << "                                                                                                                                           " << endl;
	cout << "                                                                                                                                           " << endl;
	cout << "        Please wait, game is loading...";
}


void ShowLetters() {
	cout << "         ";
	for (char y = 'A'; y <= 'M'; y++)
	{
		cout << setw(2.5) << y << " ";
	}
}



void GameMap() {
	cout << endl;
	for (size_t i = 1; i < s; i++)
	{
		for (size_t j = 1; j < s; j++)
		{
			if (j == 1) {
				cout << "   ";
				if (i == 13) {
					continue;
				}
				cout << i << "    ";
				if (i < 10) {
					cout << " ";
				}
			}
			if (i == 13) {
				cout << endl;
				ShowLetters();
				break;
			}
			cout << setw(2.5) << game[i][j] << " ";
		}
		cout << endl;
	}
}


void GameMap2() {
	cout << endl;
	for (size_t i = 1; i < s; i++)
	{
		for (size_t j = 1; j < s; j++)
		{
			if (j == 1) {
				cout << "   ";
				if (i == 13) {
					continue;
				}
				cout << i << "    ";
				if (i < 10) {
					cout << " ";
				}
			}
			if (i == 13) {
				cout << endl;
				ShowLetters();
				break;
			}
			cout << setw(2.5) << game[j][i] << " ";
		}
		cout << endl;
	}
}

void CompMap() {
	int min = 0;
	int max = 10;
	cout << endl;
	for (size_t i = 1; i < s; i++)
	{
		cout << "                                                                                                             ";
		for (size_t j = 1; j < s; j++)
		{
			if (j == 1) {
				cout << "   ";
				if (i == 13) {
					continue;
				}
				cout << i << "    ";
				if (i < 10) {
					cout << " ";
				}
			}
			if (i == 13) {
				cout << endl;
				cout << "                                                                                                             ";
				ShowLetters();
				break;
			}

			cout << setw(2.5) << comp[i][j] << " ";
		}
		cout << endl;
	}
}

int example[s][s] = {};

void MapForIntroducing() {
	int min = 0;
	int max = 10;
	cout << endl;
	for (size_t i = 1; i < s; i++)
	{
		for (size_t j = 1; j < s; j++)
		{
			if (j == 1) {
				cout << "   ";
				if (i == 13) {
					continue;
				}
				cout << i << "    ";
				if (i < 10) {
					cout << " ";
				}
			}
			if (i == 13) {
				cout << endl;
				ShowLetters();
				break;
			}
			cout << setw(2.5) << game[i][j] << " ";
		}
		cout << endl;
	}
}


void GoToXY(int x, int y) {
	COORD p = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}


void show_ship(int x_2, char y_2, int  direction, int sizeofships) {
	int iqr = int(y_2) - 65;
	for (size_t i = 0; i < sizeofships; i++)
	{
		GoToXY(x_2 + 10, iqr + 1);
		cout << "X";

		if (direction == 0) {
			x_2 += 3;
		}
		if (direction == 1) {
			iqr++;
		}
		if (direction == 2) {
			x_2 -= 3;
		}
		if (direction == 3) {
			iqr--;
		}
	}
}


bool shipisinmap(int x_2, char y_2, int direction, int sizeofships) {
	int iqrik = int(y_2) - 65;
	bool inMap = 1;
	for (size_t i = 0; i < sizeofships; i++)
	{
		if (x_2 < 0 || iqrik < 0 || x_2 >= s + 17 || iqrik >= s - 2) {
			inMap = 0;
			break;
		}
		if (direction == 0) {
			x_2++;
		}
		if (direction == 1) {
			iqrik++;
		}
		if (direction == 2) {
			x_2--;
		}
		if (direction == 3) {
			iqrik--;
		}
	}
	return inMap;
}


bool SetBoat(int game[s][s], int  x_2, char y_2, int  direction, int sizeofships) {
	bool isMap = 1;
	int temb_x = (x_2 / 2);
	int iqri = int(y_2) - 65;
	int temb_y = iqri;
	for (size_t i = 0; i < sizeofships; i++)
	{
		if (x_2 < 1 || iqri < 1 || x_2 > s + 17 || iqri > s - 2) {
			isMap = 0;
			break;
		}
		if (game[x_2][iqri] >= 1
			|| game[x_2][iqri + 1] >= 1
			|| game[x_2][iqri - 1] >= 1
			|| game[x_2 + 1][iqri] >= 1
			|| game[x_2 + 1][iqri + 1] >= 1
			|| game[x_2 + 1][iqri - 1] >= 1
			|| game[x_2 - 1][iqri] >= 1
			|| game[x_2 - 1][iqri + 1] >= 1
			|| game[x_2 - 1][iqri - 1] >= 1) {
			isMap = 0;
			break;
		}
		if (direction == 0) {
			x_2++;
		}
		if (direction == 1) {
			iqri++;
		}
		if (direction == 2) {
			x_2--;
		}
		if (direction == 3) {
			iqri--;
		}
	}
	if (isMap == 1) {
		x_2 = temb_x+1;
		iqri = temb_y+1;

		for (size_t i = 0; i < sizeofships; i++)
		{
			game[x_2][iqri] = ships_id;

			if (direction == 0) {
				x_2++;
			}
			if (direction == 1) {
				iqri++;
			}
			if (direction == 2) {
				x_2--;
			}
			if (direction == 3) {
				iqri--;
			}
		}
		Ships[ships_id] = sizeofships;
		ships_id++;
		shipcount++;
	}
	return isMap;
}


void SetShips(int game[s][s], int sizeofships, int numberofships) {
	int direction = 0;
	int y_int2 = 0;
	int x2 = 0;
	int min = 0;
	int max = s - 1;
	int shipcount = 0;
	while (shipcount < numberofships)
	{
		x2 = min + rand() % (max - min);
		y_int2 = min + rand() % (max - min);

		int temp_X = x2;
		int temp_Y = y_int2;

		direction = rand() % 4;

		bool isMap = 1;
		for (size_t i = 0; i < sizeofships; i++)
		{
			if (x2 < 1 || y_int2 < 1 || x2 >= s || y_int2 >= s) {
				isMap = 0;
				break;
			}
			if (game[x2][y_int2] >= 1
				|| game[x2][y_int2 + 1] >= 1
				|| game[x2][y_int2 - 1] >= 1
				|| game[x2 + 1][y_int2] >= 1
				|| game[x2 + 1][y_int2 + 1] >= 1
				|| game[x2 + 1][y_int2 - 1] >= 1
				|| game[x2 - 1][y_int2] >= 1
				|| game[x2 - 1][y_int2 + 1] >= 1
				|| game[x2 - 1][y_int2 - 1] >= 1) {
				isMap = 0;
				break;
			}
			if (direction == 0) {
				x2++;
			}
			if (direction == 1) {
				y_int2++;
			}
			if (direction == 2) {
				x2--;
			}
			if (direction == 3) {
				y_int2--;
			}
		}
		if (isMap == 1) {
			x2 = temp_X;
			y_int2 = temp_Y;

			for (size_t i = 0; i < sizeofships; i++)
			{

				game[x2][y_int2] = ships_id;

				if (direction == 0) {
					x2++;
				}
				if (direction == 1) {
					y_int2++;
				}
				if (direction == 2) {
					x2--;
				}
				if (direction == 3) {
					y_int2--;
				}
			}
			Ships[ships_id] = sizeofships;
			ships_id++;
			shipcount++;
		}
	}


}


void SetShipsForComp(int comp[s][s], int sizeofships, int numberofships) {
	int direction = 0;
	int y_int2 = 0;
	int x2 = 0;
	int min = 0;
	int max = s - 1;
	int shipcount = 0;
	while (shipcount < numberofships)
	{
		x2 = rand() % s;
		y_int2 = rand() % s;

		int temp_X = x2;
		int temp_Y = y_int2;
		direction = rand() % 4;

		bool isMap = 1;
		for (size_t i = 0; i < sizeofships; i++)
		{
			if (x2 < 1 || y_int2 < 1 || x2 >= s || y_int2 >= s) {
				isMap = 0;
				break;
			}
			if (comp[x2][y_int2] >= 1
				|| comp[x2][y_int2 + 1] >= 1
				|| comp[x2][y_int2 - 1] >= 1
				|| comp[x2 + 1][y_int2] >= 1
				|| comp[x2 + 1][y_int2 + 1] >= 1
				|| comp[x2 + 1][y_int2 - 1] >= 1
				|| comp[x2 - 1][y_int2] >= 1
				|| comp[x2 - 1][y_int2 + 1] >= 1
				|| comp[x2 - 1][y_int2 - 1] >= 1) {
				isMap = 0;
				break;
			}
			if (direction == 0) {
				x2++;
			}
			if (direction == 1) {
				y_int2++;
			}
			if (direction == 2) {
				x2--;
			}
			if (direction == 3) {
				y_int2--;
			}
		}
		if (isMap == 1) {
			x2 = temp_X;
			y_int2 = temp_Y;

			for (size_t i = 0; i < sizeofships; i++)
			{
				comp[x2][y_int2] = ships_id2;
				if (direction == 0) {
					x2++;
				}
				if (direction == 1) {
					y_int2++;
				}
				if (direction == 2) {
					x2--;
				}
				if (direction == 3) {
					y_int2--;
				}
			}
			Ships2[ships_id2] = sizeofships;
			ships_id2++;
			shipcount++;
		}
	}


}


void SetPlayerMap() {
	SetShips(game, 5, 1);
	SetShips(game, 4, 2);
	SetShips(game, 3, 3);
	SetShips(game, 2, 3);
	GameMap();
}

void SetCompMap() {
	SetShipsForComp(comp, 5, 1);
	SetShipsForComp(comp, 4, 2);
	SetShipsForComp(comp, 3, 3);
	SetShipsForComp(comp, 2, 3);
	CompMap();
}



int ShootFunction(int comp[s][s], int x, char y, int Ships[shipmasscount]) {
	int result = 0;

	if (comp[x][int(y) - 65 + 1] >= 1) {

		Ships[comp[x][int(y) - 65 + 1]]--;

		if (Ships[comp[x][int(y) - 65 + 1]] <= 0) {
			result = 2;
		}
		else {
			result = 1;
		}
	}

	return result;
}


int ShootFunction2(int game[s][s], int x, int y, int Ships[shipmasscount]) {
	int result = 0;

	if (game[x][y] >= 1) {

		Ships[game[x][y]]--;
		if (Ships[game[x][y]] <= 0) {
			result = 2;
		}
		else {
			result = 1;
		}
	}

	return result;
}


void MainDesk(char* nickname, int destroyedcountfornickname, int injuredcountfornickname, int destroyedcountforcomp, int injuredcountforcomp) {
	mysetcolor(3, 0);
	cout << "                                                  " << "   ---------------------------------------------------------" << endl;
	cout << "                                                  " << endl;
	cout << "                                                  " << "    " << nickname << "'s Destroyed Ships Count --> " << destroyedcountfornickname << "                        " << endl;
	cout << "                                                  " << "    " << nickname << "'s Injured Ships Count --> " << injuredcountfornickname << "                          " << endl;
	cout << "                                                  " << endl;
	cout << "                                                  " << "    " << "Computer" << "'s Destroyed Ships Count --> " << destroyedcountforcomp << "                  " << endl;
	cout << "                                                  " << "    " << "Computer" << "'s Injured Ships Count --> " << injuredcountforcomp << "                    " << endl;
	cout << "                                                  " << endl;
	cout << "                                                  " << "   ---------------------------------------------------------" << endl << endl;
	mysetcolor(2, 0);
}


void Introduction(char* nickname) {
	mysetcolor(2, 0);
	cout << endl;
	mysetcolor(4, 0);
	cout << "            Welcome To Auto Mode!" << endl;
	mysetcolor(2, 0);
	cout << endl;
	mysetcolor(3, 0);
	cout << "                " << nickname << "'s Map." << endl;
	mysetcolor(2, 0);
	cout << endl;
	srand(time(0));
	SetPlayerMap();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	mysetcolor(3, 0);
	cout << "           Computer's Map. ( Is Private For You )" << endl;
	mysetcolor(2, 0);
	cout << endl;
	ships_id = 0;
	SetCompMap();
}