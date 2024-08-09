#include "bitmap.h"
#include <iostream>
#include <stdexcept> 

template<typename T>
Queue<T>::Queue() : size(5), front(0), rear(-1) {
    arr = new T[size];
}

template<typename T>
Queue<T>::Queue(int s) : size(s), front(0), rear(-1) {
    arr = new T[size];
}

template<typename T>
Queue<T>::~Queue() {
    delete[] arr;
}

template<typename T>
void Queue<T>::insert(T element) {
    if (isfull()) {
        throw std::overflow_error("Queue is full");
    }
    rear = (rear + 1) % size;
    arr[rear] = element;
}

template<typename T>
T Queue<T>::remove() {
    if (isempty()) {
        throw std::underflow_error("Queue is empty");
    }
    T element = arr[front];
    front = (front + 1) % size;
    return element;
}

template<typename T>
bool Queue<T>::isfull() {
    return (rear + 1) % size == front;
}

template<typename T>
bool Queue<T>::isempty() {
    return front == (rear + 1) % size;
}
