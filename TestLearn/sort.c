#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swich(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertNum(int* p, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		p[i] = rand() % 50 + 1;
	}
}

void showArr(int* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}

void bubbleSort(int* p, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (p[j] > p[j + 1])
			{
				swich(&p[j], &p[j + 1]);
			}
		}
	}
}

void selectSort(int* p, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (p[i] > p[j])
			{
				swich(&p[i], &p[j]);
			}
		}
	}
		
}

void insertSort(int* p, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j > 0; j--)
		{
			if (p[j] < p[j - 1])
			{
				swich(&p[j], &p[j - 1]);
			}
			else
				break;
		}
	}
}

int main(int argc, char* argv[])
{
	int n;
	printf("please enter the amount of you want to insert:\n");
	scanf_s("%d", &n);

	int* p = (int*)malloc(n * sizeof(int));
	if (p == NULL) {
		printf("ERR!!!\n");
		return -1;
	}

	insertNum(p, n);
	printf("original arr is : \n");
	showArr(p, n);
	printf("-------varies sort resualt------------\n");

	/*bubbleSort(p, n);
	printf("bubble sort result:\n");
	showArr(p, n);

	selectSort(p, n);
	printf("select sort result:\n");
	showArr(p, n);*/

	insertSort(p, n);
	printf("insert sort result:\n");
	showArr(p, n);
		

	return 0;
}