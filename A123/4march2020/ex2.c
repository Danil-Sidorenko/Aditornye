#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h>
int Get_Length(char *string)
{
	int i = 0;
	while (string[i] != '\0') { i++; }
	return i;
}
int main(int argc, char*argv[])
{
	if (argc == 1)
	{
		system("pause");
		return 0;
	}
	setlocale(LC_ALL, "Russian");
	printf_s("Using words:\n");
	for (int i = 1; i < argc; i++)
	{
		puts(argv[i]);
		argv[i][0] = tolower(argv[i][0]);
	}
	int sovp1=0,sovp2=0;
	for (int i = 1, sovp1 = 0; i < argc - 1; i++)
	{
		int len1 = Get_Length(argv[i]), len2 = Get_Length(argv[i+1]);
		if (argv[i][len1 - 1] == argv[i + 1][0]) { sovp1++; }
		if (argv[i][0] == argv[i + 1][len2 - 1]) { sovp2++; }
	}
	if (((argc - 2) == sovp1) || ((argc - 2) == sovp2)) { printf_s("\n--> YES <--\n"); }
	else { printf_s("\n--> NO <--\n"); }
	system("pause");
	return 0;
	}