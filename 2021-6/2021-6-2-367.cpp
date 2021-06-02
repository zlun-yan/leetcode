//
// Created by ZlunYan on 2021/6/2.
//

#include <iostream>
using namespace std;

bool isPerfectSquare(int num) {
    int left = 1, right = 46340;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (mid * mid <= num) left = mid + 1;
        else right = mid - 1;
    }
    return right * right == num;
}

int main () {
    cout << isPerfectSquare(16) << endl;
    return 0;
}