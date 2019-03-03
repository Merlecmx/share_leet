int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int l, r;
    l = maxDepth(root->left);
    r = maxDepth(root->right);
    return l > r ? l+1 : r+1;
}
