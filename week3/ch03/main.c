#include<stdio.h>
#include"二叉小根堆.h"
#include<math.h>
#include<stdlib.h>
#include"函数实现.h"
int main() {
	printf("1");
	//示例一
	/*
	int count,i;
	PriorityQueue H;
	printf("请输入堆元素个数\n");
	scanf_s("%d",&count);
	H = Initialize(count);
	printf("请输入堆元素\n");
	for (i = 1; i <= count; i++) {
		scanf_s("%d", &H->Elements[i]);
		H->Size++;
	}
	H=BuildHeap(H,count);
	printf("建堆并进行下滤操作后\n");
	Print(H);
	return 0;
	*/

	//示例二
	/*PriorityQueue H;
	H = Initialize(11);
	Insert(13, H);
	Insert(14, H);
	Insert(16, H);
	Insert(19, H);
	Insert(21, H);
	Insert(19, H);
	Insert(68, H);
	Insert(65, H);
	Insert(26, H);
	Insert(32, H);
	Insert(31, H);
	Print(H);
	printf("\n");
	printf("删除最小元素后\n");
	DeleteMin(H);
	Print(H);
	return 0;
	*/
}
