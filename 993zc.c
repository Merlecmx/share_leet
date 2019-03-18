bool isCousins(struct TreeNode* root, int x, int y) {
    if (root->val == x || root->val == y) return 0;
    int dx = 0, dy = 0;
    struct TreeNode *fatherx, *fathery;
    dx = depth(root, x, &fatherx);
    dy = depth(root, y, &fathery);
    if (dx == dy && fatherx != fathery) {
        return 1;
    } else {
        return 0;
    }
}
int depth(struct TreeNode* root, int x, struct TreeNode** father) {
    if (!root) {
        return 0;
    } else if (root->val == x) {
        return 1;
    }
    int left = depth(root->left, x, father);
    int right = depth(root->right, x, father);
    if (left == 1 || right == 1) *father = root;
    if (left) return left + 1;
    if (right) return right + 1;
    return 0;
}
