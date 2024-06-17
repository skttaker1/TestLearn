#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
//#include<unistd.h>

typedef struct node
{
    int data;
    struct node* next;
}link_node;

link_node* creatNode()
{
    link_node* p = (link_node*)malloc(sizeof(link_node));
    if (p == NULL)
    {
        printf("malloc failed!!\n");
        return NULL;
    }
    p->data = 0;
    p->next = NULL;
    return p;
}

void delNode(link_node* del)
{
    free(del);
    del = NULL;
}

int main(int argc, char* argv[])
{
    int all_num = 8;
    int start_num = 3;
    int kill_num = 4;

    link_node* h = creatNode();
    h->data = 1;

    link_node* ptail = h;

    for (int i = 2; i < all_num + 1; i++)
    {
        link_node* pnew = creatNode();
        pnew->data = i;
        ptail->next = pnew;
        ptail = pnew;
    }
    ptail->next = h;

    for (int i = 0; i < start_num - 1; i++)
    {
        h = h->next;
    }

    while (h != h->next)
    {
        for (int i = 0; i < kill_num - 2; i++)
        {
            h = h->next;
        }
        link_node* pdel = h->next;
        h->next = pdel->next;
        printf("kill the %d monkey!!\n", pdel->data);
        delNode(pdel);
        h = h->next;
    }
    printf("the monkey is %d!!\n", h->data);
    free(h);



    return 0;
}