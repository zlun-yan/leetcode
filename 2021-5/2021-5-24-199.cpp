//
// Created by ZlunYan on 2021/5/24.
//

#include <cstdio>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(vector<int> &answer, TreeNode *root, int height) {
    if (root == nullptr) return;
    if (answer.size() == height) answer.push_back(root->val);
    dfs(answer, root->right, height + 1);
    dfs(answer, root->left, height + 1);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> answer;
    dfs(answer, root, 0);
    return answer;
}