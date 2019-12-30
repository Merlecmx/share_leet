bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int a[100];
    int b[100];
    int n = 0, m = 0;
    int i = 0;
    search(root1, a, &n);
    search(root2, b, &m);
    if (n != m) return false;
    while (i < n) {
        if (a[i] != b[i]) return false;
        i++;
    }
    return true;
}

void search(struct TreeNode* root, int* leaves, int* num) {
    if (!root) return;
    if (!root->left && !root->right) {
        leaves[(*num)++] = root->val;
    }
    search(root->left, leaves, num);
    search(root->right, leaves, num);
}
