
#include <vector>
using namespace std;

class MyCircularDeque {
private:
    vector<int> data;
    int front, rear, size, capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        data.resize(k);
        front = 0;
        rear = k - 1;
        size = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        data[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : data[front];
    }
    
    int getRear() {
        return isEmpty() ? -1 : data[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};