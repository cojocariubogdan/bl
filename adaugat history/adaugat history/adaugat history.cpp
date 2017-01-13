#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>


using namespace std;

const string suitnames[4] = { "spades", "diamonds", "clubs", "hearts" };
const string ranknames[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

bool isDealt[52];
int deck[52];
void amestecare(bool isDealt[]);
int value(int number);
void playerVScomputer(int deck[], char *name1, int &amount);
int ScoreHand(int Hand[], int number);
void printCards(int deck[], int i);
int GetNewCard(bool isDealt[]);
void PrintHand(int Hand[], int number);
int minim(int a, int b, int c);
void wins(const char * output_file_name);
void loses(const char * output_file_name);
void draw(const char *output_file_name);
int countf(const char *input_file_name);
void history(const char *input_file_name);

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

	while (atoi(option) < 1 || atoi(option) > 5)
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

		char valid;
		playerVScomputer(deck, name, amount);

		do
		{

			cout << "Doresti sa joci din  nou ?" << endl;
			cout << "      Da(d) / Nu(n)       " << endl;
			cin >> valid;
			system("cls");
			if (valid == 'n' || valid == 'N')
				break;
			playerVScomputer(deck, name, amount);

		} while (valid == 'd' && amount != 0);
		if (amount == 0)
			cout << "Imi pare rau , dar ai pierdut toti bani!!!" << endl;
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
	if (option[0] == '4')
	{
		history("scores.txt");
		cout << "Apasati enter pentru a continua!!" << endl;
		cin.get();
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
void wins(const char * output_file_name)
{
	ofstream fout(output_file_name, ios::app);
	fout << "1" << endl;
	fout.close();
}

void loses(const char * output_file_name)
{
	ofstream fout(output_file_name, ios::app);
	fout << "0" << endl;
	fout.close();
}

void draw(const char *output_file_name)
{
	ofstream fout(output_file_name, ios::app);
	fout << "2" << endl;
	fout.close();
}
void playerVScomputer(int deck[], char *name, int &amount)
{
	int bet;

	cout << "Cat vrei sa pariezi?" << endl;
	cin >> bet;

	while (bet < 0 || bet > amount)
	{
		cout << "Introduceti o suma intre 1$ - " << amount << endl;
		cin >> bet;
	}
	cin.get();
	cin.get();
	system("cls");

	amestecare(isDealt);

	int HouseHand[12];
	int HouseCards = 0;
	int PlayerHand[12];
	int PlayerCard = 0;
	int score = 0;
	int houseScore = 0;


	PlayerHand[0] = GetNewCard(isDealt);
	PlayerHand[1] = GetNewCard(isDealt);
	HouseHand[0] = GetNewCard(isDealt);
	HouseHand[1] = GetNewCard(isDealt);

	PlayerCard += 2;
	HouseCards += 2;
	score = ScoreHand(PlayerHand, PlayerCard);
	houseScore = ScoreHand(HouseHand, HouseCards);
	cout << "****************************" << endl;
	cout << "Hai sa incepem!! " << endl;
	cout << "****************************" << endl;
	cin.get();
	system("cls");

	cout << "Primele 2 carti sunt :" << endl;
	PrintHand(PlayerHand, PlayerCard);
	cout << "Punctele tale sunt :" << score;
	cout << "\n\n\n";

	cout << "A doua carte a dealarului este :" << endl;
	printCards(deck, HouseHand[1]);
	cout << "\n\n\n";


	char choice;
	bool hit = false;

	do
	{
		cout << "\n Doresti o alta carte?" << endl;
		cout << "     Da (d) / Nu (n)      " << endl;
		cout << "Introdu alegerea ta !" << endl;
		cin >> choice;

		if (choice == 'n' || choice == 'N')
			break;
		if (choice == 'd' || choice == 'D')
			hit = true;

		PlayerHand[PlayerCard] = GetNewCard(isDealt);
		PlayerCard++;

		system("cls");

		cout << "Ai primit o noua carte!" << endl;
		cout << "Cartile tale de pana acum sunt: " << endl;
		PrintHand(PlayerHand, PlayerCard);
		cout << endl;


		score = ScoreHand(PlayerHand, PlayerCard);
		cout << "Scorul tau pana acum este:  " << score << '\n';
	} while (hit && score < 22);

	cin.get();
	system("cls");
	PrintHand(PlayerHand, PlayerCard);
	cout << "Scorul tau este: " << score << "! \n\n\n";

	if (score > 21)
	{
		cout << "Imi pare rau. Ai pierdut!!! " << endl;
		cout << "Ai pierdut :" << bet << "$!" << endl;
		amount = amount - bet;
		loses("scores.txt");
		cout << endl << endl << endl;
		return;
	}


	if (houseScore >= 17)
	{
		cout << "\n\n\n";
		cout << "Cartile dealarului sunt: \n";
		PrintHand(HouseHand, HouseCards);
		houseScore = ScoreHand(HouseHand, HouseCards);
		cout << "Scorul dealarului este " << houseScore;
		cout << endl << endl << endl;
	}

	if (houseScore < 17)
	{
		while (houseScore < 17)
		{
			HouseHand[HouseCards] = GetNewCard(isDealt);
			HouseCards++;
			houseScore = ScoreHand(HouseHand, HouseCards);
		}
		cout << "Cartile dealerului sunt :" << endl;
		PrintHand(HouseHand, HouseCards);
		cout << "\n Scorul dealarului este: " << houseScore << endl;
		cout << endl << endl << endl;

	}

	if (houseScore > 21)
	{
		cout << "Felicitari!! Ai castigat :" << bet << "$!" << endl;
		amount = amount + bet;
		wins("scores.txt");
		return;
		cout << endl << endl << endl;

	}

	houseScore = ScoreHand(HouseHand, HouseCards);
	if (score == houseScore)
	{
		cout << "Este egalitate! \n";
		cout << endl << endl << endl;
		draw("scores.txt");

	}
	else
		if (score == 21 && houseScore != 21)
		{
			cout << "Felicitari tocmai ai castigat cu 21 de puncte!!!!!!" << endl;
			cout << "Ai castigat:" << bet << "$ !" << endl;
			amount = amount + bet;
			wins("scores.txt");
			cout << endl << endl << endl;

		}
		else
			if (houseScore == 21 && score != 21)
			{
				cout << "Imi pare rau ai pierdut!!!!" << endl;
				cout << "Ai pierdut: " << bet << "$ !" << endl;
				amount = amount - bet;
				loses("scores.txt");
				cout << endl << endl << endl;

			}
			else
				if (21 - score > 21 - houseScore)
				{
					cout << "Imi pare rau ai pierdut!!! " << endl;
					cout << "Ai pierdut:" << bet / 2 << "$ !" << endl;
					amount = amount - bet / 2;
					loses("scores.txt");
					cout << endl << endl << endl;


				}
				else
					if (21 - score < 21 - houseScore)
					{
						cout << "Bravo!!! Ai castigat!! " << endl;
						cout << "Ai castigat: " << bet << "$! " << endl;
						wins("scores.txt");
						cout << endl << endl << endl;

					}


}
int countf(const char *input_file_name)
{
	ifstream fin(input_file_name, ios::in);
	int nr = 0;
	while (!fin.eof())
	{
		char c;
		fin.get(c);
		if (isdigit(c))
			nr++;
	}
	fin.close();
	return nr;
}

void history(const char * input_file_name)
{
	ifstream fin("scores.txt", ios::in);
	int number = countf("scores.txt");
	while (!fin.eof())
	{
		char c;
		fin.get(c);

		if (c == '0')
		{
			cout << number << ") INFRANGERE!!" << endl;
			number--;
		}
		else
			if (c == '1')
			{
				cout << number << ") VICTORIE" << endl;
				number--;
			}
			else
				if (c == '2')
				{
					cout << number << ") EGALITATE" << endl;
					number--;
				}
	}
	fin.close();
}