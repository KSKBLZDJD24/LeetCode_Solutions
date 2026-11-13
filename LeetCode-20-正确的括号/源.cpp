#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string s) {
	stack<char> st;

	for(int i = 0;i<s.length();i++){
		char c = s[i];

		if (c == '(' || c == '[' || c == '{') {
			st.push(c);
		}

		else {
			if (st.empty()) {
				return false;
			}

			char top = st.top();

			if (c == ')' && top != '(') return false;
			if (c == ']' && top != '[') return false;
			if (c == '}' && top != '{') return false;

			st.pop();

		}
	}
	return st.empty();
}


int main() { 
	cout << isValid("{[()]}") << endl;
	cout << isValid("{[(])}") << endl;
	return 0;
}
