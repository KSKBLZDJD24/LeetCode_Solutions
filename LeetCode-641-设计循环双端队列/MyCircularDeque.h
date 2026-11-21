#pragma once

#include <vector>

class MyCircularDeque
{
private:
    std::vector<int> a;
    int front;
    int rear;
    int capacity;
    int count;

public:
    MyCircularDeque(int k);

    bool insertFront(int value);
    bool insertLast(int value);
    bool deleteFront();
    bool deleteLast();

    int getFront();
    int getRear();

    bool isEmpty();
    bool isFull();
};
