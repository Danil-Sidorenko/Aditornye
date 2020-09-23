#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct
{
	float value;
	struct list *next;
}list;
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
list* Get_Last(list *l_head) 
{
	while (l_head->next) { l_head = l_head->next; }
	return l_head;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void Add_Random_Value(list *l_head)
{
	srand(time(NULL));
	list *l = Get_Last(l_head);
	l->next = (list*)malloc(sizeof(list));
	l = l->next;
	l->next = NULL;
	l->value = (float)rand();
}
void Add_Before_Value(list *l_head)
{
	srand(time(NULL));
	list *l = l_head;
	float val;
	printf_s("Enter the value to add a random value before: ");
	scanf_s("%f", &val);
	int n = 0,k=0;
	while (l->next)
	{
		k++;
		l = l->next;
		if (l->value == val) { n++; break; }
	}
	if (n == 0)
	{
		printf_s("\n!There is no such value to add before!\n");
		exit(0);
		system("pause");
	}
	n = 0;
	l = l_head;
	while (n < k - 1 && l->next) { l = l->next;	n++; }
	list *tmp, *p;
	tmp = (list*)malloc(sizeof(list));
	p = l->next;
	l->next=tmp;
	tmp->value = (float)rand();
	tmp->next = p;
	}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
list* Create_List(int n)
{
	list *l_head = NULL;
	list *l = NULL;
	l_head = (list*)malloc(sizeof(list));
	l = l_head;
	l->next = NULL;
	scanf_s("%f", &l->value);
	for (int i = 1; i < n; i++)
	{
		l->next = (list*)malloc(sizeof(list));
		l = l->next;
		l->next = NULL;
		scanf_s("%f", &l->value);
	}
	return l_head;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void Output_List(list *l_head)
{
	list *l = l_head;
	while (l != NULL) { printf("[%.3f] ", l->value); l = l->next; }
	printf_s("\n");
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int main()
{
	int a;
	printf_s("Enter the number of numbers in the list: ");
	scanf_s("%d", &a);
	printf_s("Enter the list items: ");
	list *l_head = Create_List(a);
	printf_s("\nYour start list:\n");
	Output_List(l_head);
	Add_Random_Value(l_head);
	Add_Before_Value(l_head);
	printf_s("Your changed list:\n");
	Output_List(l_head);
	system("pause");
	return 0;
}