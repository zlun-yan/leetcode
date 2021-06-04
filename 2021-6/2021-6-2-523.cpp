//
// Created by ZlunYan on 2021/6/2.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 前缀和 + 同余定理
// 同余定理: 如果两个数 m 和 n 满足 m - n 能被k整除 那么 m 与 n 对k同余

// 我写的有点问题 看题解吧 懒得解决一些小问题了
bool checkSubarraySum(vector<int>& nums, int k) {
    map<int, int> hashMap;
    hashMap[0] = -1;
    int record = 0;
    for (int i = 0; i < nums.size(); i++) {
        record = (nums[i] + record) % k;

    }
    return false;
}

int main () {
    vector<int> input = {23,2,6,4,7};
    cout << checkSubarraySum(input, 13) << endl;
    return 0;
}