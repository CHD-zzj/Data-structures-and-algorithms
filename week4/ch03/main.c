#include"左式堆.h"
int main() {
  PriorityQueue H = Initialize(3);
	H = Insert1(10, H);
	H = Insert1(8, H);
	H = Insert1(21, H);
	H = Insert1(14, H);
	H = Insert1(17, H);
	H = Insert1(23, H);
	H=DeleteMin1(H);
	Print(H);
  return 0;
}
