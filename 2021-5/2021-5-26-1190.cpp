//
// Created by ZlunYan on 2021/5/26.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseParentheses(string s) {
    /*
     * doit == 0 : 没有在括号里面
     * doit != 0 : 在括号里面
     */
    int doit = 0;
    string answer = "";
    stack<stack<char>> strStackStack;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            doit ++;
            stack<char> newStack;
            strStackStack.push(newStack);
        } else if (s[i] == ')') {
            doit --;
            stack<char> topStack = strStackStack.top(); strStackStack.pop();
            if (doit) {
                while (!topStack.empty()) {
                    strStackStack.top().push(topStack.top()); topStack.pop();
                }
            } else {
                while (!topStack.empty()) {
                    answer += topStack.top(); topStack.pop();
                }
            }

        } else {
            if (doit) strStackStack.top().push(s[i]);
            else answer += s[i];
        }
    }

    return answer;
}

int main () {
    cout << reverseParentheses("a(bcdefghijkl(mno)p)q") << endl;
    return 0;
}