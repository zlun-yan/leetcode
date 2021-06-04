//
// Created by ZlunYan on 2021/6/3.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 把0 当作 -1
int findMaxLength(vector<int>& nums) {
    map<int, int> mp; mp[nums[0] ? 1 : -1] = 1;
    int answer = 0;
    nums[0] = nums[0] ? 1 : -1;
    for (int i = 1; i < nums.size(); i++) {
        nums[i] = nums[i - 1] + (nums[i] ? 1 : -1);
        if (!nums[i]) answer = max(answer, i + 1);
        else if (mp[nums[i]]) answer = max(answer, i - mp[nums[i]] + 1);
        else mp[nums[i]] = i + 1;
    }
    return answer;
}

int main () {
    vector<int> input = {0, 1, 0};
    cout << findMaxLength(input) << endl;
    return 0;
}