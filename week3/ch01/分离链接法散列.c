#pragma once
struct ListNode;//节点
struct HashTbl;//哈希表
typedef struct ListNode* Position;//结构体指针别名position
typedef struct HashTbl* HashTable;
int NextPrime(int TableSize);
int IsPrime(int TableSize);
int Hash(int key, int TableSize);
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(int key, HashTable H);
void Print(HashTable H);
void Insert(int key, HashTable H);
int Retrieve(Position P);
typedef Position List;
