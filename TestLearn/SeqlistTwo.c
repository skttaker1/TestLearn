#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100

typedef struct
{
	char name[20];
	int age;
	int score;
}stu;

typedef struct
{
	stu slist[N];
	int valid;
}stuList;

stuList* creatEmptyList()
{
	stuList* p = malloc(sizeof(stuList));
	if (p == NULL)
	{
		return -1;
	}
	p->valid = 0;
	return p;
}

int isEmpty(stuList* p)
{
	return p->valid == 0;
}

int isFull(stuList* p)
{
	return p->valid == N;
}

int insertStu(stuList* p, int index, stu st)
{
	if (index <= 0 || isFull(p) || index - 1 > p->valid)
	{
		return -1;
	}
	for (int i = p->valid; i >= index - 1; i--)
	{
		p->slist[i] = p->slist[i - 1];
	}
	p->slist[index - 1] = st;
	p->valid++;
	return 0;
}

int deleteStu(stuList* p, int index)
{
	if (isEmpty(p) || index <= 0 || index > p->valid)
	{
		return -1;
	}
	for (int i = index - 1; i < p->valid; i++)
	{
		p->slist[i] = p->slist[i + 1];
	}
	p->valid--;
	return 0;
}

void showStuList(stuList* p)
{
	for (int i = 0; i < p->valid; i++)
	{
		printf("name is :%s,age is :%d,score is :%d\n",
			p->slist[i].name, p->slist[i].age, p->slist[i].score);
	}
}

int main()
{
	stuList* s = creatEmptyList();
	stu sts[] = { {"张三",19,90},{"小明",20,89},{"小好",19,91} };

	for (int i = 1; i <= 3; i++)
	{
		insertStu(s, i, sts[i - 1]);
	}
	showStuList(s);
	printf("\n");

	deleteStu(s, 3);
	showStuList(s);

	return 0;
}