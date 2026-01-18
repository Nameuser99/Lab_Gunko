#include "stack.h"

Stack::Stack() {
    capacity = 5;
    data = new double[capacity];
    current_size = 0;
}

Stack::Stack(const Stack& other) {
    capacity = other.capacity;
    current_size = other.current_size;
    data = new double[capacity];
    for (int i = 0; i < current_size; ++i) {
        data[i] = other.data[i];
    }
}

Stack::~Stack() {
    delete[] data;
}

void Stack::resize() {
    int new_capacity = capacity + 5;
    double* new_data = new double[new_capacity];
    for (int i = 0; i < current_size; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        current_size = other.current_size;
        data = new double[capacity];
        for (int i = 0; i < current_size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

Stack& Stack::operator<<(double value) {
    if (current_size >= capacity) {
        resize();
    }
    data[current_size] = value;
    ++current_size;
    return *this;
}

Stack& Stack::operator>>(double& value) {
    if (current_size > 0) {
        --current_size;
        value = data[current_size];
    }
    return *this;
}

bool Stack::operator<(const Stack& other) const {
    if (current_size != other.current_size) {
        return current_size < other.current_size;
    }
    return false;
}

bool Stack::operator==(const Stack& other) const {
    if (current_size != other.current_size) {
        return false;
    }
    for (int i = 0; i < current_size; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

double Stack::operator[](int index) const {
    if (index >= 0 && index < current_size) {
        return data[index];
    }
    return 0.0;
}

bool Stack::empty() const {
    return current_size == 0;
}

int Stack::size() const {
    return current_size;
}

void Stack::push(double value) {
    if (current_size >= capacity) {
        resize();
    }
    data[current_size] = value;
    ++current_size;
}

double Stack::pop() {
    if (current_size > 0) {
        --current_size;
        return data[current_size];
    }
    return 0.0;
}

double Stack::top() const {
    if (current_size > 0) {
        return data[current_size - 1];
    }
    return 0.0;
}