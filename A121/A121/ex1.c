#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef struct {
	int a;
	int b;
	int abs;
}complex;
int main()
{
	FILE* in;
	fopen_s(&in, "input.txt", "r");
	fseek(in, 0, SEEK_SET);
	int number = 0, x = 0,y=0,abs=0,max=0,count=0;
	fscanf_s(in, "%d", &number);
	complex* comp = (complex*)malloc(number * sizeof(complex));
	for (int i = 0; i < number; i++)
	{
			fscanf_s(in, "%d", &x);
			fscanf_s(in, "%d", &y);
			comp[i].a = x;
			comp[i].b = y;
			comp[i].abs = x*x+y*y;
	}
	printf_s("\n");
	for (int i = 0; i < number; i++)
	{
		if (comp[i].b < 0) { printf_s("%d%di\n\n", comp[i].a, comp[i].b); }
		else { printf_s("%d+%di\n\n", comp[i].a, comp[i].b); }
	}
	for (int i = 0; i < number; i++)
	{
		if (comp[i].abs > max)
		{
			max = comp[i].abs;
			count = i;
		}
	}
	printf_s("Max: ");
	if (comp[count].b < 0)
	{
		printf_s("%d%di\n", comp[count].a, comp[count].b);
	}
	else
	{
		printf_s("%d+%di\n", comp[count].a, comp[count].b);
	}
	free(comp);
	fclose(in);
	system("pause");
	return 0;
}