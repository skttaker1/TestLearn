#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef struct Table
{
	int* data;
	int Len;
}table_node;

typedef struct Block
{
	int max;
	int post;
}index_t;

table_node* creatEmptyTable()
{
	table_node* p = malloc(sizeof(table_node));
	if (p == NULL)
	{
		printf("ERR!!\n");
		return NULL;
	}

	p->data = malloc(N * sizeof(int));
	if (p == NULL)
	{
		printf("ERR!!\n");
		return NULL;
	}

	p->Len = 0;
	return p;
}

int enTable(table_node* p, int num)
{
	if (p->Len >= N)
	{
		printf("ERR!!Table is FULL!\n");
		return -1;
	}
	p->Len++;
	p->data[p->Len] = num;

	return 0;
}

int findByOrder(table_node* p, int key)
{
	int i;
	p->data[0] = key;
	for (i = p->Len; p->data[i] != key; --i)
	{
		//printf("%d %d\n", p->data[i], i);
	}
		return i;
}

int findByHalf(table_node* p, int x)
{
	p->data[0] = x;
	int low = 1, high = N;
	int middle;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (p->data[middle] == x)
			return middle;
		else if (p->data[middle] > x)
			high = middle - 1;
		else
			low = middle + 1;
	}
	return -1;
}



int main(int argc, const char* argv[])
{
	table_node* t = creatEmptyTable();
	enTable(t, 11);
	enTable(t, 22);
	enTable(t, 33);
	enTable(t, 44);
	enTable(t, 55);
	/*for (int i = 0; i <= N; i++)
	{
		printf("%d ", t->data[i]);
	}
	printf("\n--------\n");*/

	printf("%d in order\n", findByOrder(t, 22));
	printf("%d in halfOrder\n", findByHalf(t, 22));
	

	return 0;
}