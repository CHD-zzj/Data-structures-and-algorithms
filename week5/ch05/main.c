#include"排序.h"
//归并
void Mergesort(int A[],int N){
	int* TmpArray;
	TmpArray = (int*)malloc(N*sizeof(int));
	if (TmpArray != NULL) {
		Msort(A, TmpArray, 0, N - 1);
		for (int j = 0; j < N; j++)
			printf("%d ", A[j]);
	free(TmpArray);
	}
	else {
		printf("out of space");
	}
}
void Msort(int A[], int TmpArray[], int Left, int Right){
	int Center;
	if (Left < Right) {
		Center = (Left + Right) / 2;
		Msort(A, TmpArray, Left, Center);
		Msort(A, TmpArray, Center + 1,Right);
		Merge(A, TmpArray, Left, Center + 1, Right);
	}
}
void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd) {
	int i, LeftEnd, NumElements, TmpPos;
	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElements = RightEnd-Lpos + 1;
	while (Lpos <= LeftEnd && Rpos <= RightEnd)
		if (A[Lpos] <= A[Rpos])
			TmpArray[TmpPos++] = A[Lpos++];
		else
			TmpArray[TmpPos++] = A[Rpos++];
	while (Lpos <= LeftEnd)
		TmpArray[TmpPos++] = A[Lpos++];
	while(Rpos<=RightEnd)
		TmpArray[TmpPos++] = A[Rpos++];
	for (i = 0; i < NumElements; i++,RightEnd--)
		A[RightEnd] = TmpArray[RightEnd];
}
int main(){
  int a[8] = { 13,26,1,2,27,38,15 ,1};
	Mergesort(a, 8);
  return 0;
}
