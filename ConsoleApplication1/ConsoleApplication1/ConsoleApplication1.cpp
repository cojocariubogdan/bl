#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <string.h>


using namespace std;

const string suitnames[4] = { "spades", "diamonds", "clubs", "hearts" };
const string ranknames[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

bool isDealt[52];
int deck[52];
void amestecare(bool isDealt[]);
int value(int number);
void intro();
void rules();

int main()
{
	srand(time(NULL));
	intro();
	cout << "Apasati ENTER pentru a contiunua!" << endl;
	cin.get();
	int  i;
	for (i = 0; i < 52; i++)
		deck[i] = i;

	int amount;
	int option;

	system("COLOR 6");
asd:   cout << "Selecteaza optiunea: " << endl;
	cout << "            _________________________________" << endl;
	cout << "            |1. Reguli                       |" << endl;
	cout << "            |2. Jucator vs. Calculator       |" << endl;
	cout << "            |3. Jucator vs. Jucator          |" << endl;
	cout << "            |4. Istoric                      |" << endl;
	cout << "            |5. Jucator vs. Jucator istoric  |" << endl;
	cout << "            |________________________________|" << endl;
	cin >> option;


	while (option < 1 || option >5)
	{
		cout << "Introduceti un numar intre 1 si 5!!!! " << endl;
		cin >> option;
	}


	if (option == 1)
	{
		rules();
		cout << endl;
		cout << "Apasati ENTER pentru a merge la meniu!" << endl;
		cin.get();
		cout << endl;
		cin.get();
		system("cls");
		goto asd;
	}

}
int value(int number)
{
	int value = 0;
	int rest = number % 13;

	if (rest == 0)
		value = 1;
	else
		if (rest >= 1 && rest <= 9)
			value = rest + 1;
		else
			value = 10;

	return value;

}
void intro()
{
	system("COLOR 1");




	cout << " _____  __                _                          _           " << endl;
	cout << "(_____)(__)              (_) _      _               (_) _        " << endl;
	cout << "(_)__(_)(_)  ____    ___ (_)(_)    (_)  ____    ___ (_)(_)       " << endl;
	cout << "(_____) (_) (____) _(___)(___)      _  (____) _(___)(___)        " << endl;
	cout << "(_)__(_)(_)( )_( )(_)___ (_)(_)    (_)( )_( )(_)___ (_)(_)       " << endl;
	cout << "(_____)(___)(__)_) (____)(_) (_)_  (_) (__)_) (____)(_) (_)      " << endl;
	cout << "                               ( )_(_)                           " << endl;
	cout << "                                (___)                            " << endl;
}
void rules()
{
	system("COLOR 4");
	cout << "     _________________R_E_G_U_L_I__________________" << endl;
	cout << "     ##############################################" << endl;
	cout << "     Blackjack este un joc popular din America, obiectivul" << endl;
	cout << "     jocului este atingerea unui scor cat mai apropiat de 21. " << endl;
	cout << "     Acest lucru trebuie realizat fara a depasi aceasta valoare," << endl;
	cout << "     in caz contrar mana fiind considerata depasita " << endl;
	cout << "     Daca nu ajungi la 21, obiectivul jocului este  " << endl;
	cout << "     sa obtii un scor mai mare decat al calculatorului respectiv a jucatorului." << endl;
	cout << "     ________________________________________________" << endl;
}
void amestecare(bool isDealt[])
{
	for (int i = 0; i<52; i++)
		isDealt[i] = false;
}

