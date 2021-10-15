#pragma once
typedef unsigned int Index;//记无符号整形数据 别名为Index
typedef Index Position;//记Index别名为Position
struct HashTbl;
typedef struct HashTbl* HashTable;
/*HashTable 就是所有HashTbl结构体指针的代称 
可以用HashTable命名指向HashTbl的指针
例如 指向结构体HashTbl
HashTable H, E, T;*/
int IsPrime(int x);
int NextPrime(int TableSize);
Position  Hash(int X, int Size);
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(int key, HashTable H); 
void Insert(int key, HashTable H);
int Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H);
enum KindOfEntry{Legitimate,Empty,Deleted};
/*枚举类型*/
