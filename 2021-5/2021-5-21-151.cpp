//
// Created by ZlunYan on 2021/5/21.
//

#include <cstring>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

int main() {
    string s = "  hello world!  ";

    string temp = "";
    stack<string> strStack;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            if (temp != "") {
                strStack.push(temp);
                temp = "";
            }
        } else {
            temp = temp + s[i];
        }
    }

    if (temp != "") strStack.push(temp);
    temp = strStack.top();strStack.pop();
    while (!strStack.empty()) {
        temp = temp + " " + strStack.top();
        strStack.pop();
    }

    cout << temp;

    return 0;
}