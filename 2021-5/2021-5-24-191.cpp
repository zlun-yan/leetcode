//
// Created by ZlunYan on 2021/5/24.
//

// hoho 这个题目挺有意思的
#include <cstdio>
#include <cstdint>

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        n &= n - 1;
        count++;
    }
    return count;
}

int main () {
    printf("%d\n", hammingWeight(11));
    return 0;
}