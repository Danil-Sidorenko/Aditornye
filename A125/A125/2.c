#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num_of_numbers;
	int *mass, *prime_numbers;
	printf_s("Enter number of numbers: ");
	scanf_s("%d", &num_of_numbers);
	mass = (int*)malloc(num_of_numbers * sizeof(int));
	prime_numbers = (int*)malloc(num_of_numbers * sizeof(int));
	printf_s("Enter all numbers:\n");
	for (int i = 0; i < num_of_numbers; i++)
	{
		scanf_s("%d", &mass[i]);
		if (mass[i] < 0 || mass[i] == 0) { printf_s("!ALL NUMBER MUST BE POSITIV AND BIGGER THAN 1!"); system("pause"); return 0; }
	}
	for (int i = 0; i < num_of_numbers; i++)
	{
		int counter = 0, tmp = 1, num = 0;
		while (num != mass[i])
		{
			counter = 0;
			tmp++;
			for (int j = 2; j < tmp; j++)
			{
				if ((tmp % j) == 0) { j = tmp; }
				if ((tmp % j) != 0) { counter++; }
			}
			if ((counter == (tmp - 2))) { num++; }
		}
		prime_numbers[i] = tmp;
	}
	printf_s("Prime numbers:\n");
	for (int i = 0; i < num_of_numbers; i++) { printf_s("%d ", prime_numbers[i]); };
	printf_s("\n");
	system("pause");
	return 0;
}