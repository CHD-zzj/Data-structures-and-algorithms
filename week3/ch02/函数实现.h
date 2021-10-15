#pragma once
#include"开放定址法.h"
struct HashEntry {
	int Element;
	enum  KindOfEntry Info;
};
typedef struct HashEntry Cell;//Cell是结构体HashEntry的别名
struct HashTbl {
	int TableSize;
	Cell* TheCells;
};
HashTable InitializeTable(int TableSize) {
	HashTable H;
	int i;
	if (TableSize < 1) {
		printf("Table Size too Small");
		return NULL;
	}
	H = (HashTbl*)malloc(sizeof(struct HashTbl));
	if (H == NULL)
	{
		printf("out of space");
	}
	H->TableSize = NextPrime(TableSize);
	H->TheCells = (Cell*)malloc(sizeof(Cell) * H->TableSize);
	if (H->TheCells == NULL) {
		printf("out of space");
	}
	for (i = 0; i < H->TableSize; i++)
		H->TheCells[i].Info = Empty;
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
int IsPrime(int x) {
	int i;
	for (i = 2; i * i <= x; i++)
		if (x % i == 0)
			return 0;
	return 1;
}
Position Find(int key, HashTable H) {
	Position CurrentPos;
	int CollisionNum;
	CollisionNum = 0;
	CurrentPos = Hash(key, H->TableSize);
	while (H->TheCells[CurrentPos].Info != Empty &&
		H->TheCells[CurrentPos].Element != key)
	{
		CurrentPos += 2 * ++CollisionNum - 1;
		if (CurrentPos >= H->TableSize) {
			CurrentPos -= H->TableSize;
		}
	}
	return CurrentPos;
}
Position  Hash(int X, int Size) {
	return X % Size;
}
void Insert(int key, HashTable H) {
	Position Pos;
	Pos = Find(key, H);
	if (H->TheCells[Pos].Info != Legitimate) {
		H->TheCells[Pos].Element = key;
		H->TheCells[Pos].Info = Legitimate;
	}
}
void Print(HashTable H) {
	printf("表头：关键字\n");
	for (int i = 0; i < H->TableSize; i++)
	{
		if (H->TheCells[i].Info != Empty) {
			printf("%d   ； %d\n", i, H->TheCells[i].Element);
		}
		else {
			printf("%d   ； NULL\n", i);
		}
	}
}
HashTable Rehash(HashTable H)
{
	int i, OldSize;
	Cell* OldCells;
	OldSize = H->TableSize;
	OldCells = H->TheCells;
	H = InitializeTable(2 * OldSize);
	for (i = 0; i < OldSize; i++) {
		if (OldCells[i].Info == Legitimate)
		{
			Insert(OldCells[i].Element, H);
			//printf("执行一次插入");
		}
	}
	free(OldCells);
	return H;
}
