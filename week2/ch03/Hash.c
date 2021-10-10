#include<stdio.h>
#include<stdlib.h>
struct ListNode;//节点
struct HashTbl;//哈希表
typedef struct ListNode* Position;//结构体指针别名position
typedef struct HashTbl* HashTable;
struct ListNode {
	int Element;
	Position Next;
};
struct HashTbl
{
	int The_Size;
	Position* TheListNode;
};
void Creat(int SIZE, HashTable H)
{
	H = (HashTable)malloc(sizeof(struct HashTbl));//H是哈希表结构体的指针
	if (H == NULL)
		printf("out of space");
	H->The_Size = SIZE;
	//初始化哈希表数组
	H->TheListNode = (Position*)malloc(sizeof(Position) * SIZE);
	if (H->TheListNode == NULL)
		printf("out of space");
	for (int i = 0; i < SIZE; i++) {
		H->TheListNode[i] = (Position)malloc(sizeof(struct ListNode));
		if (H->TheListNode[i] == NULL)
			printf("out of space");
		H->TheListNode[i]->Next = NULL;
	}
}
int Hash(int X,int SIZE){
	return (X*X) % SIZE;
}
Position Find(HashTable H, int X)
{
	Position P;
	P = H->TheListNode[Hash(X, H->The_Size)];
	while (P!=NULL&&P->Element!=X)
	{
		P = P->Next;
	}
	return P;
}
void Insert(HashTable H, int X)
{
	if (!Find(H, X))
	{
		Position  temp, L;
		temp = (Position)malloc(sizeof(struct ListNode));
		if (temp == NULL)
			printf("out of space");
		L = H->TheListNode[Hash(X, H->The_Size)];
		temp->Element = X;
		temp->Next = L->Next;
		L->Next = temp;
	}
}
