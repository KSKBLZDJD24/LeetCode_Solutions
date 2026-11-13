#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> data_st;   // 主栈：存所有的数据
    stack<int> min_st;    // 辅助栈：存对应的最小值

public:
    MinStack() {
        // 构造没什么要写的，默认就行
    }

    void push(int val) {
        // 【你要补全的地方 1】
        // 1. 主栈无条件 push(val)
        data_st.push(val);
        // 2. 如果辅助栈为空，或者 val <= 辅助栈的栈顶，就把 val 也 push 进辅助栈
        if (min_st.empty() || val <= min_st.top()) {
            min_st.push(val);
        }
    }

    void pop() {
        // 【你要补全的地方 2】
        // 1. 如果主栈为空，直接 return（养成好习惯）
        if (data_st.empty()) return;
        // 2. 如果主栈的栈顶 == 辅助栈的栈顶，说明你刚弹走的正是最小值，辅助栈也要 pop
        if (data_st.top() == min_st.top()) {
            min_st.pop();
        }
        // 3. 主栈自己 pop
        data_st.pop();
    }

    int top() {
        // 【你要补全的地方 3】
        // 直接返回主栈的栈顶
        return data_st.top();
    }

    int getMin() {
        // 【你要补全的地方 4】
        // 直接返回辅助栈的栈顶（不用管主栈）
        return min_st.top();
    }
};

// ========== 下面是测试你的实验的代码（不用改） ==========
int main() {
    MinStack s;
    s.push(5);
    s.push(3);
    s.push(7);

    cout << "当前最小值: " << s.getMin() << endl; // 应该输出 3
    cout << "当前栈顶: " << s.top() << endl;      // 应该输出 7

    s.pop(); // 弹走 7
    cout << "弹走7后，当前最小值: " << s.getMin() << endl; // 应该还是 3

    s.pop(); // 弹走 3
    cout << "弹走3后，当前最小值: " << s.getMin() << endl; // 应该变成 5
    cout << "弹走3后，当前栈顶: " << s.top() << endl;      // 应该变成 5

    return 0;
}