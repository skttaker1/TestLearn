#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	char data;
	struct Node* lchiled;
	struct Node* rchiled;
}tree_node,*tree_list;

tree_list creatTree()
{
	char ch;
	scanf("%c", &ch);
	if (ch == "#")
		return NULL;
	tree_node* r = malloc(sizeof(tree_list));
	if (r == NULL)
	{
		printf("malloc tree node fail!!\n");
		return NULL;
	}
	r->data = ch;
	r->lchiled = creatTree();
	r->rchiled = creatTree();
}

void preorder(tree_node* r)
{
	if (r == NULL)
	{
		return;
	}
	printf("%c", r->data);
	preorder(r->lchiled);
	preorder(r->rchiled);
}
void inorder(tree_node* r)
{
	if (r == NULL)
	{
		return;
	}
	inorder(r->lchiled);
	printf("%c", r->data);
	inorder(r->rchiled);
}

void postorder(tree_list r)
{
	if (r == NULL)
	{
		return;
	}
	postorder(r->lchiled);
	postorder(r->rchiled);
	printf("%c", r->data);
}

void showBinTree(void (*p)(tree_node*), tree_node* r, char* s)
{
	printf("%s", s);
	p(r);  
	printf("\n");
}

void clearTree(tree_node* r)
{
	if (r == NULL)
	{
		return;
	}
	clearTree(r->lchiled);
	clearTree(r->rchiled);
	free(r);
}

int main()
{
#if 0
	//定义6个二叉树节点
	tree_node a = { 'A', NULL, NULL };
	tree_node b = { 'B', NULL, NULL };
	tree_node c = { 'C', NULL, NULL };
	tree_node d = { 'D', NULL, NULL };
	tree_node e = { 'E', NULL, NULL };
	tree_node f = { 'F', NULL, NULL };
	//形成二叉树
	a.lchiled = &b;
	a.rchiled = &c;
	b.lchiled = &d;
	c.lchiled = &e;
	c.rchiled = &f;

#endif

	printf("preoder:");
	preorder(&a);
	printf("\n");
	showBinTree(preorder, &a, "preoder:");

	showBinTree(inorder, &a, "inorder:");
	showBinTree(postorder, &a, "postorder:");

	return 0;
}