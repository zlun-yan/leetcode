//
// Created by ZlunYan on 2021/5/27.
//

// 之前也有这个hamming处理
#include <cstdio>

int hammingDistance(int x, int y) {
    x ^= y;
    int answer = 0;
    while (x) {
        x &= x - 1;
        answer ++;
    }
    return answer;
}

int main () {
    printf("%d\n", hammingDistance(1, 4));
    return 0;
}