//
// Created by ZlunYan on 2021/5/23.
//

#include <cstdio>
#include <stack>
#include <cstdint>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    stack<int> digit;
    for (int i = 0; i < 32; i++) digit.push(n & (1 << i) ? 1 : 0);
    uint32_t answer = 0;
    for (int i = 0; i < 32; i++) {
        answer += digit.top() << i; digit.pop();
    }

    return answer;
}

int main () {
    printf("%ld", reverseBits(43261596));
}

/*
class Solution {
private:
    const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
    const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
    const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
    const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111

public:
    uint32_t reverseBits(uint32_t n) {
        n = n >> 1 & M1 | (n & M1) << 1;
        n = n >> 2 & M2 | (n & M2) << 2;
        n = n >> 4 & M4 | (n & M4) << 4;
        n = n >> 8 & M8 | (n & M8) << 8;
        return n >> 16 | n << 16;
    }
};
*/

// 这个是leetcode上面的题解 时间复杂度为O(1)!!!