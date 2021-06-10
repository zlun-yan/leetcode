//
// Created by ZlunYan on 2021/6/8.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 优先队列罢了
// 或者做一个大根堆
//int lastStoneWeightII(vector<int>& stones) {
//    priority_queue<int> priorityQueue;
//    for (int i = 0; i < stones.size(); i++) priorityQueue.push(stones[i]);
//    while (priorityQueue.size() >= 2) {
//        int a = priorityQueue.top(); priorityQueue.pop();
//        int b = priorityQueue.top(); priorityQueue.pop();
//        priorityQueue.push(abs(a - b));
//    }
//
//    return priorityQueue.top();
//}

// 转化为背包问题
// 在不超过 sum / 2 的情况下 重量尽可能的大
int dp[35] = {0};  // dp[i]表示前i个 满足条件的最大重量
int lastStoneWeightII(vector<int>& stones) {
    int sum = 0, answer = 0;
    for (int i = 0; i < stones.size(); i ++) sum += stones[i];
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] <= sum / 2) dp[i] = stones[i];
        for (int j = 0; j < i; j++) {
            if (dp[j] + stones[i] <= sum / 2) dp[i] = max(dp[i], dp[j] + stones[i]);
            answer = max(answer, dp[i]);
        }
    }

    return sum - 2 * answer;
}

int main () {
    vector<int> input = {31,26,33,21,40};
    cout << lastStoneWeightII(input) << endl;
    return 0;
}