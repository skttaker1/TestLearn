#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int num;
	char book_name[20];
}book_t;

int hashFunc(int key)
{
	int post = (key / 1000000 + key / 1000 % 1000 + key % 1000);
	return post;
}

void saveBookInfo(book_t* p, book_t* q)
{
	int post = hashFunc(q->num);
	p[post] = *q;
}

int main()
{
	book_t b;
	book_t* p = NULL;
	int number;
	book_t hash_list[1000];
	int i;


	return 0;
}