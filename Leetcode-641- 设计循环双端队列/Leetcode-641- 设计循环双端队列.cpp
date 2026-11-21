#include "MyCircularDeque.h"

// 构造函数
MyCircularDeque::MyCircularDeque(int k)
{
    capacity = k;
    a.resize(k);
    front = 0;
    rear = 0;
    count = 0;
}

// 在队头插入
bool MyCircularDeque::insertFront(int value)
{
    if (isFull())
    {
        return false;
    }

    // front 往左退一格，要加 capacity 防负数
    front = (front - 1 + capacity) % capacity;

    a[front] = value;
    count++;
    return true;
}

// 在队尾插入
bool MyCircularDeque::insertLast(int value)
{
    if (isFull())
    {
        return false;
    }

    a[rear] = value;

    // rear 往右进一格
    rear = (rear + 1) % capacity;

    count++;
    return true;
}

// 删除队头
bool MyCircularDeque::deleteFront()
{
    if (isEmpty())
    {
        return false;
    }

    // front 往右进一格
    front = (front + 1) % capacity;

    count--;
    return true;
}

// 删除队尾
bool MyCircularDeque::deleteLast()
{
    if (isEmpty())
    {
        return false;
    }

    // rear 往左退一格，要加 capacity 防负数
    rear = (rear - 1 + capacity) % capacity;

    count--;
    return true;
}

// 获取队头元素
int MyCircularDeque::getFront()
{
    if (isEmpty())
    {
        return -1;
    }
    return a[front];
}

// 获取队尾元素
int MyCircularDeque::getRear()
{
    if (isEmpty())
    {
        return -1;
    }

    // rear 是空位，真实的队尾在 rear 左边一格，同样防负数
    return a[(rear - 1 + capacity) % capacity];
}

bool MyCircularDeque::isEmpty()
{
    return count == 0;
}

bool MyCircularDeque::isFull()
{
    return count == capacity;
}
