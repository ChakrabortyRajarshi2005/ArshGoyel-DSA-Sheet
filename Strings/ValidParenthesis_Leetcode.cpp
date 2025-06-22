#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        // Push opening brackets to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            // If stack is empty or top doesn't match the current closing bracket
            if (st.empty()) return false;
            char top = st.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
            st.pop(); // matched, so pop it
        }
    }

    return st.empty(); // all brackets matched
}

int main() {
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;

    if (isValid(s)) {
        cout << "The parentheses are valid." << endl;
    } else {
        cout << "The parentheses are NOT valid." << endl;
    }

    return 0;
}
