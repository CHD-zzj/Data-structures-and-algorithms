#include"排序.h"
//快速排序
void Quicksort(int A[], int N){
	Qsort(A, 0,N - 1);
	for (int i = 0; i < N; i++)
		printf("%d", A[i]);
}
void Qsort(int A[], int Left, int Right)
{
	int i, j;
	int Pivot;//枢纽元；
	if(Left+Cutoff<=Right)
	{ 
		Pivot = Median3(A, Left, Right);
		i = Left; j = Right - 1;
		for (;;) 
		{
			while (A[++i] < Pivot) {
				printf("i=%d", i);
			}
			while (A[--j] > Pivot) {
				printf("i2=%d", i);
			}
			if (i < j)
				Swap(A[i], A[j]);
			else
				break;
		}
		Swap(A[i], A[Right - 1]);
		Qsort(A, Left, i - 1);
		Qsort(A, i + 1, Right);
	}
	else {
		//printf("数组长度太小，进行插入排序更好");
		InsertionSort(A, Right + 1);
	}
}
int Median3(int A[], int Left, int Right) {
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		Swap(A[Left], A[Center]);
	if (A[Left] > A[Right])
		Swap(A[Left], A[Right]);
	if (A[Center] > A[Right])
		Swap(A[Center],A[Right]);
	Swap(A[Center], A[Right - 1]); 
	return A[Right - 1];
}
int main()
{
int a[10] = { 8,1,4,9,0,3,5,2,7,6 };
Quicksort(a, 10);
return 0;
}
