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
int ScoreHand(int Hand[], int number);
void printCards(int deck[], int i);
int GetNewCard(bool isDealt[]);
void PrintHand(int Hand[], int number);
int minim(int a, int b, int c);
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
	char option[1];

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

	while (atoi(option) < 1 || atoi(option) >5)
	{
		cout << "Enter a number between 1-5 ! " << endl;
		cin >> option;
	}


	if (option[0] == '1')
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
	char name[50];

	if (option[0] == '2')
	{
		cout << "Introdu numele cu care joci :" << endl;
		cin >> name;
		cout << "Introdu suma cu care vrei sa joci :" << endl;
		cin >> amount;
		cout << "Suma pe care o ai in acest moment este :" << amount << "$" << endl;

	}
	int money1 = 0;
	int money2 = 0;
	char name1[50], name2[50];

	if (option[0] == '3')
	{
		system("cls");
		cout << "Ai ales modul jucator vs jucator!!!!" << endl;
		cout << "Introduceti numele primului jucator : " << endl;
		cin >> name1;
		cout << "Introduceti numele celui de-al doilea jucator: " << endl;
		cin >> name2;
		cout << endl;
		cout << "Introduceti suma cu care vrea primul si al doilea jucator sa joace:" << endl;
		cin >> money1;
		money2 = money1;
		cout << "Sunteti amandoi inregistrati cu suma:" << money1 << " $" << endl;

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
int ScoreHand(int Hand[], int number)
{
	int i;
	int score = 0;
	int aces = 0;
	for (i = 0; i<number; i++)
	{
		int valuen = value(Hand[i]);
		if (valuen == 1)
			aces++;
		score = score + valuen;
	}

	while (aces > 0 && score < 12)
	{
		aces = aces - 1;
		score = score + 10;
	}
	return score;
}

void PrintHand(int Hand[], int number)
{
	for (int i = 0; i<number; i++)
		printCards(deck, Hand[i]);
}

int GetNewCard(bool isDealt[])
{
	bool isCard = true;
	int NewCard;
	do
	{
		NewCard = rand() % 52;
		if (!isDealt[isCard])
			isCard = false;
	} while (isCard);
	return NewCard;
}
void printCards(int deck[], int i)
{
	int suitnumber = deck[i] / 13;
	int rank = deck[i] % 13;
	cout << ranknames[rank] << " of " << suitnames[suitnumber];
	cout << "\n";

}
int minim(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return a;
		else
			return c;
	}
	else
	{
		if (b < c)
			return b;
		else
			return c;
	}
}


