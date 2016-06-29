#define __CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <varargs.h>
#include <stdio.h>

int amount(int, ...);

void main()
{
	int count;
	printf("Enter count of numbers: ");
	scanf("%d", &count);
	printf("\n Sum of %d numbers is %d!", count, amount(count));
	return;
}

int amount(int number, ...) 
{
	va_list args;															// ������ ����������
	int sum = 0;
	int testsum = 0;
	va_start(args, number);													// ������������� ��������� �� ������ �������
	while (number--) 
	{
		testsum += va_arg(args, int);										//������ ���������, �������� ��� ���������
		if (testsum >= sum) 
		{
			sum = testsum;
		}
		else 
		{
			exit(0);
		}
	}
	va_end(args);
}