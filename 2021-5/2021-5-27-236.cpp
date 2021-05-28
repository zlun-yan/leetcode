//
// Created by ZlunYan on 2021/5/27.
//

// 这个可就没有二叉搜索树的性质可以用咯
#include <cstdio>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* root, TreeNode* target, vector<TreeNode*> &pre, bool &flag) {
    if (flag || root == nullptr) return;
    if (root->val == target->val) {
        flag = true;
        return;
    }
    pre.push_back(root);
    dfs(root->left, target, pre, flag);
    if (flag) return;
    dfs(root->right, target, pre, flag);
    if (flag) return;
    pre.pop_back();
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> pPre, qPre;
    bool flag = false;
    dfs(root, p, pPre, flag); pPre.push_back(p);
    flag = false;
    dfs(root, q, qPre, flag); qPre.push_back(q);
    int i;
    for (i = 0; i < min(pPre.size(), qPre.size()); i++) {
        if (pPre[i]->val != qPre[i]->val) break;
    }
    return pPre[i - 1];
}

int main () {
    TreeNode *node[10];
    for (int i = 0; i < 10; i++) node[i] = new TreeNode(i);
//    node[3]->left = node[5];
//    node[3]->right = node[1];
//    node[5]->left = node[6];
//    node[5]->right = node[2];
//    node[2]->left = node[7];
//    node[2]->right = node[4];
//    node[1]->left = node[0];
//    node[1]->right = node[8];
    node[1]->left = node[2];

    TreeNode *answer = lowestCommonAncestor(node[1], node[2], node[1]);
    printf("%d\n", answer->val);
    return 0;
}