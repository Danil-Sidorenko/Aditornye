#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
int main()
{
	char symbol=0;
	int tmp = 0, counter = 0, flag = 0;
	int mass[1000];
	while (symbol!='\n')
	{
		symbol = fgetc(stdin);
		if ((symbol>= '0') && (symbol <= '9'))
		{
		tmp = tmp*10 +(symbol - '0');
		flag = 1;
		}
		else
		{
			if (flag == 1)
			{
				mass[counter] = tmp;
				counter++;
				flag = 0;
				tmp = 0;
			}
		}
	}
	if (flag == 1)
	{
		mass[counter] = tmp;
		counter++;
	}
	for (int i = 0; i < counter; i++) { printf_s("%llu ", (unsigned long long)(mass[i] * mass[i])); }
	system("pause");
	return 0;
}