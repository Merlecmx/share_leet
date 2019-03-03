struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) return NULL;
    struct TreeNode *temp;
    temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}
