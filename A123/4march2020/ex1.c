#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *mass1, *mass2;
	int length1,length2;
	printf_s("Enter a number of elements: ");
	scanf_s("%d", &length1);
	length2 = length1;
	mass1 = (int*)malloc(length1 * sizeof(int));
	printf_s("Enter %d elememts: ", length1);
	for (int i = 0; i < length1; i++) { scanf_s("%d", &mass1[i]); }
	for (int l = 0; l < length1; l++)
	{
		for (int i = 0; i < length1; i++)
		{
			int x = mass1[i];
			for (int j = i + 1; j < length1; j++)
			{
				if (x == mass1[j])
				{
					length1--;
					for (int k = j; k < length2 - 1; k++)
					{
						int tmp = mass1[k];
						mass1[k] = mass1[k + 1];
						mass1[k + 1] = tmp;
					}
				}
			}
		}
	}
	mass2 = (int*)malloc(length1 * sizeof(int));
	for (int i = 0; i < length1; i++) { mass2[i] = mass1[i]; }
	printf("Result: ");
	for (int i = 0; i < length1; i++) { printf_s("%d ", mass2[i]); }
	printf("\n");
	free(mass1);
	free(mass2);
	system("pause");
	return 0;
	}