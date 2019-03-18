int sum = 0;
int findTilt(struct TreeNode* root) {
    sum = 0;
    title(root);
    return sum;
}
int title(struct TreeNode* root) {
    if (!root) return 0;
    int left = title(root->left);
    int right = title(root->right);
    sum += abs(left - right);
    return left + right + root->val;
}
