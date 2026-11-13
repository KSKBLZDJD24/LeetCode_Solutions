#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string s : tokens) {
            // 如果是加号
            if (s == "+") {
                // 【你要补全的地方：弹出两个数，相加，压回去】
                int right = st.top();
                st.pop();

                int left = st.top();
                st.pop();

                st.push(right + left);
            }
            else if (s == "-") {
                // 【你要补全的地方：注意顺序！左 - 右】
                int right = st.top();
                st.pop();

                int left = st.top();
                st.pop();

                st.push(left - right);
            }
            else if (s == "*") {
                // 【你要补全的地方】
                int right = st.top();
                st.pop();

                int left = st.top();
                st.pop();

                st.push(right * left);
            }
            else if (s == "/") {
                // 【你要补全的地方：注意顺序！左 / 右】
                int right = st.top();
                st.pop();

                int left = st.top();
                st.pop();

                st.push(left / right);
            }
            else {
                // 如果不是这四个符号，说明是数字字符串，转成整数入栈
                st.push(stoi(s));
            }
        }

        // 最后返回栈顶的唯一元素
        return st.top();
    }
};