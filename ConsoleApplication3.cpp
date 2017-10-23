// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"


int main()
{
	double a, b, d, h, x, sum, result;

	int k;

	printf("h = ");
	scanf_s("%lf", &h);

	printf("a = ");
    scanf_s("%lf", &a);

	printf("b = ");
	scanf_s("%lf", &b);

	printf("d = ");
	scanf_s("%lf", &d);

	printf("result=");

	for (x = a; x <= b+0.5*h; x += h)\
	{
		k = 1;
		sum = 0;
		result=1.0;

		do
		{
			result = (pow(-1,k)*sin(k*x))/k;
			sum += result;
			k++;
		}
		while (fabs(result > d));
		printf("x=%lf sum=%lf result=%lf\n", x, sum, result);
	}

	system("pause");
	return 0;

}

