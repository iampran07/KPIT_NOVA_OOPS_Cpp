#include "bitmap.h"
#include <iostream>
#include <stdexcept> // for std::out_of_range

template<typename T>
Stack<T>::Stack() : size(5), top(-1) {
    arr = new T[size];
}

template<typename T>
Stack<T>::Stack(int s) : size(s), top(-1) {
    arr = new T[size];
}

template<typename T>
Stack<T>::~Stack() {
    delete[] arr;
}

template<typename T>
void Stack<T>::push(T element) {
    if (isfull()) {
        throw std::overflow_error("Stack is full");
    }
    arr[++top] = element;
}

template<typename T>
T Stack<T>::pop() {
    if (isempty()) {
        throw std::underflow_error("Stack is empty");
    }
    return arr[top--];
}

template<typename T>
T Stack<T>::peep() {
    if (isempty()) {
        throw std::underflow_error("Stack is empty");
    }
    return arr[top];
}

template<typename T>
bool Stack<T>::isfull() {
    return top == size - 1;
}

template<typename T>
bool Stack<T>::isempty() {
    return top == -1;
}
