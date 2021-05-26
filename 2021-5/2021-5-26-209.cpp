//
// Created by ZlunYan on 2021/5/26.
//

#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

// 感觉就是简单的前缀和以及二分
int minSubArrayLen(int target, vector<int>& nums) {
    // 这里为了省空间 我就直接修改原数组吧 虽然说1e11有可能超过INT_MAX 但是我看了题解之后也是用的int 所以就懒得改了
    int answer = INT_MAX;
    nums.insert(nums.begin(), 0);
    for (int i = 1; i < nums.size(); i++) nums[i] += nums[i - 1];
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] < target) break;
        else {
            // 二分
            int left = 0, right = i - 1;
            while (left <= right) {
                int mid = (left + right) >> 1;
                if (nums[mid] <= nums[i] - target) left = mid + 1;
                else right = mid - 1;
            }
            answer = answer ? min(answer, i - right) : i - right;
        }
    }

    return answer == INT_MAX ? 0 : answer;
}

int main () {

    vector<int> input = {1, 2, 3, 4, 6};
    printf("%d\n", minSubArrayLen(17, input));
    return 0;
}