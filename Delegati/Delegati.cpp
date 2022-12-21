
#include <stdio.h>
#include <stdlib.h>


typedef void (*funcDef)(int, int);

void add(int x, int y)
{
	printf("\n c = %d", x + y);
}

void sub(int x, int y)
{
	printf("\n c = %d", x - y);
}
void mul(int x, int y)
{
	printf("\n c = %d", x * y);
}
funcDef* addOne(funcDef* array, long long number, funcDef method) {
	funcDef* ptr1 = (funcDef*)malloc(sizeof(funcDef) * (number + 1));
	if (ptr1)
	{
		for (long long i = 0; i < number; i++) {
			ptr1[i] = array[i];
		}
		ptr1[number] = method;
	}
	return ptr1;
}

int isMethod(funcDef* method, funcDef* ptr, long long number)
{
	for (long long i = 0; i < number; i++)
	{
		if (method == add || method == sub || method == mul)
		{
			if (ptr[i] == method)
			{
				return 1;
			}
		}
		else 
			return 1;
	}
	return 0;
}

funcDef* deleteRepeat(funcDef* ptr, long long number) 
{
	int n = 0, j = 0;
	funcDef* ptr2 = (funcDef*)malloc(sizeof(funcDef) * number);
	for (long long i = 0; i < number; i++)
	{
		if (!isMethod(ptr[i], ptr2,number))
		{
			ptr2[j] = ptr[i];
			n++;
			j++;
		}
	}
	funcDef* ptr1 = (funcDef*)malloc(sizeof(funcDef) * (number - n -1));
	if (ptr1)
	{
		for (long long i = 0; i < number; i++)
		{
			if (ptr[i] == add || ptr[i] == sub || ptr[i] == mul)
			{
				ptr1[i] = ptr2[i];
			}
		}
		return ptr1;
	}
	return ptr1;
}

void deleteAll(funcDef* array, long long number)
{
	for (long long i = 0; i < number; i++) 
	{
		array[i] = NULL;
	}
}


void main(void)
{
	system("chcp 1251>nul");
	int a = 8;
	int b = 3;
	funcDef* ptr;

	funcDef funcArray[3];
	long long l = sizeof(funcArray) / sizeof(funcArray[0]);
	funcArray[0] = add;
	funcArray[1] = sub;
	funcArray[2] = mul;
	for (int i = 0; i < 3; i++) {
		funcArray[i](a, b);
	}

	printf("\nОпределен новый тип данных\n");

	ptr = addOne(funcArray, l, add);

	for (int i = 0; i <= l; i++) {
		ptr[i](a, b);
	}
	printf("\nДобавление функции\n");	
	l++;
	ptr = addOne(ptr, l, add);

	l++;
	ptr = addOne(ptr, l, add);

	l++;
	ptr = addOne(ptr, l, sub);

	l++;
	ptr = addOne(ptr, l, add);

	l++;
	ptr = addOne(ptr, l, mul);
	l++;
	for (int i = 0; i < (l); i++) {
		ptr[i](a, b);
	}
	printf("\nДобавление повторных функций для удаления\n");

	ptr = deleteRepeat(ptr, l);
	for (int i = 0; i < l; i++) {
		if (!(ptr[i] == add || ptr[i] == sub || ptr[i] == mul))
		{
			l--;
			continue;
		}
		ptr[i](a, b);
		l--;
	}
	l--;
	printf("\nУдаление повторных функций\n");

	deleteAll(ptr, l);
	for (int i = 0; i < l; i++) {
		if (!(ptr[i] == add || ptr[i] == sub || ptr[i] == mul))
		{
			continue;
		}
		ptr[i](a, b);
	}
	printf("\nМассив указателей на функцию полностью удален\n");
	system("pause");
}