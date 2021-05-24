//
// Created by ZlunYan on 2021/5/24.
//

// 区间DP，感觉这个题挺有意思的
//
#include <cstdio>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

const int LEN = 105;
int dp[LEN][LEN] = {0};

int strangePrinter(string s) {

    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) dp[i][j] = INT_MAX;
        dp[i][i] = 1;
    }
    for (int len = 1; len < s.length(); len++) {
        for (int i = 0; i < s.length() - len; i++) {
            if (s[i] == s[i + len]) dp[i][i + len] = dp[i][i + len - 1];
            else for (int j = i; j < i + len; j++) dp[i][i + len] = min(dp[i][i + len], dp[i][j] + dp[j + 1][i + len]);
        }
    }
    return dp[0][s.length() - 1];
}

int main () {
    printf("%d\n", strangePrinter("aaaaaa"));
    return 0;
}