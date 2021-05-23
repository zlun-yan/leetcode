//
// Created by ZlunYan on 2021/5/23.
//

// 这里的Trie的设计 因为无法解决时间复杂度的问题 所以放弃

// 要做出这个题 需要先学会字典树、前缀树
// 这个东西的概念很简单 主要是因为这个是树 所以有点复杂
// 由于元素最大值为10的9次方，也就是可以用2的30次方1073741824来比较
// 那么就建一个30层的字典二叉树即可
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int binary[31] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384,
                        32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728,
                        268435456, 536870912, 1073741824};

struct Trie {
    Trie *zero;
    Trie *one;
    Trie() : zero(nullptr), one(nullptr) {}
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
                if (temp->one == nullptr) temp->one = new Trie();
                temp = temp->one;
            } else {  // 如果为0
                if (temp->zero == nullptr) temp->zero = new Trie();
                temp = temp->zero;
            }

            digit.pop();
        }
    }

    return root;
}

// 注意 这里异或的是所有比限制数小的数
// 如果有了限制数的话 可能需要回溯
vector<int> maximizeXorWithoutRestrict(vector<int>& nums, vector<vector<int>>& queries) {
    Trie *root = buildTrieTree(nums);
    vector<int> answer;

    for (int i = 0; i < queries.size(); i++) {
        // queries[i][0]: 异或数
        // queries[i][1]: 限制数
        Trie *temp = root;
        int record = 0;

        stack<int> digit = toBinary(queries[i][0]);
        for (int j = 30; j >= 0; j--) {
            // 首先要到比restrict小的地方
            if (digit.top()) {  // 如果此时为1
                if (temp-> zero != nullptr) {
                    temp = temp->zero;
                    record += binary[j];
                } else {
                    temp = temp->one;
                }
            } else {  // 如果此时为0
                if (temp->one != nullptr) {
                    temp = temp->one;
                    record += binary[j];
                } else temp = temp->zero;
            }

            digit.pop();
        }

        answer.push_back(record);
    }

    return answer;
}

// i == 0 代表到达子叶节点
// 最先到达子叶节点的temp肯定是最大的
void dfs(Trie *root, stack<int>& digit, stack<int>& restrict, int i, int temp, int valid, int &record) {  // 回溯 这里都是传引用，记得复原哈
    // 还需要剪枝
    if (i == -1) {
        record = max(temp, record);
        return;
    }
    int digitTop = digit.top(); digit.pop();
    int restrictTop = restrict.top(); restrict.pop();

    if (valid) {
        if (digitTop) {
            if (root->zero != nullptr) dfs(root->zero, digit, restrict, i - 1, temp + binary[i], true, record);
            else dfs(root->one, digit, restrict, i - 1, temp, true, record);
        } else {
            if (root->one != nullptr) dfs(root->one, digit, restrict, i - 1, temp + binary[i], true, record);
            else dfs(root->zero, digit, restrict, i - 1, temp, true, record);
        }
    } else {
        if (digitTop) {
            if (root->zero != nullptr) dfs(root->zero, digit, restrict, i - 1, temp + binary[i], restrictTop, record);
            if (root->one != nullptr && (valid || restrictTop)) dfs(root->one, digit, restrict, i - 1, temp, false, record);
        } else {
            if (root->one != nullptr && (valid || restrictTop)) dfs(root->one, digit, restrict, i - 1, temp + binary[i], false, record);
            if (root->zero != nullptr) dfs(root->zero, digit, restrict, i - 1, temp, restrictTop, record);
        }
    }
//    if (digitTop) {
//        if (root->zero != nullptr) dfs(root->zero, digit, restrict, i - 1, temp + binary[i], valid || restrictTop, record);
//        if (root->one != nullptr && (valid || restrictTop)) dfs(root->one, digit, restrict, i - 1, temp, valid, record);
//    } else {
//        if (root->one != nullptr && (valid || restrictTop)) dfs(root->one, digit, restrict, i - 1, temp + binary[i], valid, record);
//        if (root->zero != nullptr) dfs(root->zero, digit, restrict, i - 1, temp, valid || restrictTop, record);
//    }

    digit.push(digitTop);
    restrict.push(restrictTop);
}

vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    Trie *root = buildTrieTree(nums);
    vector<int> answer;

    for (int i = 0; i < queries.size(); i++) {
        // queries[i][0]: 异或数
        // queries[i][1]: 限制数
        int record = -1;

        stack<int> digit = toBinary(queries[i][0]);
        stack<int> restrict = toBinary(queries[i][1]);
        dfs(root, digit, restrict, 30, 0, false, record);

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

    vector<int> nums = {0, 1, 2, 3, 4};
    vector<vector<int>> queries = {{3, 1}, {1, 3}, {5, 6}};
    vector<int> answerWithoutRestrict = maximizeXorWithoutRestrict(nums, queries);
    vector<int> answer = maximizeXor(nums, queries);

    printf("answerWithoutRestrict:\n");
    for (int i = 0; i < answerWithoutRestrict.size(); i++) printf("%d ", answerWithoutRestrict[i]);
    printf("\nanswer:\n");
    for (int i = 0; i < answer.size(); i++) printf("%d ", answer[i]);
    return 0;
}