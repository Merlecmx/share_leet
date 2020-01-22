/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int m, int n) {
    return m > n ? m : n;
}

int countFloor(struct TreeNode* root) {//计算子树高度
    if (root == NULL) return 0;
    return 1 + max(countFloor(root->left), countFloor(root->right));
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) return true;
    if (abs(countFloor(root->left) - countFloor(root->right)) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
