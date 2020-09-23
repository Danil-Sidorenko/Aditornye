#include<stdio.h>
#include<math.h>
int main()
{
	int a, r;
	float result;
	printf_s("Enter a and r:\n");
	scanf_s("%d %d", &a, &r);
	result = a * sqrt(4 * pow(r, 2) - pow(a, 2)) + pow(r, 2)*(3.1415926535 - 4 * asin(sqrt(1 - (pow(a, 2) / (4 * pow(r, 2))))));
	printf_s("%.3f\n", result);
	system("pause");
	return 0;
}
