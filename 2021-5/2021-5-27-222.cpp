//
// Created by ZlunYan on 2021/5/27.
//

#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 遍历树中所有节点当然可以
// 但是没有用上这个完全二叉树的条件
/*
 * n0、n1、n2分别代表节点的度数为0、1、2。n为总结点数
 * n0 = n2+1;
 * n=n0+n1+n2
 * 分支总线=n-1=n1+2n2
 */
// 一个完全二叉树的两个子树,至少有一个是满二叉树
// 满二叉树的节点个数: 1 + 2 + 4 + 8 + ...
int countNodes(TreeNode* root) {
    TreeNode *left = root, *right = root;
    int leftHeight = 0, rightHeight = 0;
    while (left != nullptr) {leftHeight ++; left = left->left;}
    while (right != nullptr) {rightHeight ++; right = right->right;}
    if (leftHeight == rightHeight) return (1 << leftHeight) - 1;
    else return 1 + countNodes(root->left) + countNodes(root->right);
}