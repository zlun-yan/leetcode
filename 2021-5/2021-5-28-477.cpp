//
// Created by ZlunYan on 2021/5/28.
//

#include <cstdio>
#include <vector>
using namespace std;

int totalHammingDistance(vector<int>& nums) {
    int count[35] = {0};
    for (int i = 0; i < nums.size(); i++) for (int j = 0; j < 31; j++) if (nums[i] & (1 << j)) count[j] ++;
    int answer = 0;
    for (int i = 0; i < 31; i++) answer += (nums.size() - count[i]) * count[i];
    return answer;
}

int main () {
    vector<int> input = {4, 14, 2};
    printf("%d\n", totalHammingDistance(input));
    return 0;
}