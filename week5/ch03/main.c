#include"排序.h"
//哈希排序
void Shellsort(int A[],int N) {
	int B[3] = { 5,3,1 };
	int i, j, Tmp, Increment;
	for (i = 0; i < 3; i++) {
		Increment = B[i];
		printf("在%d排序后 :", Increment);
		if (Increment == 1) {
			int j, P;
			int Tmp;
			for (P = 1; P < N; P++) {
				Tmp = A[P];
				for (j = P; j > 0 && A[j - 1] > Tmp; j--) {
					A[j] = A[j - 1];
				}
				A[j] = Tmp;
			}
		}
		else{
		for (j = 0; j + Increment < N; j++) {
			if (A[j] > A[j + Increment])
			{
				Swap(A[j], A[j + Increment]);
			}
		}
		}
		for (j = 0; j < N; j++) {
			printf("%d  ", A[j]);
		}
		printf("\n");
	}
}
int main()
{
  int a[13] = { 81,94,11,96,12,35,17,95,28,58,41,75,15 };
	Shellsort(a, 13); 
  return 0;
}
