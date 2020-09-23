#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>
typedef struct
{
	int age;
	char *name;
}persons;
int main()
{
	setlocale(LC_ALL, "RISSIAN");
	FILE* in;
	fopen_s(&in, "persons.txt", "r");
	int num_of_persons = 0;
	char letter=0;
	fseek(in, 0, SEEK_SET);
	fscanf_s(in, "%d", &num_of_persons);
	printf("Number of persons: %d\n", num_of_persons);
	persons *person = (persons*)malloc(num_of_persons * sizeof(persons));
	int *length = (int*)malloc(num_of_persons * sizeof(int));
	int i = 0;
	fseek(in, 3, SEEK_CUR);
	length[i] = 1;
	while (!feof(in))
	{
		fscanf_s(in, "%c", &letter, 1);
		length[i]++;
		if ((letter == '\n'))
		{
			i++;
			length[i] = 1;
		}
	}
	for (int i = 0; i < num_of_persons; i++)
	{
		person[i].name = (char*)malloc((length[i]-3) * sizeof(char));
	} 
	printf("\n");
	fseek(in, 0, SEEK_SET);
	fscanf_s(in, "%d", &num_of_persons);
	for (int i = 0; i < num_of_persons; i++)
	{
		fscanf_s(in, "%d", &person[i].age);
		printf("%d", person[i].age);
		fgets(person[i].name, length[i], in);
		printf("%s", person[i].name);
		printf("\n");
	}
	int max = 0,index=0;
	for (int i = 0; i < num_of_persons; i++)
	{
		if (person[i].age > max)
		{
			max = person[i].age;
			index = i;
		}
	}
	printf_s("\nThe most adult here: %d %s\n", person[index].age, person[index].name);
	system("pause");
	return 0;
}