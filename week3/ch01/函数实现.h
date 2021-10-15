#pragma once
#include"分离链接法散列.h"
struct ListNode {
	int Element;
	Position Next;
};
struct HashTbl
{
	int TableSize;
	List* TheLists;
};
int Hash(int key, int TableSize) {
	return key % TableSize;
}
void Insert(int key, HashTable H) {
	Position Pos, NewCell;
	List L;
	Pos = Find(key, H);
	if (Pos == NULL) {
		NewCell = (Position)malloc(sizeof(struct ListNode));
		if (NewCell == NULL)
			printf("out of space");
		else
		{
			L = H->TheLists[Hash(key, H->TableSize)];
			NewCell->Next = L->Next;
			NewCell->Element = key;
			L->Next = NewCell;
		}
	}

}
Position Find(int key, HashTable H) {
	Position P;
	List L;
	L = H->TheLists[Hash(key, H->TableSize)];
	P = L->Next;
	while (P != NULL && P->Element != key)
	{
		P = P->Next;
	}
	return P;
}
HashTable InitializeTable(int TableSize) {
	HashTable H;
	int i;
	if (TableSize < 1) {
		printf("TableSize too small");
		return NULL;
	}
	H = (HashTable)malloc(sizeof(struct HashTbl));
	if (H == NULL)
		printf("out of space");
	H->TableSize = NextPrime(TableSize);
	H->TheLists = (List*)malloc(sizeof(List) * H->TableSize);
	if (H->TheLists == NULL)
		printf("out of space");
	for (i = 0; i < H->TableSize; i++)
	{
		H->TheLists[i] = (Position)malloc(sizeof(struct ListNode));
		if (H->TheLists[i] == NULL)
			printf("out of space");
		else
			H->TheLists[i]->Next = NULL;
	}
	return H;
}
int NextPrime(int TableSize)
{
	while (1) {
		if (IsPrime(TableSize))
			return TableSize;
		else
			TableSize++;
	}
}
void Print(HashTable H) {
	printf("表头  :链表\n");
	Position P;
	for (int i = 0; i < H->TableSize; i++)
	{
		printf("  %d   :", i);
		P = H->TheLists[i]->Next;
		if (P == NULL)
			printf("NULL");
		else {
			while (P != NULL) {
				printf("%d--->", P->Element);
				P = P->Next;
			}
			printf("NULL");
		}
		printf("\n");
	}
}
int IsPrime(int x) {
	int i;
	for (i = 2; i * i <= x; i++)
		if (x % i == 0)
			return 0;
	return 1;
}
