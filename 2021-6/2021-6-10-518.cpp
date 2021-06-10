//
// Created by ZlunYan on 2021/6/10.
//

#include <iostream>
#include <vector>
using namespace std;

// dp + 滚动数组
int dp[5005] = {1};
int change(int amount, vector<int>& coins) {
    if (!amount) return 0;
    for (int i = 0; i < coins.size(); i++) for (int j = coins[i]; j <= amount; j ++) dp[j] += dp[j - coins[i]];
    return dp[amount];
}

int main () {
    vector<int> input = {10};
    cout << change(10, input) << endl;
    return 0;
}