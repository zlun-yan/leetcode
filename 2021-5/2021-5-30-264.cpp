//
// Created by ZlunYan on 2021/5/30.
//

// 这个题目 是我未曾设想的道路哈
#include <cstdio>
#include <algorithm>
using namespace std;

// 三指针
/*
 * p2: 代表我想要dp[p2] * 2 加入数组
 * p3: 代表我想要dp[p3] * 3 加入数组
 * p5: 代表我想要dp[p5] * 5 加入数组
 */
/*
 * 当我比较得到 dp[px] * x 是最小的时候, 就会将dp[px] * x 加入数组
 * 那么接下来我要考虑的就是将 dp[px+1] * x 加入数组了
 */
/*
 * 但是有可能有重复元素, 注意按照这个流程, 重复元素计算出来肯定是在一起比较的
 * 比如说在某一次计算中, dp[px1] * x1 == dp[px2] * x2
 * 那么就相当于这两个都进入了数组呗(都是最小的元素)
 * 所以 px1 ++; px2 ++;
 */
const int LEN = 1695;
int dp[LEN] = {0};

int nthUglyNumber(int n) {
    dp[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; i++) {
        int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
        dp[i] = min(num2, min(num3, num5));
        if (num2 == dp[i]) p2++;
        if (num3 == dp[i]) p3++;
        if (num5 == dp[i]) p5++;
    }
    return dp[n];
}

int main () {
    printf("%d\n", nthUglyNumber(10));
    return 0;
}