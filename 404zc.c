int sumOfLeftLeaves(struct TreeNode* root) {
    return findsum(root, 0);
}
int findsum(struct TreeNode* root, int sum) {
    if (root != NULL) {
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
            sum += root->left->val;
        }
        sum = findsum(root->left, sum);
        sum = findsum(root->right, sum);
    }
    return sum;
}
