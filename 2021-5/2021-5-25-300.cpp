//
// Created by ZlunYan on 2021/5/25.
//

// 最长递增子序列：动态规划
#include <cstdio>
#include <vector>
using namespace std;
const int LEN = 2510;

int dp[LEN] = {0};
// dp[i]表示 以nums[i] 为结尾的最长递增子序列的长度
int lengthOfLIS(vector<int>& nums) {
    int answer = 0;
    for (int i = 0; i < nums.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
        answer = max(answer, dp[i]);
    }
    return answer;
}

int main () {
    vector<int> input = {0,1,0,3,2,3};
    printf("%d\n", lengthOfLIS(input));
    return 0;
}