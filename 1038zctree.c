/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* dfs(struct TreeNode* root, int* sum){
    if (root == NULL) return sum;
    if (root) {
        dfs(root->right, sum);
        root->val += *sum;
        *sum = root->val;
        dfs(root->left, sum);
    }
    return root;
}

struct TreeNode* bstToGst(struct TreeNode* root){
    int sum = 0;
    return dfs(root, &sum);
}
