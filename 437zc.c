void path(struct TreeNode* root, int n, int *p);
void onetree(struct TreeNode* root, int n, int *p);
int pathSum(struct TreeNode* root, int sum) {
    int *s[] = {0};
    path(root, sum, s);
    return *s;
}

void path(struct TreeNode* root, int n, int *p) {
    if (!root) return;
    if (root->val == n)(*p)++;
    onetree(root->left, n-root->val, p);
    onetree(root->right, n-root->val, p);
    path(root->left, n, p);
    path(root->right, n, p);
}

void onetree(struct TreeNode* root, int n, int *p) {
    if (!root) return;
    if (root->val == n) (*p)++;
    onetree(root->left, n-root->val, p);
    onetree(root->right, n-root->val, p);
}
