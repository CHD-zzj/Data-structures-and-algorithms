//结构体中元素的数据类型 以int为例
#include<stdio.h>
#include<stdlib.h>
#ifndef _List_H
struct Node;
typedef struct Node* PtrToNode;//Node 对象都是结构体，PtrToNode对象都是结构体指针
typedef PtrToNode List;
typedef PtrToNode Position;
List Create();
List MakeEmpty(List L);//
int IsEmpty(List L);
int IsLast(Position P,List L);
Position FindPrevious(int X, List L);
void Insert(int X,List L,Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
int Retrieve(Position P);//
void Delete(int X,List L);
void PrintList(List L);
#endif /* _List_H*/
struct Node {
	int Element;
	Position Next;
};
int IsEmpty(List L) {
	return L->Next == NULL;
}
int IsLast(Position P, List L) {
	return P->Next == NULL;
}
Position Find(int X,List L) {
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
		P = P->Next;
	return P;
}
void Delete(int X,List L) {
	Position P, TmpCell;
	P = FindPrevious(X,L);
	if (!IsLast(P, L)) {
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
} 
Position FindPrevious(int X,List L) {
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Element!=X)
		P = P->Next;
	return P;
}
void Insert(int X, List L,Position P)
{
	Position TmpCell;
	TmpCell = (Position)malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		printf("out of space");
	TmpCell->Element = X;
	TmpCell->Next=P->Next;
	P->Next = TmpCell;
}
void PrintList(List L) {
	printf("打印当前链表\n");
	Position P = L->Next;
	while (P != NULL){ 
		printf("%d",P->Element);
		if (P->Next != NULL)
			printf(" ");
		P = P->Next;
	}
}
void DeleteList(List L) {
	Position P, TmpCell;
	P = L->Next;
	L->Next = NULL;
	while(P!=NULL){
		TmpCell = P->Next;
		free(P);
		P = TmpCell;
	}
}

List Create() {
	Position Header, TmpCell;
	Header = (Position)malloc(sizeof Node);
	TmpCell = Header;
	int n;
	printf("请输入元素个数");
	scanf_s("%d", &n);
	printf("请输入所有元素");
	for (int i = 0; i < n; i++) {
		int X;
		scanf_s("%d",&X);
		Position P;
		P = (Position)malloc(sizeof(struct Node));
		P->Element = X;
		P->Next = NULL;
		TmpCell->Next = P;
		TmpCell = TmpCell->Next;
	}
	return Header;
}
int main()
{
	List L;
	L = Create();
	printf("IsEmpty=%d\n",IsEmpty(L));
	PrintList(L);
	printf("删除元素3\n");
	Delete(3, L);
	PrintList(L);
	printf("插入元素5在开头位置上\n");
	Insert(5, L, L);
	PrintList(L);
	printf("删除列表\n");
	DeleteList(L);
	printf("IsEmpty=%d\n", IsEmpty(L));
	return 0;
}
