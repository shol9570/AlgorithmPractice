#include "Global.h"

int main() {
	while (true) {
		cout << "0. ����" << endl;
		cout << "1. BFS" << endl;
		cout << "��带 �������ּ��� : ";
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
			cout << "�߸��� ����Դϴ�." << endl;
		}
		cout << "�ɸ� �ð� : " << (double)(clock() - t) / CLOCKS_PER_SEC << endl;
	}
	return 0;
}