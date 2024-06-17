#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	char data;
	struct Node* lchild;
	struct Node* rchild;
}tree_node,*tree_list;

tree_list creatTree()
{
	char ch;
	scanf_s(" %c", &ch, 1);
	if (ch == '#')
		return NULL;
	tree_node* r = (tree_node*)malloc(sizeof(tree_node));
	if (r == NULL)
	{
		printf("malloc tree node fail!!\n");
		return NULL;
	}
	r->data = ch;
	r->lchild = creatTree();
	r->rchild = creatTree();

	return r;
}

void preorder(tree_node* r)
{
	if (r == NULL)
	{
		return;
	}
	printf("%c", r->data);
	preorder(r->lchild);
	preorder(r->rchild);
}

void inorder(tree_node* r)
{
	if (r == NULL)
	{
		return;
	}
	inorder(r->lchild);
	printf("%c", r->data);
	inorder(r->rchild);
}

void postorder(tree_list r)
{
	if (r == NULL)
	{
		return;
	}
	postorder(r->lchild);
	postorder(r->rchild);
	printf("%c", r->data);
}

void showBinTree(void (*p)(tree_node*), tree_node* r,const char* s)
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
	clearTree(r->lchild);
	clearTree(r->rchild);
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
	tree_node* r = creatTree();

	printf("preoder:");
	preorder(r);
	printf("\n");
	showBinTree(preorder, r, "preoder:");

	showBinTree(inorder, r, "inorder:");
	showBinTree(postorder, r, "postorder:");

	clearTree(r);

	return 0;
}