#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<time.h>
#define SIZE 1024
int main()
{
	DWORD size = SIZE;
	TCHAR uname[SIZE], cname[SIZE];
	LPSTR u=uname, c=cname;
	GetComputerNameA(c, &size);
	GetUserNameA(u, &size);
	printf("Username: %s\n", u);
	printf("Computer Name: %s\n", c);	
	time_t t = time(NULL);
	tm *current_time = localtime(&t);
	char days[][20] = { "Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday" };
	char months[][20] = { "January","February","March","April","May","June","Jule","August","September","October","November","December" };
	if (current_time->tm_min < 10){printf_s("Time: %d:0%d\n", current_time->tm_hour, current_time->tm_min);}
	else { printf_s("Time: %d:%d\n", current_time->tm_hour, current_time->tm_min); }
	printf_s("Date: %s, %s %d, %d\n", days[current_time->tm_wday], months[current_time->tm_mon], current_time->tm_mday, current_time->tm_year + 1900);
	system("pause");
	return 0;
}