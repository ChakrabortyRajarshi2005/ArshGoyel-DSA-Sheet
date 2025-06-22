20. Valid Parentheses
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'

----------------------------------------------------------------------------------------------------------------------------------------

class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) =='(' || s.charAt(i)=='{' || s.charAt(i)=='['){
                st.push(s.charAt(i));
            }else{
               if(st.isEmpty()== true){
                return false;
                }else{
                    if((s.charAt(i)==')' && st.peek() != '(') ||
                        (s.charAt(i)=='}' && st.peek() != '{') ||
                        (s.charAt(i)==']' && st.peek() != '[')){
                            return false;
                        }else{
                            st.pop();
                        }
               }
            }
        }
      return  st.empty();
    }
}
-----------------------------------------------------

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
