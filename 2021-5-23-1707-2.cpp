//
// Created by ZlunYan on 2021/5/23.
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// 在Trie 中添加了一个minn 是这样用的：
// 如果对于一颗子树，其代表的最小值minn小于等于限制数m，就说明可以在这个树上搜索
// 如果大于，则不在这个子树上进行搜索
struct Trie {
    int minn;  // 代表以此为根的子树中所代表的数的最小值
    Trie *zero;
    Trie *one;
    Trie() : minn(INT_MAX), zero(nullptr), one(nullptr) {}
    Trie(int minn) : minn(minn), zero(nullptr), one(nullptr) {}
};

stack<int> toBinary(int num) {
    stack<int> numStack;
    for (int i = 0; i < 31; i++) {
        numStack.push(num % 2); num /= 2;
    }
    return numStack;
}

Trie* buildTrieTree(vector<int>& nums) {
    Trie *root = new Trie();

    for (int i = 0; i < nums.size(); i++) {
        Trie* temp = root;
        stack<int> digit = toBinary(nums[i]);
        while (!digit.empty()) {
            if (digit.top()) {  // 如果为1
                if (temp->one == nullptr) temp->one = new Trie(nums[i]);
                else temp->one->minn = min(nums[i], temp->one->minn);
                temp = temp->one;
            } else {  // 如果为0
                if (temp->zero == nullptr) temp->zero = new Trie(nums[i]);
                else temp->zero->minn = min(nums[i], temp->zero->minn);
                temp = temp->zero;
            }

            digit.pop();
        }
    }

    return root;
}

vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    Trie *root = buildTrieTree(nums);
    vector<int> answer;

    for (int i = 0; i < queries.size(); i++) {
        // queries[i][0]: 异或数
        // queries[i][1]: 限制数
        Trie *temp = root;
        int record = -1;

        for (int j = 30; j >= 0; j--) {
            if (queries[i][0] & 1 << j) {  // 此位为1
                if (temp->zero != nullptr && temp->zero->minn <= queries[i][1]) {
                    record = record == -1 ? queries[i][0] : record;
                    temp = temp->zero;
                }
                else if (temp->one != nullptr && temp->one->minn <= queries[i][1]) {
                    record = record == -1 ? queries[i][0] - (1 << j) : record - (1 << j);
                    temp = temp->one;
                }
                else break;
            } else {  // 此位为0
                if (temp->one != nullptr && temp->one->minn <= queries[i][1]) {
                    record = record == -1 ? queries[i][0] + (1 << j) : record + (1 << j);
                    temp = temp->one;
                }
                else if (temp->zero != nullptr && temp->zero->minn <= queries[i][1]) {
                    record = record == -1 ? queries[i][0] : record;
                    temp = temp->zero;
                }
                else break;
            }
        }

        answer.push_back(record);
    }

    return answer;
}

int main () {
    // 0, 1, 2, 3, 4
    // {3, 1}, {1, 3}, {5, 6}
    // 0
    // {0, 0}
    // 11
    // {11, 10}
    // 536870912,0,534710168,330218644,142254206
    // {214004,404207941}

    vector<int> nums = {536870912,0,534710168,330218644,142254206};
    vector<vector<int>> queries = {{214004,404207941}};
    vector<int> answer = maximizeXor(nums, queries);

    printf("answer:\n");
    for (int i = 0; i < answer.size(); i++) printf("%d ", answer[i]);
    return 0;
}