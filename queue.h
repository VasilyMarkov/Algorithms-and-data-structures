#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <algorithm>
constexpr size_t N{5};
namespace my {
class MyCircularQueue {
    size_t size{0};
    int* data;
    size_t tail{0};
    size_t head{0};
public:
    MyCircularQueue(int k) {
        size = k;
        data = new int[size];
    }

    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        if(isEmpty()) head = 0;
        data[tail] = value;
        if(!(tail == size - 1))
            tail++;
        return true;
    }

    bool deQueue() {        
        if(isEmpty()) {
            return false;
        }
        else {
            head++;
        }
        return true;
    }

    int Front() {
        if(isEmpty()) return -1;
        return data[head];
    }

    int Rear() {
        if(isEmpty()) return -1;
        return data[tail];
    }

    bool isEmpty() {
        return tail == head;
    }

    bool isFull() {
        return tail - head == size-1;
    }
};

class BinaryHeap {
    int data[100];
    size_t heapSize = 0;
public:
    void insert(int val) {
        heapSize++;
        data[heapSize-1] = val;
        siftUp(heapSize-1);
    }
    void siftUp(int i) {
            while(data[i] < data[(i-1)/2]) {
                std::swap(data[i], data[(i-1)/2]);
                i = (i-1)/2;
        }
    }
    int extractMin() {
        int min = data[0];
        data[0] = data[heapSize-1];
        heapSize = heapSize-1;
        siftDown(0);
        return min;
    }
    void siftDown(int i) {
        while (2*i+1< heapSize) {
            int left = 2*i+1;
            int right = 2*i+2;
            auto j = left;
            if (right < heapSize && data[right] < data[left]) {
                j = right;
            }
            if(data[i] < data[j])
                break;
            std::swap(data[i], data[j]);
            i = j;
        }
    }
};

}
#endif // QUEUE_H
