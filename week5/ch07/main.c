#include"排序.h"
//选择问题
void Qselect(int A[], int k, int Left, int Right) {
	//第k个最小的元素
	int i, j;
	int Pivot;
	if (Left+Cutoff <= Right) {
		Pivot = Median3(A, Left, Right);
		//printf("pivot=%d\n", Pivot);
		i = Left; j = Right - 1;
		for (;;)
		{
			//printf("----i=%d j=%d\n", i, j);
			while (A[++i] < Pivot) {}
			while (A[--j ]> Pivot) {}
			//printf("i=%d j=%d\n" ,i,j);
			if (i < j)
				Swap(A[i], A[j]);
			else
				break;
		}
		Swap(A[i], A[Right - 1]);
		//for (int k = 0; k < 10; k++)
			//printf("%d", A[k]);
		//printf("\n");
		if (k <= i)
			Qselect(A, k, Left, i -1);
		else if (k > i + 1)
			Qselect(A, k, i + 1, Right);
		else if(k==i+1)
			printf("第%d小者为%d\n",k,Pivot);
	}
	//else
		//InsertionSort(A+Left,Right-Left+1);
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
int main() {
	int a[] = {9,8,7,5,4,0,3,1,2};
	Qselect(a, 8, 0, 8);
	for (int i = 0; i < 9; i++)
		printf("%d ", a[i]);
	printf("\n");
	printf("%d", a[7]);
	
	return 0;
}
