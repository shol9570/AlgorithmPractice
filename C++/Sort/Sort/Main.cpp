#include "Global.h"
using namespace std;

inline void Category(char* _words) {
	cout << _words << endl;
}

int main() {
	//Select sort type
	while (true) {
		int select = -1;
		Category(new char[] {"0. 나가기"});
		Category(new char[] {"1. 퀵정렬"});
		Category(new char[] {"2. 힙정렬"});
		cout << "선택해주세요 : ";
		cin >> select;
		switch (select) {
		case 0:
			return 0;
			break;
		case 1:
			QuickSort::Main();
			break;
		case 2:
			HeapSort::Main();
			break;
		default :
			cout << "잘못된 선택입니다" << endl;
			break;
		}
		system("pause");
	}
	return 0;
}