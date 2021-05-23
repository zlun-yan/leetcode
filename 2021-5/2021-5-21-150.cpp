//
// Created by ZlunYan on 2021/5/21.
//

// 注意解决负数的问题
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<string> tokens = {"3","-4","+"};

    stack<int> nums;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i].length() == 1 && (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")) {
            int num1 = nums.top();nums.pop();
            int num2 = nums.top();nums.pop();
            switch (tokens[i][0]) {
                case '+':
                    nums.push(num2 + num1);
                    break;
                case '-':
                    nums.push(num2 - num1);
                    break;
                case '*':
                    nums.push(num2 * num1);
                    break;
                case '/':
                    nums.push(num2 /  num1);
                    break;
            }
        } else {
            if (tokens[i][0] == '-') {
                int num = 0;
                for (int j = 1; j < tokens[i].length(); j++) num = num * 10 + tokens[i][j] - '0';
                nums.push(-num);
            } else {
                int num = 0;
                for (int j = 0; j < tokens[i].length(); j++) num = num * 10 + tokens[i][j] - '0';
                nums.push(num);
            }
        }
    }

    printf("%d\n", nums.top());
    return 0;
}