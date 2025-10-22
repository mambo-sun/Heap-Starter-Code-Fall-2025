//
// Created by we7289 on 3/13/2024.
//

#include "Heap.h"

void swap(int *array, int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

template<class T>
Heap<T>::Heap() {
    max_size = 100;
    size = 0;
    elements = new T[max_size];
}

template<class T>
Heap<T>::Heap(int max_size) {
    this->max_size = max_size;
    size = 0;
    elements = new T[max_size];
}

// Left = 2*i + 1
// right = 2*1 + 2
// parent = (i - 1) / 2

template<class T>
void Heap<T>::ReheapUp(T value) {
    if (size >= max_size) {
        throw FullHeap();
    }
    elements[size] = value; // number of elements
    int currInd = size;     //
    while (currInd != 0) {
        int parentInd = (currInd - 1) / 2;
        if (elements[parentInd] < elements[currInd]) {
            swap(elements, currInd, parentInd);
            currInd = parentInd;
        } else {
            break;
        }
    }
    size++;
}

template<class T>
T Heap<T>::ReheapDown() {   // Returns the top most element
    T priority_value = elements[0];

    elements[0] = elements[size - 1];
    --size;

    int currInd = 0;
    int bottomInd = size - 1;

    int leftInd = currInd * 2 + 1;
    int rightInd = currInd * 2 + 2;
    int maxChildInd;

    while (currInd != bottomInd) {

        if (leftInd == bottomInd) {
            // If the bottom is the left child there is no right branch
            // Left must be the max child.
            maxChildInd = leftInd;
        } else if (elements[leftInd] > elements[rightInd]) {
            maxChildInd = leftInd;
        } else {
            maxChildInd = rightInd;
        }

        if (elements[currInd] < elements[maxChildInd]) {
            swap(elements, currInd, maxChildInd);
            currInd = maxChildInd;
        } else {
            break;
        }

        leftInd = currInd * 2 + 1;
        rightInd = currInd * 2 + 2;

    }

    return priority_value;
}











