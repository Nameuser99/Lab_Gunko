#ifndef STACK_H
#define STACK_H

class Stack {
private:
    double* data;
    int capacity;
    int current_size;
    void resize();

public:
    Stack();
    Stack(const Stack& other);
    ~Stack();
    Stack& operator=(const Stack& other);
    Stack& operator<<(double value);
    Stack& operator>>(double& value);
    bool operator<(const Stack& other) const;
    bool operator==(const Stack& other) const;
    double operator[](int index) const;
    bool empty() const;
    int size() const;
    void push(double value);
    double pop();
    double top() const;
};

#endif