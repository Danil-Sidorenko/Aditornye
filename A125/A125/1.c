#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <Windows.h>
#define STR1 30
#define STR2 40
void Hide_Cursor()
{
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
void GotoXY(int x, int y)
{
	COORD coordinates;
	coordinates.X = (short)x;
	coordinates.Y = (short)y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
int main() 
{
	Hide_Cursor();
	srand(time(NULL));
	DWORD delay = 72;
	char matrix[STR1][STR2];
	int c = 0;
	GotoXY(0, 0);
	for (int i = 0; i < STR1; i++) {
		for (int j = 0; j < STR2; j++) {
			matrix[i][j] = ' ';
			printf_s("%c ", matrix[i][j]);
		}
		GotoXY(0, i);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	do {
		for (int i = 1; i < STR1; i++) 
		{
			GotoXY(0, i - 1);
			for (int j = 0; j < STR2; j++) 
			{
				matrix[i - 1][j] = matrix[i][j];
				GotoXY(j, i - 1);
				printf_s("%c", matrix[i][j]);
			}
		}
		GotoXY(0, STR1 - 1);
		for (int j = 0; j < STR2; j++)
		{
			int k = rand() % 5;
			if (k > 2) { matrix[STR1 - 1][j] = 32 + rand() % (255 - 31); }
			else { matrix[STR1 - 1][j] = ' '; }
			printf_s("%c", matrix[STR1 - 1][j]);
		}
		Sleep(delay);
	} while (c == 0);
	getchar();
	return 0;
}
