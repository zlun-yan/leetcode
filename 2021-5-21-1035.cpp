//
// Created by ZlunYan on 2021/5/21.
//

// 最长公共子序列  动态规划
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int LEN = 505;
int dp[LEN][LEN] = {0};

int main () {
    /*
     * [2,5,1,2,5]
     * [10,5,2,1,5,2]
     */
    /*
     * [4,3,5,5,5,4,5,2,1,3,3,5,1,5,2,4,2,1,2,3,3,3,5,3,4,2,2,3,5,1]
     * [1,2,4,4,1,3,2,2,1,5,5,5,2,1,2]
     */
    vector<int> nums1 = {2,5,1,2,5};
    vector<int> nums2 = {10,5,2,1,5,2};
    // 为了方便，数组下标计数从1开始吧 即 index = index - 1

    for (int i = 1; i <= nums1.size(); i++) {
        for (int j = 1; j <= nums2.size(); j++) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
//                printf("(%d: %d, %d: %d): (%d)\n", i, nums1[i - 1], j, nums2[j - 1], dp[i][j]);
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    /*
    for (int i = 0; i <= nums1.size(); i++) {
        for (int j = 0; j <= nums2.size(); j++) {
            printf("(%d, %d): %d\n", i, j, dp[i][j]);
        }
    }
     */
    printf("%d\n", dp[nums1.size()][nums2.size()]);
    return 0;
}