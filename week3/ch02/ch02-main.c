#include<stdio.h>
#include<stdlib.h>
#include"开放定址法.h"
#include"函数实现.h"
int main() {
	HashTable H;//初始化H
	H=InitializeTable(7);
	Insert(89, H);
	Insert(18, H);
	Insert(49, H);
	Insert(87, H);
	Insert(13, H);
	Insert(5, H);
	printf("打印当前散列表\n");
	Print(H);
	H=Rehash(H);//再散列H
	printf("执行再散列操作后再次打印散列表\n");
	Print(H);
	return 0;
}
