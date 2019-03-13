struct TreeNode* convertBST(struct TreeNode* root) {
    int sum = 0;
    convert(root, &sum);
    return root;
}
void convert(struct TreeNode* root, int *sum) {
    if (root == NULL) return;
    convert(root->right, sum);
    root->val = root->val + *sum;
    *sum = root->val;
    convert(root->left, sum);
}
