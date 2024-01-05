#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<ctime>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int arr[8][8] = { 0 }, player = 1, r_in = 7;


void board() {
	system("cls");
	SetConsoleTextAttribute(h, 6);
	for (int i = 1; i <= 8; i++)
	{
		SetConsoleTextAttribute(h, 1);
		cout << " _";
		SetConsoleTextAttribute(h, 6);
		cout << i;
		SetConsoleTextAttribute(h, 1);
		cout << "_ ";
	}
	cout << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] == 0) {
				SetConsoleTextAttribute(h, 1);
				cout << "|   |";
			}
			else if (arr[i][j] == 1) {
				SetConsoleTextAttribute(h, 1);
				cout << "|";
				SetConsoleTextAttribute(h, 12);
				cout << " X ";
				SetConsoleTextAttribute(h, 1);
				cout << "|";
			}
			else {
				SetConsoleTextAttribute(h, 1);
				cout << "|";
				SetConsoleTextAttribute(h, 10);
				cout << " O ";
				SetConsoleTextAttribute(h, 1);
				cout << "|";
			}
		}
		cout << endl;
	}
	SetConsoleTextAttribute(h, 1);
	cout << "----------------------------------------\n\n";
}

void play(int p) {
	if (r_in >= 0 && p <= 7) {
		if (arr[r_in][p] != 0) {
			r_in--;
			play(p);
		}
		else {
			arr[r_in][p] = player;
			r_in = 7;
		}
	}
	else {
		(player == 1) ? player = 2 : player = 1;
		r_in = 7;
	}
}

int winner() {
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j <= 4; j++) {
			if (arr[i][j] == player && arr[i][j + 1] == player && arr[i][j + 2] == player && arr[i][j + 3] == player) {

				return player;
			}


		}
	}
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] == player && arr[i + 1][j] == player && arr[i + 2][j] == player && arr[i + 3][j] == player) {
				return player;
			}

		}
	}


	for (int i = 0; i <= 4; i++)
	{
		for (int j = 3; j < 8; j++) {
			if (arr[i][j] == player && arr[i + 1][j - 1] == player && arr[i + 2][j - 2] == player && arr[i + 3][j - 3] == player) {

				return player;
			}

		}
	}

	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++) {
			if (arr[i][j] == player && arr[i + 1][j + 1] == player && arr[i + 2][j + 2] == player && arr[i + 3][j + 3] == player) {

				return player;
			}

		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] != 0)
				count++;
		}
	}
	if (count == 64) {

		return 3;
	}
	return 0;
}

int main() {
	char x;
	SetConsoleTextAttribute(h, 6);
	do {
		system("cls");
		cout << "            =============" << endl;
		cout << "//////////// H E L L O ! \\\\\\\\\\\\\\\\\\\\\\\\\n";
		cout << "            =============" << endl;
		cout << "\nPlay vs anoter player press 1\n";
		cout << "Play vs computer press 2 \n";
		int your_press;
		cin >> your_press;
		if (your_press == 1) {
			int pos;
			board();
			while (winner() == 0) {
				SetConsoleTextAttribute(h, 6);
				cout << "Choose your position player " << player << " : ";
				cin >> pos;

				play(pos - 1);
				board();
				winner();
				if (winner() == 0)
					(player == 1) ? player = 2 : player = 1;
			}
			if (winner() == 1)
			{
				SetConsoleTextAttribute(h, 12);
				cout << "player 1 winner\n";
			}
			else if (winner() == 2)
			{
				SetConsoleTextAttribute(h, 10);
				cout << "player 2 winner\n";
			}
			else
			{
				SetConsoleTextAttribute(h, 12);
				cout << " draw between two players\n";

			}

		}
		else if (your_press == 2) {
			int pos;
			board();
			while (winner() == 0) {
				SetConsoleTextAttribute(h, 6);
				cout << "Choose your position player " << player << " : ";
				if (player == 1)
					cin >> pos;
				else if (player == 2) {
					srand(time(0));
					pos = rand() % 8 + 1;
				}
				play(pos - 1);
				board();
				winner();
				if (winner() == 0)
					(player == 1) ? player = 2 : player = 1;
			}
			if (winner() == 1)
			{
				SetConsoleTextAttribute(h, 12);
				cout << "player 1 winner\n";
			}
			else if (winner() == 2)
			{
				SetConsoleTextAttribute(h, 10);
				cout << "computer win\n";
			}
			else
			{
				SetConsoleTextAttribute(h, 12);
				cout << " draw between two players\n";

			}

		}
		SetConsoleTextAttribute(h, 6);
		cout << "\nDo you want to play again [ y / n ] ? ";
		cin >> x;
		if (x == 'y') {
			for (int k = 0; k < 8; k++)
				for (int w = 0; w < 8; w++)
					arr[k][w] = 0;

			player = 1;
		}
		else if (x == 'n') {
			SetConsoleTextAttribute(h, 6);
			cout << "Thanks for playing our game... \n";
		}
	} while (x == 'y');
	system("pause");
}
