//
// Created by ZlunYan on 2021/5/25.
//

// 本来想用最长递增子序列的,但是这完全没有必要啊
// 只需要遍历一遍,然后记录就行了

#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int pre = INT_MAX, prepre = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        if (pre < nums[i]) return true;
        else {
            if (prepre < nums[i]) pre = nums[i];
            else prepre = nums[i];
        }
    }

    return false;
}

int main () {
    vector<int> input = {5, 1, 6};
    printf("%d\n", increasingTriplet(input));
    return 0;
}