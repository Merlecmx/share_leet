/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool dfs(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;
    return (root1->val == root2->val) && dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
}

bool isSymmetric(struct TreeNode* root){
    return dfs(root, root);
}
