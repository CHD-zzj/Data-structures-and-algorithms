#pragma once
#include<stdio.h>
#include<stdlib.h>
struct TreeNode;
typedef struct TreeNode* PriorityQueue;
PriorityQueue Initialize(int X);
int FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
void SwapChildren(PriorityQueue H);
PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2);
PriorityQueue Insert1(int X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);
struct TreeNode {
	int Element;
	PriorityQueue Left;
	PriorityQueue Right;
	int NPL;
};
PriorityQueue Initialize(int X) {
	PriorityQueue H;
	H = (PriorityQueue)malloc(sizeof(struct TreeNode));
	if (H == NULL)
		printf("out of space");
	H->Left = H->Right = NULL;
	H->Element = X;
	H->NPL = 0;
	return H;
}
PriorityQueue Insert1(int X, PriorityQueue H) {
	PriorityQueue SingleNode;
	SingleNode = (PriorityQueue)malloc(sizeof(struct TreeNode));
	if (SingleNode == NULL)
		printf("Out of space");
	else {
		SingleNode->Element = X;
		SingleNode->NPL = 0;
		SingleNode->Left = SingleNode->Right = NULL;
		H = Merge(SingleNode, H);
	}
	return H;
}
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2) {
	if (H1 == NULL)
		return H2;
	if (H2 == NULL)
		return H1;
	if (H1->Element < H2->Element)
		return Merge1(H1, H2);
	else
		return Merge1(H2, H1);
}
//static 
PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2) {
	//H1根节点<H2根节点  H2与H1的右子堆合并
	if (H1->Left == NULL)
	{
		H1->Left = H2;
	}
	else
	{
		H1->Right = Merge(H1->Right, H2);
		if (H1->Left->NPL < H1->Right->NPL) {
			SwapChildren(H1);

		}
		H1->NPL = H1->Right->NPL + 1;
	}
	return H1;
}
void SwapChildren(PriorityQueue H) {

	PriorityQueue Temp;
	Temp = H->Left;
	H->Left = H->Right;
	H->Right = Temp;

}
PriorityQueue DeleteMin1(PriorityQueue H) {
	PriorityQueue LeftHeap, RightHeap;
	if (IsEmpty(H)) {
		printf("It is Empty!");
		return H;
	}
	LeftHeap = H->Left;
	RightHeap = H->Right;
	free(H);
	return Merge(LeftHeap, RightHeap);
}
int IsEmpty(PriorityQueue H) {
	if (H == NULL)
		return 1;
	else
		return 0;
}
int FindMin(PriorityQueue H)
{
	return H->Element;
}
void Print(PriorityQueue H) {
	if (H != NULL) {
		printf("%d\n", H->Element);
	}
	if (H->Left != NULL) {
		printf("打印%d的左堆--------\n", H->Element);
		Print(H->Left);
	}
	else
		printf("%d的左子堆为NULL\n", H->Element);
	if (H->Right != NULL) {
		printf("打印%d的右堆--------\n", H->Element);
		Print(H->Right);
	}
	else
		printf("%d的右子堆为NULL\n", H->Element);
}
