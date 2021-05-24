//
// Created by ZlunYan on 2021/5/24.
//

// hamming 法 可以看看191题
#include <cstdio>

// 其实也就是求从 left 到 right 的二进制数的公共前缀
// 可以看看题解中的分析 这个区间里面所有的数的公共前缀 其实也就是left和right的公共前缀
int rangeBitwiseAnd(int left, int right) {
    while (right > left) right &= right - 1;
    return right;
}

int main () {
    printf("%d\n", rangeBitwiseAnd(5, 7));
    return 0;
}