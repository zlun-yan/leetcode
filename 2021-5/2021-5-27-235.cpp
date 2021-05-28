//
// Created by ZlunYan on 2021/5/27.
//

// 题目中说这是一个二叉搜索树
// 二叉搜索树具有的性质为: 一个节点其左子树的元素均小于它, 其右子树中的元素均大于它
// 那么我们目标是找p和q的最近公共祖先, 那么当我们遍历到一个节点的时候
// 如果这个节点大于p和q, 那么说明p和q均在其左子树
// 如果这个节点小于p和q, 那么说明p和q均在其右子树
// 否则, p和q就不在一个子树里面了, 这个节点就是这个最近公共祖先
#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root->val > p->val) {
        if (root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        return root;
    } else if (root->val == p->val) return root;
    else {
        if (root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
}