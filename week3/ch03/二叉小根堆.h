#pragma once
struct HeapStruct;
typedef struct HeapStruct* PriorityQueue;
PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(int X, PriorityQueue H);
int DeleteMin(PriorityQueue H);
int FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
PriorityQueue BuildHeap(PriorityQueue H,int count);
PriorityQueue PercolateDown(PriorityQueue H, int i, int count);
struct HeapStruct {
	int Capacity;
	int Size;
	int* Elements;
};
