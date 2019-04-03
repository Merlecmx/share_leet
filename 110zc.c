bool isBalanced(struct TreeNode* root) {
    if (root == NULL) return true;
    if (abs(countFloor(root->left) - countFloor(root->right)) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

int countFloor(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + max(countFloor(root->left), countFloor(root->right));
}

int max(int m, int n) {
    if (m > n) return m;
    return n;
}
