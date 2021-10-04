#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct Node;
typedef struct Node* PtrToNode;//Node 对象都是结构体，PtrToNode对象都是结构体指针
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);//返回的是头指针
void DisposeStack(Stack S);//销毁栈
void MakeEmpty(Stack S);//置空
void Push(char X, Stack S);
char Top(Stack S);
char Pop(Stack S);
struct Node {
	char Element;
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
	else {
		while (!IsEmpty(S)) {
			Pop(S);
		}
	}

}
char Pop(Stack S) {
	PtrToNode TmpCell;
	char X;
	if (!IsEmpty(S)) {
		X = S->Next->Element;
		TmpCell = S->Next;
		S->Next = S->Next->Next;
		free(TmpCell);
		return X;
	}
	else
	{
		printf("Empty Stack\n");
	}
}
void Push(char X, Stack S)
{
	PtrToNode TmpCell;
	TmpCell = (Stack)malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		printf("out of space");
	else {
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}
char Top(Stack S) {
	if (!IsEmpty(S)) {
		//printf("栈顶元素为%c\n", S->Next->Element);
		return S->Next->Element;
	}
	else
	{
		return 0;
	}
}
int main() {
	Stack S = CreateStack();
	//char Str[]= "s=t[5]+u/(v*(w+y))";
	int E = 0;
	//char Str[] = "s=t5]+u/(v*(w+y))";//更改Str[]改变输入
	char Str[] = "s=t[5]+u/(v*(w+y)";
	int count = strlen(Str);
	printf("%d\n", count);
	for (int j = 0; j < count; j++)
		printf("%c", Str[j]);
	for (int i = 0; i < count; i++) {
		if (Str[i] == '(' || Str[i] == '{' || Str[i] == '[') {
			Push(Str[i], S);
		}
		else if (Str[i] == ')') {
			if (IsEmpty(S) || Top(S)!= '(') { printf("字符串符号不平衡"); E = -1;}
			else Pop(S);
		}
		else if (Str[i] == '}') {
			if (IsEmpty(S) || Top(S)!='{') { printf("字符串符号不平衡"); E = -1; }
			else Pop(S);
		}
		else if (Str[i] == ']') {
			if (IsEmpty(S) || Top(S)!= '[') { printf("字符串符号不平衡"); E = -1; }
			else Pop(S);
		}
	}
	if (E != -1) {
		if (IsEmpty(S)) { printf("字符串符号平衡"); }
		else
		{
			printf("字符串符号不平衡");
		}
	}
	return 0;
}
