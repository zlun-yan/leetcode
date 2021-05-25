//
// Created by ZlunYan on 2021/5/25.
//

#include <cstdio>

bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    while (n != 1) {
        if (n % 3) return false;
        n /= 3;
    }
    return true;
}

int main () {
    for (int i = 0; i <= 45; i++) {
        printf("%d: %d\n", i, isPowerOfThree(i));
    }
    return 0;
}