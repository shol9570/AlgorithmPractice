#pragma once

#include <iostream>
#include <list>
#include <string>
using namespace std;

#include "QuickSort.h"
#include "HeapSort.h"

#define Parent(x) ((x-1)/2)
#define Child1(x) ((x*2)+1)
#define Child2(x) ((x*2)+2)

namespace Array {
	template<typename T>
	inline void PrintArr(T* _target) {
		int size = _msize(_target) / sizeof(&_target[0]);
		for (int i = 0; i < size; i++) {
			cout << _target[i] << " ";
		}
		cout << endl;
	}

	template<typename T>
	inline void PrintTree(T* _target) {
		int size = _msize(_target) / sizeof(_target[0]);
		int compare = 0;
		while (compare < size) compare = Child1(compare);
		compare = Parent(compare);

		int i = 0;
		while (i < size) {
			for (int j = i; j < (i * 2) + 1 && j < size; j++) {
				for (int x = 0; x < compare; x++) cout << "\t";
				cout << _target[j] << "\t\t";
				for (int x = 0; x < compare; x++) cout << "\t";
			}
			cout << endl;
			compare = Parent(compare);
			i = Child1(i);
		}
	}
}