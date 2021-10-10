#include<stdio.h>
#include<stdlib.h>
struct AvlNode;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;
typedef int ElementType;//int 重命名为ElementType  改int可以改所代指的数据类型
AvlTree MakeEmpty(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
int Height(AvlTree T);
int MAX(int a, int b);
AvlTree SingleRotateLeft(AvlTree T);
AvlTree SingleRotateRight(AvlTree T);
AvlTree DoubleRotateLeft(AvlTree T);
AvlTree DoubleRotateRight(AvlTree T);
struct AvlNode {
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int height;
};
AvlTree MakeEmpty(AvlTree T)
{
	if (T != NULL) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
int Height(AvlTree T) {
	if (T == NULL)
		return -1;
	else
		return T->height;
}
int MAX(int a,int b) 
{
	if (a > b) { return a; }
	else {
	return b;
	}
}

AvlTree SingleRotateLeft(AvlTree T)
{
	AvlTree L=T->Right;
	T->Right = L->Left;
	L->Left = T;
	T->height =MAX(Height(T->Left),Height(T->Right))+1;
	L->height =MAX(Height(L->Left),Height(L->Right))+1;
	return L;
}
AvlTree SingleRotateRight(AvlTree T)
{
	AvlTree L = T->Left;
	L->Right = T;
	T->Left = L->Right;
	T->height = (MAX(Height(T->Left), Height(T->Right))) + 1;
	L->height = (MAX(Height(L->Left), Height(L->Right)) )+ 1;
	return L;
}
AvlTree DoubleRotateLeft(AvlTree T){
	//先左后右双旋转
	T->Left = SingleRotateLeft(T->Left);
	return SingleRotateRight(T);
}
AvlTree DoubleRotateRight(AvlTree T) {
	//先右后左双旋转
	T->Right = SingleRotateRight(T->Left);
	return SingleRotateLeft(T);
}
AvlTree Insert(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		T = (AvlTree)malloc(sizeof(struct AvlNode));
		if (T == NULL)
			printf("out of space");
		else
		{
			T->Element = X;
			T->height = 0;
			T->Left = NULL;
			T->Right = NULL;
		}
	}
	else if (X < T->Element) {
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
		{
			if (X < T->Left->Element)//左左插入
				T = SingleRotateRight(T);
			else //左儿子右子树插入
				T = DoubleRotateLeft(T);
		}
	}
	else if (X > T->Element) {
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (X > T->Right->Element)//右右插入情况
				T = SingleRotateLeft(T);
			else
				T = DoubleRotateRight(T);
		}
	}
	T->height = (MAX(Height(T->Left),Height(T->Right))+ 1);
	return T;
}
