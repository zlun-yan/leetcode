//
// Created by ZlunYan on 2021/6/6.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 三维动态规划
// dp[i][j][k]: 在前i个字符串中，使用i个0和j个1的情况下的最大子集大小
// 状态转移方程为: 假设第i个字符串有x个0和y个1
// 则dp[i][j][k] = max(dp[i][j - 1][k], dp[i][j][k - 1], dp[i - 1][j - x][k - y] + 1);
int dp[605][105][105] = {0};
int findMaxForm(vector<string>& strs, int m, int n) {
    int x = 0, y = 0; for (char j : strs[0]) if (j == '0') x++; else y++;
    for (int j = x; j <= m; j++) for (int k = y; k <= n; k++) dp[0][j][k] = 1;

    for (int i = 1; i < strs.size(); i++) {
        x = 0, y = 0; for (char j : strs[i]) if (j == '0') x++; else y++;
        for (int j = 0; j <= m; j++) for (int k = 0; k <= n; k++) {
            dp[i][j][k] = dp[i - 1][j][k]; if (j >= x && k >= y) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - x][k - y] + 1);
        }
    }

    return dp[strs.size() - 1][m][n];
}

int main () {
    vector<string> input = {"10", "0001", "111001", "1", "0"};
    cout << findMaxForm(input, 5, 3) << endl;
    return 0;
}