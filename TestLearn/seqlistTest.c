#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100

typedef struct
{
	int data[N];
	int valid;
}seqlist_t;

seqlist_t* creatEmptySeqlist()
{
	seqlist_t* p = (seqlist_t*)malloc(sizeof(seqlist_t));
	if (p == NULL)
	{
		return NULL;
	}
	p->valid = 0;
	return p;
}

int isEmpty(seqlist_t* p)
{
	return p->valid == 0;
}

int isFull(seqlist_t* p)
{
	return p->valid == N;
}

void showSeqlist(seqlist_t* p)
{
	for (int i = 0; i < p->valid; i++)
	{
		printf("%d ", p->data[i]);
	}
	printf("\n");
}

int insertInto(seqlist_t* p, int index, int val)
{
	if (index <= 0 || index > p->valid + 1 || isFull(p))
	{
		return -1;
	}
	for (int i = p->valid - 1; i >= index - 1; i--)
	{
		p->data[i + 1] = p->data[i];
	}
	p->data[index - 1] = val;
	p->valid++;
	return 0;
}

int deleteFrom(seqlist_t* p, int index)
{
	if (index > p->valid || isEmpty(p) || index <= 0)
	{
		return -1;
	}
	for (int i = index; i <= p->valid - 1; i++)
	{
		p->data[i - 1] = p->data[i];
	}
	p->valid--;
	return 0;
}

int getLenth(seqlist_t* p)
{
	return p->valid;
}

int findDate(seqlist_t* p, int search)
{
	for (int i = 0; i < p->valid; i++)
	{
		if (p->data[i] == search)
		{
			return i;
		}
	}
	return -1;
}

void clearSeqlist(seqlist_t* p)
{
	p->valid = 0;
}

int main()
{
		//1. ����һ���յ�˳��� createEmptySeqlist() / create()
		//2. �ж�˳����Ƿ�Ϊ�� �յĻ� ����1 ���շ���0 isEmpty()
		//3. �ж�˳����Ƿ�Ϊ�� ���Ļ� ����1 ��������0 isFull()
		//4. ����˳�����������ЧԪ�� showSeqlist()
		//5. ��ָ��λ�ò������� insertInto()
		//6. ɾ��ָ��λ���ϵ����� deleteFrom()
		//7.��˳���ĳ��� getLength()
		//8. ����ĳ��Ԫ����˳����г��ֵĵ�λ�� findData()
		//9. ���˳��� clearSeqlist()
	seqlist_t* t = creatEmptySeqlist();
	isEmpty(t);
	isFull(t);
	showSeqlist(t);
	insertInto(t, 1, 1);
	insertInto(t, 2, 2);
	insertInto(t, 3, 3);
	deleteFrom(t, 2);
	showSeqlist(t);

	printf("the lenth is %d\n",getLenth(t));
	findDate(t, 3);
	clearSeqlist(t);

	showSeqlist(t);

	free(t);
	return 0;
}
