//
// Created by ZlunYan on 2021/5/25.
//

#include <cstdio>
#include <vector>
using namespace std;

// 从奇偶性入手：
/*
 * 奇数个0和偶数个1异或：0
 * 奇数个0和奇数个1异或：1
 * 偶数个0和偶数个1异或：0
 * 偶数个0和奇数个1异或：1
 */

/*
 * 如果数组长度为奇数：
 * 如果数组长度为偶数：
 */

// 奇偶性好像不行
// 这个还有数组长度k的约束
// 利用异或的性质
int minChanges(vector<int>& nums, int k) {
    int answer = 0;
    for (int i = 0; i < k; i++) {
        int record = nums[i], index = i + k;
        while (index < nums.size()) {
            record ^= nums[index];
            index += k;
        }
        printf("%d\n", record);
        if (record) {
            answer++;
        }
    }

    return answer;
}

int main () {
    vector<int> nums = {1,2,0,3,0};
    printf("%d\n", minChanges(nums, 1));
    return 0;
}