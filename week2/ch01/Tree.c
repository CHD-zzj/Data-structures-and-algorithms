#include<stdio.h>
#include<stdlib.h>

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;
typedef int ElementType;//int 重命名为ElementType  改int可以改所代指的数据类型
SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);
void Print(SearchTree T);

struct TreeNode {
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};
SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL){
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
Position Find(ElementType X, SearchTree T)
{
	if (T==NULL)
		return NULL;
	if (X < T->Element)
		return Find(X, T->Left);
	else
		if (X > T->Element)
			return Find(X, T->Right);
		else 
			return T;
}
Position FindMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else
		if (T->Left == NULL)
			return T;
		else
			return FindMin(T->Left);
}
Position FindMax(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else
		if (T->Right == NULL)
			return T;
		else
			return FindMin(T->Right);
}
SearchTree Insert(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		if (T == NULL)
			printf("out of space");
		else 
		{
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else {
		if (X < T->Element)
			T->Left = Insert(X, T->Left);
		else
			T->Right = Insert(X, T->Right);
	}
	return T;//T是插入后的指针 指向插入的元素
}
SearchTree Delete(ElementType X, SearchTree T)
{
	Position TmpCell;
	if (T == NULL)
		printf("ElementType not found");
	else if (X < T->Element)
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)
		T->Right = Delete(X, T->Right);
	else if (T->Left && T->Right) {
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(TmpCell->Element, T->Right);
	}
	else{
		TmpCell = T;
		if (T->Left == NULL)
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		free(TmpCell);
	}
	return T;
}

void MidPrint(SearchTree T) {
	if (T != NULL)
	{
		MidPrint(T->Left);
		printf("");
		printf("%d  ", T->Element);
		MidPrint(T->Right);
	}
}
void PrePrint(SearchTree T) {
	if (T != NULL)
	{
		printf("");
		printf("%d  ", T->Element);
		PrePrint(T->Left);
		PrePrint(T->Right);
	}
}
int main()
{
	SearchTree T=NULL;
	MakeEmpty(T);
	T=Insert(6, T);
	T=Insert(2, T);
	T=Insert(1, T);
	T=Insert(4, T);
	T=Insert(3, T);
	T=Insert(5, T);
	T=Insert(8, T);
	printf("树中最大元素为%d\n", FindMax(T)->Element);
	printf("树中最小元素为%d\n", FindMin(T)->Element);
	printf("中序遍历\n");
	MidPrint(T);
	printf("\n");
	printf("先序遍历\n");
	PrePrint(T);
	printf("\n");
	Delete(4, T);
	printf("删除元素4后\n");
	printf("中序遍历\n");
	MidPrint(T);
	printf("\n");
	printf("先序遍历\n");
	PrePrint(T);
	return 0;
}
