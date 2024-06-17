#include<stdio.h>
#include<stdlib.h>

int hashFunc(int num)
{
	int post = num - 1;
	return post;
}

void saveHash(int* p, int age, int amount)
{
	int post = hashFunc(age);
	p[post] = amount;
}

int getHash(int* p, int age)
{
	int post = hashFunc(age);
	return p[post];
}

int main()
{
	int hash_list[150] = { 0 };
	int num, age;
	for (int i = 0; i < 5; i++)
	{
		printf("plz enter the num of the age\n");
		scanf_s("%d %d", &num, &age);
		saveHash(hash_list, age, num);
	}
	for (int i = 0; i < 5; i++)
	{
		printf("plz enter the age what u want!\n");
		scanf_s("%d", &age);
		printf("%d age people have %d!!\n", age , getHash(hash_list, age));
	}

	return 0;
}
