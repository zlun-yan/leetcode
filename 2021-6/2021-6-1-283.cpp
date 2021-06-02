//
// Created by ZlunYan on 2021/6/1.
//

#include <cstdio>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int point = 0;
    for (int i = 0; i < nums.size(); i++) if (nums[i]) nums[point++] = nums[i];
    for (int i = point; i < nums.size(); i++) nums[i] = 0;
}

int main () {
    vector<int> input = {0,1,0,3,12};
    moveZeroes(input);
    return 0;
}