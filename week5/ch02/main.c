#include"排序.h"
//插入排序
void InsertionSort(int A[], int N) {
	int j, P;
	int Tmp;
	for (P = 1; P < N; P++) {
		Tmp = A[P];
		for (j = P; j > 0 && A[j - 1] >Tmp; j--) {
			A[j] = A[j - 1];
		}
		A[j] = Tmp;
	}
}
int main() {
  int a[6] = { 34,8,64,51,32,21 };
	InsertionSort(a, 6);
	return 0;
}
