#define __CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

double amount(char*, ...);

void main()
{
	printf("Sum of three parameters is %.3f!\n\n", amount("213", 2222, -2222, 1000.575));
	printf("But...really is %.3f!\n\n", (2222 - 2222 + 1000.575));
	return;
}

double amount(char* format, ...)
{
	va_list arg_ptr;														// ������ ����������
	va_start(arg_ptr, format);												// ������������� ��������� �� ������ �������
	char type;																// ���������� ���� ���������� ���������
	int length = strlen(format);
	double sum = 0;
	while (*format)
	{
		type = *format++;
		switch (type)
		{
		case '1':
			sum += va_arg(arg_ptr, int);
			printf("sum1 = %.3f\n", sum);
			break;
		case '2':
			sum += va_arg(arg_ptr, unsigned long);
			printf("sum2 = %.3f\n", sum);
			break;
		case '3':
			sum += va_arg(arg_ptr, double);
			printf("sum3 = %.3f\n", sum);
			break;
		}
	}
	va_end(arg_ptr);
	return sum;
}