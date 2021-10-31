#include"排序.h"
//堆排序（大根堆）
void HeapSort(int A[], int N) {
	int i; int Tmp;
	for (i = N / 2; i >= 0; i--)  
		PercDown(A, i, N);
	for (i = N-1 ; i > 0; i--)
	{	
		Swap(A[0], A[i]);
		PercDown(A, 0, i);
	}
	for (int k = 0; k < N; k++)
		printf("%d  ", A[k]);
}
void PercDown(int A[],int i,int N){
	int tmp;
	int Child;
	for (tmp=A[i];LeftChild(i)<N;i=Child)
	{
		Child = LeftChild(i);
		if (Child != N - 1 && A[Child + 1] > A[Child])
			Child++;
		if (tmp < A[Child])
			A[i] = A[Child];
		else
			break;
	}
	A[i] = tmp;
}
int main(){
  int a[7] = { 2,3,6,4,8,1,9 };
	HeapSort(a, 7);
  return 0;
}
