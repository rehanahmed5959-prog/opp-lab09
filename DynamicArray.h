#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
private:
    T* data;
    int count;
    int capacity;

    void grow();

public:
    DynamicArray(int cap = 2);
    ~DynamicArray();
    void push_back(T value);
    bool removeAt(int index);
    T get(int index);
    int size();
    int getCapacity();
    bool isEmpty();
};

template <typename T>
void DynamicArray<T>::grow() {
    int newCapacity = capacity * 2;
    T* bigger = new T[newCapacity];

    for (int i = 0; i < count; i++) {
        bigger[i] = data[i];
    }

    delete[] data;
    data = bigger;
    capacity = newCapacity;
}

template <typename T>
DynamicArray<T>::DynamicArray(int cap) {
    capacity = cap;
    count = 0;
    data = new T[capacity];
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template <typename T>
void DynamicArray<T>::push_back(T value) {
    if (count == capacity) {
        grow();
    }
    data[count] = value;
    count++;
}

template <typename T>
bool DynamicArray<T>::removeAt(int index) {
    if (index < 0 || index >= count) {
        return false;
    }
    for (int i = index; i < count - 1; i++) {
        data[i] = data[i + 1];
    }
    count--;
    return true;
}

template <typename T>
T DynamicArray<T>::get(int index) {
    return data[index];
}

template <typename T>
int DynamicArray<T>::size() {
    return count;
}

template <typename T>
int DynamicArray<T>::getCapacity() {
    return capacity;
}

template <typename T>
bool DynamicArray<T>::isEmpty() {
    return count == 0;
}

#endif