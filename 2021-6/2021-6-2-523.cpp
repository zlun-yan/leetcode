//
// Created by ZlunYan on 2021/6/2.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 前缀和 + 同余定理
// 同余定理: 如果两个数 m 和 n 满足 m - n 能被k整除 那么 m 与 n 对k同余
bool checkSubarraySum(vector<int>& nums, int k) {
    map<int, bool> hashMap;
    hashMap[0] = true;
    int result = nums[0] % k;
    if (hashMap[result]) return true;
    hashMap[result] = true;
    for (int i = 1; i < nums.size(); i++) {
        nums[i] += nums[i - 1];
        result = nums[i] % k;
        if (hashMap[result]) return true;
        hashMap[result] = true;
    }
    return false;
}

int main () {
    vector<int> input = {23,2,6,4,7};
    cout << checkSubarraySum(input, 13) << endl;
    return 0;
}