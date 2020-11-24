#include "Global.h"

void QuickSort::Sort(int* _arr, int _size) {
	if (_size <= 1) return;
	int pivot = _arr[0];
	int i = 0;
	int j = _size - 1;
	while (i <= j) {
		while (i < _size && _arr[i] <= pivot) i++;
		while (j > 0 && _arr[j] >= pivot) j--;
		if (i > j) {
			Array::Swap<int>(&_arr[0], &_arr[j]);
		}
		else {
			Array::Swap<int>(&_arr[i], &_arr[j]);
		}
	}
	Sort(_arr, j);
	Sort(_arr + j + 1, _size - j - 1);
}

int QuickSort::Main() {
	cout << "�迭�� ũ�⸦ �Է����ּ��� : ";
	int size;
	cin >> size;

	cout << "�迭�� �Է����ּ��� : ";
	int *arr = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	cout << "�� ���� �� �迭 �Դϴ�." << endl;
	Array::PrintArr(arr);

	Sort(arr, size);

	cout << "�� ���� �� �迭 �Դϴ�." << endl;
	Array::PrintArr(arr);

	delete[] arr;
	return 0;
}