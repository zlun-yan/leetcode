//
// Created by ZlunYan on 2021/6/7.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 动态规划
int findTargetSumWays(vector<int>& nums, int target) {
    map<int, map<int, int>> dp;
    dp[0][nums[0]] = 1; dp[0][- nums[0]] = 1;
    for (int i = 1; i < nums.size(); i++) {
        map<int, int>::iterator it = dp[i - 1].begin();
        while (it != dp[i - 1].end()) {
            dp[i][it->first + nums[i]] += it->second;
            dp[i][it->first - nums[i]] += it->second;
            it ++;
        }
    }

    return dp[nums.size() - 1][target];
}

int main () {
    vector<int> input = {1};
    cout << findTargetSumWays(input, 1) << endl;
    return 0;
}