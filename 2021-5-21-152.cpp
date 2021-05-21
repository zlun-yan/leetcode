//
// Created by ZlunYan on 2021/5/21.
//

/*
 * record[0].first: 表示到达第i个元素的最大正数
 * record[0].second: 表示到达第i个元素的最大负数
 * maxx随时记录最大值
 */

#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {-2,0,-1};

    int answer = INT_MIN;
    vector<pair<int, int>> record;
    record.push_back(make_pair(0, 0));
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= 0) {
            record.push_back(make_pair(record[i].first ? record[i].first * nums[i] : nums[i], record[i].second ? record[i].second * nums[i] : 0));
            answer = max(answer, record[i + 1].first);
        } else {
            record.push_back(make_pair(record[i].second ? record[i].second * nums[i] : 0, record[i].first ? record[i].first * nums[i] : nums[i]));
            if (record[i + 1].first) answer = max(answer, record[i + 1].first);
            else answer = max(answer, record[i + 1].second);
        }
    }

    printf("%d\n", answer);

    return 0;
}