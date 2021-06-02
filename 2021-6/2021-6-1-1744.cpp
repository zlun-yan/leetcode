//
// Created by ZlunYan on 2021/6/1.
//

#include <iostream>
#include <vector>
using namespace std;

// 注意是由第0天的
// 这里采用int会溢出 但是问题不大 重新建一个longlong数组保存前缀和就好了 这个题目没什么意思
vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    vector<bool> answer;
    for (int i = 1; i < candiesCount.size(); i++) candiesCount[i] += candiesCount[i - 1];
    for (int i = 0; i < queries.size(); i++) {
        if (queries[i][0]) answer.push_back(candiesCount[queries[i][0]] >= queries[i][1] + 1 && queries[i][2] * (queries[i][1] + 1) > candiesCount[queries[i][0] - 1]);
        else answer.push_back(candiesCount[queries[i][0]] >= queries[i][1] + 1);
    }
    return answer;
}

int main () {
    vector<int> input1 = {7,4,5,3,8};
    vector<vector<int>> input2 = {
            {0,2,2},
            {4,2,4},
            {2,13,1000000000}
    };

    vector<bool> answer = canEat(input1, input2);
    for (int i = 0; i < answer.size(); i++) cout << answer[i] << endl;
    return 0;
}