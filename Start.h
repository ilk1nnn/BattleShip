#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Functions.h"
using namespace std;




void BattleShip()
{
	// Menu
	ShowMenu();
	cout << "\a\a\a";
	// Selection

	cout << endl;
	cout << endl;


	char selection = ' ';
	cout << "                                                                  Select One of this Commands --> ";
	cin >> selection;


	// Conditions  (a or m)

	if (selection == 'm' || selection == 'M') {
		// Manual
		system("cls");
		cin.ignore();
		cin.clear();
		cout << endl;
		cout << endl;
		mysetcolor(3, 0);
		Nickname();
		char* nickname = new char[100]{};
		cin.getline(nickname, 100);
		mysetcolor(2, 0);
		system("cls");
		mysetcolor(3, 0);
		Loading();
		Sleep(800);
		system("cls");
		mysetcolor(2, 0);
		int x_2 = 0;
		char y_2 = 'A';
		int y_2_int = int(y_2) - 65;
		int direction = 0;
		int sizeofships = 6;
		int ch = 0;

		while (true)
		{
			GameMap2();
			cout << endl;
			cout << endl;

			show_ship(x_2, y_2, direction, sizeofships);
			int temp_x_2 = x_2;
			char temp_y_2 = y_2;
			int temp_direction = direction;
			ch = _getch();
			if (ch == 100) {
				x_2 += 3;
			}
			if (ch == 115) {
				y_2++;
			}
			if (ch == 97) {
				x_2 -= 3;
			}
			if (ch == 119) {
				y_2--;
			}
			if (ch == 13) { // enter 
				if (SetBoat(game, x_2, y_2, direction, sizeofships)) {
					x_2 = 0;
					y_2 = 'A';
					direction = 0;
					sizeofships--;
					if (sizeofships <= 1) {
						break;
					}
				}
			}
			if (!shipisinmap(x_2, y_2, direction, sizeofships)) {
				x_2 = temp_x_2;
				y_2 = temp_y_2;
				direction = temp_direction;
			}
			system("cls");
		}
		bool turn = 1;
		int destroyedcountfornickname = 0;
		int injuredcountfornickname = 0;
		int destroyedcountforcomp = 0;
		int injuredcountforcomp = 0;
		SetShipsForComp(comp, 5, 2);
		SetShipsForComp(comp, 3, 1);
		SetShipsForComp(comp, 2, 1);
		CompMap();
		while (true)
		{
			system("cls");
			cout << endl;
			mysetcolor(4, 0);
			cout << "                                                                  Welcome To Manual Mode!" << endl;
			cout << endl;
			mysetcolor(2, 0);
			cout << endl;
			mysetcolor(3, 0);
			cout << "                " << nickname << "'s Map." << endl;;
			mysetcolor(2, 0);
			GameMap2();
			mysetcolor(3, 0);
			cout << "                                                                                                           ";
			cout << "           Computer's Map. ( Is Private For You )" << endl;
			mysetcolor(2, 0);
			srand(time(0));
			ships_id = 0;
			/*SetCompMap();*/
			CompMap();
			cout << endl;
			cout << endl;
			mysetcolor(3, 0);
			cout << "                                                                        For Turns In This Game.." << endl;
			mysetcolor(2, 0);
			MainDesk(nickname, destroyedcountfornickname, injuredcountfornickname, destroyedcountforcomp, injuredcountforcomp);
			cout << endl;
			cout << endl;
			int resultofshoot = 0;
			mysetcolor(6, 0);
			if (turn == true) {
				cout << "                                                     It is Your Turn, " << nickname << "!" << endl;
				cout << "                                                     Enter XY Location --> ";
				int returntomenu = 0;
				returntomenu = _getch();
				if (returntomenu == 27) {
					system("cls");
					BattleShip();
				}

				cin >> x;
				cin >> y;
				if (comp[x][int(y) - 65 + 1] == -1) {
					cout << "                                                     You Typed This Location! Try it Again in another turn!" << endl;
					cout << "                                                     ------------------------------------------------------" << endl;
					Sleep(1500);
				}
				resultofshoot = ShootFunction(comp, x, y, Ships2);
				if (resultofshoot == 2) {
					cout << "                                                     Destroyed Ship!" << endl;
					destroyedcountfornickname++;
					injuredcountfornickname++;
					comp[x][int(y) - 65 + 1] = -1;
					if (destroyedcountfornickname == 4) {
						cout << endl;
						cout << endl;
						cout << "                                                     " << nickname << " Wins!" << endl;
						cout << endl;
						cout << endl;
						system("pause");
						system("cls");
						BattleShip();
					}

					/*MainDesk(nickname, destroyedcountfornickname, injuredcountfornickname, destroyedcountforcomp, injuredcountforcomp);*/
					cout << "                                                     ------------------------" << endl;
				}
				else if (resultofshoot == 1) {
					cout << "                                                     Injured Ship!" << endl;
					injuredcountfornickname++;
					comp[x][int(y) - 65 + 1] = -1;
					/*MainDesk(nickname, destroyedcountfornickname, injuredcountfornickname, destroyedcountforcomp, injuredcountforcomp);*/
					cout << "                                                     ------------------------" << endl;
				}
				else {
					cout << "                                                     Missed Enemy's Ship!" << endl;
					cout << "                                                     ------------------------" << endl;
				}
				if (x > 12 || y > 'M') {
					cout << "                                                     Wrong Input! Try Again in another turn!" << endl;
					cout << "                                                     ---------------------------------------" << endl;
					Sleep(1500);
				}
			}
			else {
				cout << "                                                     It is Computer Turn!" << endl;
				cout << "                                                     Computer chooses his own XY Locations.." << endl;
				Sleep(3200);
				x_2 = rand() % s;
				int y_i = rand() % s + 1;
				resultofshoot = ShootFunction2(game, x, y_i, Ships);
				if (game[x_2][y_i] == -1) {
					cout << "                                                     Comp, you Typed This Location! Try it Again in another turn!" << endl;
					cout << "                                                     ------------------------------------------------------------" << endl;
					Sleep(800);
				}
				if (resultofshoot == 2) {
					cout << "                                                     Destroyed Ship!" << endl;
					destroyedcountforcomp++;
					injuredcountforcomp++;
					game[x_2][y_i] = -1;
					cout << "                                                     ------------------------" << endl;
					if (destroyedcountforcomp == 4) {
						cout << "                                                     " << "Computer " << " Wins!" << endl;
						cout << endl;
						cout << endl;
						system("pause");
						system("cls");
						BattleShip();
					}

					/*MainDesk(nickname, destroyedcountfornickname, injuredcountfornickname, destroyedcountforcomp, injuredcountforcomp);*/
				}
				else if (resultofshoot == 1) {

					cout << "                                                     Injured Ship!" << endl;
					injuredcountforcomp++;
					game[x_2][y_i] = -1;
					/*MainDesk(nickname, destroyedcountfornickname, injuredcountfornickname, destroyedcountforcomp, injuredcountforcomp);*/
					cout << "                                                     ------------------------" << endl;
				}
				else {
					cout << "                                                     Missed Enemy's Ship!" << endl;
					cout << "                                                     ------------------------" << endl;
				}
			}
			/*if (resultofshoot == 2) {
				cout << "    Congratulations!. Destroyed Ship! ( 1 point to you)" << endl;
				cout << "   ----------------------------------------------------" << endl;
			}
			else if (resultofshoot == 1) {
				cout << "    Injured Ship!" << endl;
				cout << "   ------------------------" << endl;
			}
			else {
				cout << "    Missed Enemy's Ship!" << endl;
				cout << "   ------------------------" << endl;
			}*/
			Sleep(800);
			turn = !turn;
		}


	}
	else if (selection == 'a' || selection == 'A') {
		// Auto
		system("cls");
		cin.ignore();
		cin.clear();
		cout << endl;
		cout << endl;
		mysetcolor(3, 0);
		Nickname();
		char* nickname = new char[100]{};
		cin.getline(nickname, 100);
		mysetcolor(2, 0);
		system("cls");
		mysetcolor(3, 0);
		Loading();
		Sleep(800);
		system("cls");
		mysetcolor(2, 0);
		cout << endl;
		mysetcolor(4, 0);
		cout << "                                                                  Welcome To Auto Mode!" << endl;
		cout << endl;
		mysetcolor(2, 0);
		cout << endl;
		mysetcolor(3, 0);
		cout << "                " << nickname << "'s Map." << endl;;
		mysetcolor(2, 0);
		SetPlayerMap();
		mysetcolor(3, 0);
		cout << "                                                                                                           ";
		cout << "           Computer's Map. ( Is Private For You )" << endl;
		mysetcolor(2, 0);
		srand(time(0));
		ships_id = 0;
		/*SetCompMap();*/
		SetShipsForComp(comp, 5, 1);
		SetShipsForComp(comp, 4, 2);
		SetShipsForComp(comp, 3, 3);
		SetShipsForComp(comp, 2, 3);
		CompMap();
		cout << endl;
		cout << endl;
		bool turn = 1; // it means that it is nickname's turn
		mysetcolor(3, 0);
		cout << "                                                                        All Turns In This Game.." << endl;
		mysetcolor(2, 0);
		int destroyedcountfornickname = 0;
		int injuredcountfornickname = 0;
		int destroyedcountforcomp = 0;
		int injuredcountforcomp = 0;
		while (true) {
			system("cls");
			cout << endl;
			mysetcolor(4, 0);
			cout << "                                                                    Welcome To Auto Mode!" << endl;
			mysetcolor(2, 0);
			cout << endl;
			mysetcolor(2, 0);
			cout << endl;
			mysetcolor(3, 0);
			cout << "                " << nickname << "'s Map." << endl;;
			mysetcolor(2, 0);
			GameMap();
			mysetcolor(3, 0);
			cout << "                                                                                                           ";
			cout << "           Computer's Map. ( Is Private For You )" << endl;
			mysetcolor(2, 0);
			CompMap();
			mysetcolor(3, 0);
			cout << "                                                                        For Turns In This Game.." << endl;
			mysetcolor(2, 0);
			MainDesk(nickname, destroyedcountfornickname, injuredcountfornickname, destroyedcountforcomp, injuredcountforcomp);
			cout << endl;
			cout << endl;
			int resultofshoot = 0;
			mysetcolor(6, 0);
			if (turn == true) {
				cout << "                                                     It is Your Turn, " << nickname << "!" << endl;
				cout << "                                                     Enter XY Location --> ";
				int returntomenu = 0;
				returntomenu = _getch();
				if (returntomenu == 27) {
					system("cls");
					BattleShip();
				}

				cin >> x;
				cin >> y;
				if (comp[x][int(y) - 65 + 1] == -1) {
					cout << "                                                     You Typed This Location! Try it Again in another turn!" << endl;
					cout << "                                                     ------------------------------------------------------" << endl;
					Sleep(1500);
				}
				resultofshoot = ShootFunction(comp, x, y, Ships2);
				if (resultofshoot == 2) {
					cout << "                                                     Destroyed Ship!" << endl;
					destroyedcountfornickname++;
					injuredcountfornickname++;
					comp[x][int(y) - 65 + 1] = -1;
					if (destroyedcountfornickname == 9) {
						cout << endl;
						cout << endl;
						cout << "                                                     " << nickname << " Wins!" << endl;
						cout << endl;
						cout << endl;
						system("pause");
						system("cls");
						BattleShip();
					}

					/*MainDesk(nickname, destroyedcountfornickname, injuredcountfornickname, destroyedcountforcomp, injuredcountforcomp);*/
					cout << "                                                     ------------------------" << endl;
				}
				else if (resultofshoot == 1) {
					cout << "                                                     Injured Ship!" << endl;
					injuredcountfornickname++;
					comp[x][int(y) - 65 + 1] = -1;
					/*MainDesk(nickname, destroyedcountfornickname, injuredcountfornickname, destroyedcountforcomp, injuredcountforcomp);*/
					cout << "                                                     ------------------------" << endl;
				}
				else {
					cout << "                                                     Missed Enemy's Ship!" << endl;
					cout << "                                                     ------------------------" << endl;
				}
				if (x > 12 || y > 'M') {
					cout << "                                                     Wrong Input! Try Again in another turn!" << endl;
					cout << "                                                     ---------------------------------------" << endl;
					Sleep(1500);
				}
			}
			else {
				cout << "                                                     It is Computer Turn!" << endl;
				cout << "                                                     Computer chooses his own XY Locations.." << endl;
				Sleep(3200);
				x = rand() % s;
				int y_i = rand() % s + 1;
				resultofshoot = ShootFunction2(game, x, y_i, Ships);
				if (game[x][y_i] == -1) {
					cout << "                                                     Comp, you Typed This Location! Try it Again in another turn!" << endl;
					cout << "                                                     ------------------------------------------------------------" << endl;
					Sleep(800);
				}
				if (resultofshoot == 2) {
					cout << "                                                     Destroyed Ship!" << endl;
					destroyedcountforcomp++;
					injuredcountforcomp++;
					game[x][y_i] = -1;
					cout << "                                                     ------------------------" << endl;
					if (destroyedcountforcomp == 9) {
						cout << "                                                     " << "Computer " << " Wins!" << endl;
						cout << endl;
						cout << endl;
						system("pause");
						system("cls");
						BattleShip();
					}

					/*MainDesk(nickname, destroyedcountfornickname, injuredcountfornickname, destroyedcountforcomp, injuredcountforcomp);*/
				}
				else if (resultofshoot == 1) {

					cout << "                                                     Injured Ship!" << endl;
					injuredcountforcomp++;
					game[x][y_i] = -1;
					/*MainDesk(nickname, destroyedcountfornickname, injuredcountfornickname, destroyedcountforcomp, injuredcountforcomp);*/
					cout << "                                                     ------------------------" << endl;
				}
				else {
					cout << "                                                     Missed Enemy's Ship!" << endl;
					cout << "                                                     ------------------------" << endl;
				}
			}
			/*if (resultofshoot == 2) {
				cout << "    Congratulations!. Destroyed Ship! ( 1 point to you)" << endl;
				cout << "   ----------------------------------------------------" << endl;
			}
			else if (resultofshoot == 1) {
				cout << "    Injured Ship!" << endl;
				cout << "   ------------------------" << endl;
			}
			else {
				cout << "    Missed Enemy's Ship!" << endl;
				cout << "   ------------------------" << endl;
			}*/
			Sleep(800);
			turn = !turn;
		}
	}
	else if (selection == 'r' || selection == 'R') {
		system("cls");
		ShowDescribtion();
		cout << endl;
		cout << endl;
		cout << "  ";
		system("pause");
		system("cls");
	}
	else {
		// Else
		system("cls");
	}


}
