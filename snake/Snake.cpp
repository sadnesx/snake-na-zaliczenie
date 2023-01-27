#include<iostream>
#include<windows.h> 
#include<conio.h>
#include<ctime>
#include<cstdlib>

using namespace std;

const int wysokosc = 20;
const int szerokosc = 20;
bool gO;
int wazX, wazY, jedzenieX, jedzenieY, wynik;

int ogonX[100];
int ogonY[100];
int dlOgona;

enum Kierunek { STOP = 0, UP, DOWN, LEFT, RIGHT };
Kierunek dir;

void Setup();
void Draw();
void Input();
void Logic();

int main()
{

	Setup();
	while (!gO)
	{
		Draw();
		Input();
		Logic();
		Sleep(40);
	}
	return 0;
}

void Setup()
{
	srand(time(NULL));
	gO = false;
	dir = STOP;
	wazX = szerokosc / 2;
	wazY = wysokosc / 2;

	jedzenieX = rand() % szerokosc;
	jedzenieY = rand() % wysokosc;

}
void Draw()
{
	system("CLS");

	for (int i = 0; i <= szerokosc; i++)
	{
		cout << "#";
	}cout << endl;

	for (int i = 0; i <= wysokosc; i++)
	{
		for (int j = 0; j <= szerokosc; j++)
		{
			if (j == 0 || j == szerokosc) { cout << "#"; }
			else if (i == wazY && j == wazX) { cout << "O"; }
			else if (i == jedzenieY && j == jedzenieX) { cout << "X"; }
			else {
				bool print = false;

				for (int k = 0; k < dlOgona; k++)
				{
					if (i == ogonY[k] && j == ogonX[k])
					{
						cout << "o";
						print = true;
					}
				} if (!print) { cout << " "; }

			}
		}cout << endl;

	}

	for (int i = 0; i <= szerokosc; i++)
	{
		cout << "#";
	}cout << endl;
	cout << endl;
	cout << "WYNIK: " << wynik << endl;

}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			dir = UP;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		default:
			break;
		}
	}


}
void Logic()
{
	srand(time(NULL));
	int poprzedniX = ogonX[0];
	int poprzedniY = ogonY[0];

	ogonX[0] = wazX;
	ogonY[0] = wazY;

	int poprzedni2X;
	int poprzedni2Y;

	for (int i = 1; i < dlOgona; i++)
	{
		poprzedni2X = ogonX[i];
		poprzedni2Y = ogonY[i];
		ogonX[i] = poprzedniX;
		ogonY[i] = poprzedniY;
		poprzedniX = poprzedni2X;
		poprzedniY = poprzedni2Y;
	}

	switch (dir)
	{
	case UP:
		wazY--;
		break;

	case DOWN:
		wazY++;
		break;

	case LEFT:
		wazX--;
		break;

	case RIGHT:
		wazX++;
		break;
	defualt:
		break;
	}

	if (wazX<0 || wazX>szerokosc || wazY <0 || wazY>wysokosc) gO = true;

	for (int i = 0; i < dlOgona; i++)
	{
		if (wazX == ogonX[i] && wazY == ogonY[i]) gO = true;
	}

	if (wazX == jedzenieX && wazY == jedzenieY)
	{
		wynik += 5;
		jedzenieX = rand() % szerokosc;
		jedzenieY = rand() % wysokosc;
		dlOgona++;
	}

}