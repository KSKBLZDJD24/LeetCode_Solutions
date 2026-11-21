#include <iostream>
#include "MyCircularDeque.h"

using namespace std;

int main() {
    // 测试用例：容量为 3
    MyCircularDeque deque(3);

    cout << "插入尾 1: " << deque.insertLast(1) << " (预期 1)" << endl;
    cout << "插入尾 2: " << deque.insertLast(2) << " (预期 1)" << endl;
    cout << "插入头 3: " << deque.insertFront(3) << " (预期 1)" << endl;
    cout << "插入头 4: " << deque.insertFront(4) << " (预期 0, 因为满了)" << endl;

    cout << "队尾元素: " << deque.getRear() << " (预期 2)" << endl;
    cout << "是否满:   " << deque.isFull() << " (预期 1)" << endl;
    cout << "删除尾:   " << deque.deleteLast() << " (预期 1)" << endl;
    cout << "插入头 4: " << deque.insertFront(4) << " (预期 1)" << endl;
    cout << "队头元素: " << deque.getFront() << " (预期 4)" << endl;

    return 0;
}