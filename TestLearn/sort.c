#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

void selectSort(int* p, int n)
{

		
}

int main()
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

	bubbleSort(p, n);
	printf("bubble sort result:\n");
	showArr(p, n);
		

	return 0;
}