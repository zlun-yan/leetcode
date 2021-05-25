//
// Created by ZlunYan on 2021/5/25.
//

// 简单的dp啦
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_AMOUNT = 10010;
int dp[MAX_AMOUNT] = {0}; // dp[i] 代表 amount = i时，所需的最少硬币个数

int coinChange(vector<int>& coins, int amount) {
    for (int i = 1; i <= amount; i++) {
        dp[i] = MAX_AMOUNT;
        for (int j = 0; j < coins.size(); j++) if (coins[j] <= i) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    }
    return dp[amount] == MAX_AMOUNT ? -1 : dp[amount];
}

int main () {
    vector<int> input = {2, 4, 6};
    printf("%d\n", coinChange(input, 9999));
    return 0;
}