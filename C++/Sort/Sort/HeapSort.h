#pragma once

namespace HeapSort {
	void Heapify(int* _arr, int _start, int _size);
	void BuildHeap(int* _arr, int _size);
	void HeapSort(int* _arr, int _size);
	int Main();
}