#pragma once
#include"二叉小根堆.h"
PriorityQueue Initialize(int MaxElements) {
	PriorityQueue H;
	if (MaxElements < 1)
		printf("PriorityQueue is too small");
	H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
	if (H == NULL)
		printf("out of space");
	H->Elements = (int*)malloc(sizeof(int) * (MaxElements + 1));
	if (H->Elements == NULL)
		printf("Out of space");
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = -1;//MinData自定义
	return H;

}
PriorityQueue PercolateDown(PriorityQueue H, int i, int count)//下虑i
{
	int child, j, temp;
	int MinChild = 0;
	for (j = i; j <= count / 2; j = MinChild) {
		child = j * 2;
		if (H->Elements[child] > H->Elements[child + 1]) {
			MinChild = child + 1;
		}
		else
		{
			MinChild = child;
		}
		if (H->Elements[j] > H->Elements[MinChild])
		{
			temp = H->Elements[j];
			H->Elements[j] = H->Elements[MinChild];
			H->Elements[MinChild] = temp;
		}
	}
	return H;
}
PriorityQueue BuildHeap(PriorityQueue H, int count) {
	int j;
	for (j = count / 2; j > 0; j--) {
		H = PercolateDown(H, j, count);
	}
	return H;
}
void Insert(int X, PriorityQueue H)
{
	int i;
	if (IsFull(H))
	{
		printf("这个二叉树已经满了");
		return;
	}
	for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = X;
}
int DeleteMin(PriorityQueue H) {
	int i, child;
	int MinElement, LastElement;
	if (IsEmpty(H)) {
		printf("这个二叉树是空树");
		return H->Elements[0];
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];//先赋值给lastelement 然后size--
	for (i = 1; i * 2 < H->Size; i = child)
	{
		child = i * 2;
		if (child != H->Size && H->Elements[child] > H->Elements[child + 1])
			child++;//找出两个孩子较小的一个
		if (LastElement > H->Elements[i])
			H->Elements[i] = H->Elements[child];
		else {
			break;
		}
	}
	H->Elements[i] = LastElement;
	return MinElement;
}
int IsEmpty(PriorityQueue H)
{
	if (H->Size == 0)
		return 1;
	else
		return 0;
}
int IsFull(PriorityQueue H)
{
	if (H->Size == H->Capacity)
		return 1;
	else
		return 0;
}
void Print(PriorityQueue H) {
	int  i = 1, j = 1;
	for (i; i <= H->Size; i++)
	{
		printf("   %d   ", H->Elements[i]);
		if (i == (pow(2, j) - 1))
		{
			printf("\n");
			j++;
		}
	}
}
