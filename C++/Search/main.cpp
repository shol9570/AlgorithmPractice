#include "Global.h"

int main() {
	while (true) {
		cout << "0. 종료" << endl;
		cout << "1. BFS" << endl;
		cout << "모드를 선택해주세요 : ";
		int select = -1;
		cin >> select;
		clock_t t = clock();
		switch (select) {
		case 0:
			return 0;
		case 1:
			BFS::Main();
			break;
		default:
			cout << "잘못된 모드입니다." << endl;
		}
		cout << "걸린 시간 : " << (double)(clock() - t) / CLOCKS_PER_SEC << endl;
	}
	return 0;
}