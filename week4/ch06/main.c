#include"斜堆.h"
int main() {
PriorityQueue H = Initialize(1);
	for (int i = 2; i <=15; i++)
		H = Insert1(i, H);
	//H= DeleteMin1(H);
	Print(H);
	return 0;
}
