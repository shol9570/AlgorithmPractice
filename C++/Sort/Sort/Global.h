#pragma once

#include <iostream>
#include <list>
#include <string>
using namespace std;

#include "QuickSort.h"

namespace Array {
	template<typename T>
	void Swap(T* _a, T* _b) {
		T temp = *_a;
		*_a = *_b;
		*_b = temp;
	}

	template<typename T>
	void PrintArr(T* _target) {
		int size = _msize(_target) / sizeof(&_target[0]);
		for (int i = 0; i < size; i++) {
			cout << _target[i] << " ";
		}
		cout << endl;
	}
}