#ifndef STACK_H
#define STACK_H
#include <iostream>
namespace my {
    class Stack {
        size_t n{0};
        int* data[10];
        const int full = 10;
    public:
        void push(int value) {
            if(n == full) return;
            data[n] = value;
            n++;
        }
        void pop() {
            if (n == 0) return;
            data[n] = 0;
            n--;
        }
        int top() {
            return data[n];
        }
        bool isEmpty() {
            return n;
        }
    };
}

#endif // STACK_H
