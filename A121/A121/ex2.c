#include<stdio.h>
#include<conio.h>
#include<windows.h>
int main()
{
	int lengh, ch, flag=0;
	int *mass;
	printf_s("Enter the lengh of your password (up to 20 characters): ");
	scanf_s("%d", &lengh);
	printf_s("It may contains '0-9' '.,_-' 'A-Z' 'a-z'\n");
	mass = (int*)malloc(lengh * sizeof(int));
	int n = 0;
	do
	{
		ch = _getch();
		if ((ch == 13)||(ch == 8)|| (ch == 32) || ((ch >= 48)&(ch <= 57)) || ((ch >= 65)&(ch <= 90)) || (ch == 95) || (ch == 45) || (ch == 46) || (ch == 44) || ((ch >= 97)&(ch <= 122)))
		{
			if (ch == 8) { n--; printf_s("\b \b"); continue; }
			if (ch == 13) { flag = 1; break; }
			mass[n] = ch;
			printf_s("*");
			n = n + 1;
		}
		else
		{
			printf_s("\nYou entered invalid characters. Try again!");
			flag = 1;
			break;
		}
	} while (n != lengh);
	if (flag == 0)
	{
		printf_s("\nYour password:");
		for (int i = 0; i < lengh; i++)
		{
			printf_s("%c", mass[i]);
		}
	}
	printf_s("\n");
	free(mass);
	system("pause");
	return 0;
}