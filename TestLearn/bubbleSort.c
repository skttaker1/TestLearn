#include<stdio.h>

void swch(int *a, int *b)
{
	int i = 0;
	i = *a;*a = *b;*b = i;
}



int main()
{
	int num[10] = { 0 };

	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d", &num[i]);
	}

	for (int i = 0; i < 10 - 1; i++)
	{
		for (int j = 0; j < 10 - i - 1; j++)
		{
			if (num[j] > num[j + 1]);
			{
				swch(&num[j], &num[j + 1]);
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", num[i]);
	}

	return 0;
}