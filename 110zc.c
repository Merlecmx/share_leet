bool isBalanced(struct TreeNode* root) {
    if (root == NULL) return true;
    if (abs(countFloor(root->left) - countFloor(root->right)) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
int countFloor(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + fmax(countFloor(root->left), countFloor(root->right));
}
