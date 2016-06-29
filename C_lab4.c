#define __CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

float amount(char*, ...);

void main()
{
	printf("Sum of three parameters is %.3f!\n\n", amount("123", 2999998, 100, 3.575));
	printf("But...really is %.3f!\n\n", ( 1 + 2999998 + 3.575));
	return;
}

float amount(char* format, ...)
{
	va_list arg_ptr;														// список аргументов
	char type;																// переменная типа очередного параметра
	int i,
		length = strlen(format);
	float sum = 0;
	for (i = 0; i < length; i++)
	{
		va_start(arg_ptr, format);											// Устанавливаем указатель на первый элемент
		type = format[i];
		switch (type)
		{
		case '1':
			sum += va_arg(arg_ptr, int);
			break;
		case '2':
			sum += va_arg(arg_ptr, long);
			break;
		case '3':
			sum += va_arg(arg_ptr, float);
			break;
		}
	}
	va_end(arg_ptr);
	return sum;
}