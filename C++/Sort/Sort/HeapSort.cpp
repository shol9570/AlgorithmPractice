#include "Global.h"

void HeapSort::Heapify(int* _arr, int _start, int _size) {
	int child1 = Child1(_start);
	int child2 = Child2(_start);
	int max = _start;
	if (child1 < _size && _arr[child1] > _arr[max]) max = child1;
	if (child2 < _size && _arr[child2] > _arr[max]) max = child2;
	if (max != _start) {
		swap(_arr[_start], _arr[max]);
		Heapify(_arr, max, _size);
	}
}

void HeapSort::BuildHeap(int* _arr, int _size) {
	for (int i = Parent(_size); i >= 0; i--) {
		Heapify(_arr, i, _size);
	}
}

void HeapSort::HeapSort(int* _arr, int _size) {
	BuildHeap(_arr, _size);
	for (int i = _size - 1; i >= 0; i--) {
		swap(_arr[0], _arr[i]);
		Heapify(_arr, 0, i);
	}
}

int HeapSort::Main() {
	cout << "배열의 크기를 입력해주세요 : ";
	int size;
	cin >> size;

	cout << "배열을 입력해주세요 : ";
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	cout << "힙 정렬 전 배열 입니다." << endl;
	Array::PrintTree<int>(arr);

	HeapSort(arr, size);

	cout << "힙 정렬 후 배열 입니다." << endl;
	Array::PrintTree<int>(arr);

	delete[] arr;
	return 0;
}