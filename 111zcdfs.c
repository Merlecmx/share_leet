/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int min(int a, int b) {
    return a > b ? b : a;
}

int minDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    int min_depth = INT_MAX;
    if (root->left != NULL) min_depth = min(minDepth(root->left), min_depth);
    if (root->right != NULL) min_depth = min(minDepth(root->right), min_depth);
    return min_depth + 1;
}
