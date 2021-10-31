#pragma once
#include<stdio.h>
#include<stdlib.h>
#define LeftChild(i)  (2*(i)+1)
#define Cutoff (3)
///交换两数
void Swap(int& a, int& b);
void Swap(int& a, int& b) {
	int Tmp;
	Tmp = a;
	a = b;
	b = Tmp;
}
//按顺序打印数组
void Print(int A[],int N) {
	for (int i = 0; i < N; i++)
		printf("%d  ", A[i]);
}
//插入排序
void InsertionSort(int A[], int N);
//哈希排序
void Shellsort(int A[], int N);
//堆排序
void PercDown(int A[], int i, int N);
void HeapSort(int A[], int N);
//归并排序
void Mergesort(int A[], int N);
void Msort(int A[], int TmpArray[], int Left, int Right);
void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd);
//快速排序
void Quicksort(int A[], int N);
void Qsort(int A[], int Left, int Right);
int Median3(int A[], int Left, int Right);
//选择问题
void Qselect(int A[], int k, int Left, int Right);
