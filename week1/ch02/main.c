//结构体元素的数据类型 以int为例
#include<stdio.h>
#include<stdlib.h>
struct Node;
typedef struct Node* PtrToNode;//Node 对象都是结构体，PtrToNode对象都是结构体指针
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);//返回的是头指针
void DisposeStack(Stack S);//销毁栈
void MakeEmpty(Stack S);//置空
void Push(int X, Stack S);
int Top(Stack S);
void Pop(Stack S);
struct Node {
	int Element;
	PtrToNode Next;
};
int IsEmpty(Stack S) {
	return S->Next == NULL;
}
Stack CreateStack() {
	Stack S;
	S = (Stack)malloc(sizeof(struct Node));
	if (S == NULL)
		printf("out of space");
	S->Next = NULL;
	return S;
}
void MakeEmpty(Stack S)
{
	if (S == NULL)
	{
		printf("must use CreateStack first");
		exit(1);
	}
	else{
		while (!IsEmpty(S)) {	
			Pop(S);
		}
	}
		
}
void Pop(Stack S) {
	PtrToNode TmpCell;
	if (!IsEmpty(S)) {
		TmpCell = S->Next;
	    S->Next = S->Next->Next;
		free(TmpCell);
	}
	else
	{
		printf("Empty Stack\n");
	}
}
void Push(int X, Stack S)
{
	PtrToNode TmpCell;
	TmpCell = (Stack)malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		printf("out of space");
	else{
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}
int Top(Stack S) {
	if (!IsEmpty(S)) {
	printf("栈顶元素为%d\n", S->Next->Element);
	return 0;
	}
	else
	{
		printf("Empty Stack\n");
		return 0;
	}
}

int main() {
	Stack S = CreateStack();

	Push(1, S);
	Push(2, S);
	Push(3, S);
	Push(4, S);
	Top(S);
	printf("执行出栈操作后\n");
	Pop(S);
	Top(S);
	MakeEmpty(S);
	printf("执行置空操作后\n");
	Top(S);
	return 0;
}
