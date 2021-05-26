//
// Created by ZlunYan on 2021/5/26.
//

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int LEN = 305;
int dp[LEN][LEN] = {0};
int dir[3][2] = {{1, 0}, {0, 1}, {1, 1}};
int maximalSquare(vector<vector<char>>& matrix) {
    int rowNum = matrix.size(), colNum = matrix[0].size(), answer = 0;
    for (int i = rowNum - 1; i >= 0; i--) dp[i][colNum - 1] = matrix[i][colNum - 1] - '0';  // 每一行的最后一列
    for (int i = colNum - 1; i >= 0; i--) dp[rowNum - 1][i] = matrix[rowNum - 1][i] - '0';  // 每一列的最后一行

    for (int i = rowNum - 2; i >= 0; i--) {
        for (int j = colNum - 2; j >= 0; j--) {
            if (matrix[i][j] == '1') {
                dp[i][j] = 305;
                for (int k = 0; k < 3; k++) dp[i][j] = min(dp[i][j], dp[i + dir[k][0]][j + dir[k][1]] + 1);
                answer = max(answer, dp[i][j] * dp[i][j]);
            }
        }
    }

    return answer;
}

int main () {
    vector<vector<char>> input = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };

    printf("%d\n", maximalSquare(input));
    return 0;
}