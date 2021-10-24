#include"左式堆.h"
int main() {
	//构建并合并两个左式堆
	
	PriorityQueue h1;
	PriorityQueue H1 =Initialize(10);
	H1 = Insert1(21,H1);
	PriorityQueue H2 =Initialize(14);
	H2 = Insert1(23, H2);
	PriorityQueue H3 = Initialize(3);
	PriorityQueue H4 = Initialize(26);
	H4 = Insert1(17, H4);
	H4 = Insert1(8, H4);
	h1=Merge(Merge(Merge(H1, H2), H3), H4);
	PriorityQueue  H5, H6,H7,h2;
	H7 = Initialize(12);
	H7 = Insert1(18, H7);
	H5 = Initialize(24);
	H5 = Insert1(33, H5);
	H5=Insert1(6,Merge(H7, H5));
	H6 = Initialize(7);
	H6 = Insert1(37, H6);
	H6 = Insert1(18, H6);
	h2 = Merge(H5, H6);
	Print(Merge(h1, h2));
	return 0;
}
