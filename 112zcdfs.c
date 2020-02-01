/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum){
    if (!root) return false;
    sum = sum - root->val;
    if (!root->left && !root->right && !sum) return true;//左右节点均为 NULL且 sum 为 0 时
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}
