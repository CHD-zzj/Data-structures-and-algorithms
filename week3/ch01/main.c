#include<stdio.h>
#include<stdlib.h>
#include"分离链接法散列.h"
#include"函数实现.h"
int main() {
	HashTable H;
	Position P;
	H = InitializeTable(11);
	Insert(0, H);
	Insert(1, H);
	Insert(81, H);
	Insert(4, H);
	Insert(64, H);
	Insert(25, H);
	Insert(16, H);
	Insert(36, H);
	Insert(9, H);
	Insert(49, H);	
	printf("打印出分离链接散列\n");
	Print(H);
	printf("\n");
	printf("查询元素77\n");
	P=Find(77, H);
	if (P ==NULL)
		printf("没有找到\n");
	printf("查询元素49\n");
	P=Find(49, H);
	if (P != NULL)
		printf("元素49在列表内\n");
	return 0;
}
