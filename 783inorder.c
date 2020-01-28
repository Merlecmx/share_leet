/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int InOrderTraversal(struct TreeNode* root, int* arr, int n) {
    if (root->left) {
        n = InOrderTraversal(root->left, arr, n);
    }
    arr[n++] = root->val;
    if (root->right) {
        n = InOrderTraversal(root->right, arr, n);
    }
    return n;
}

int minDiffInBST(struct TreeNode* root) {
    int arr[101];
    int index = InOrderTraversal(root, arr, 0);
    int min = INT_MAX;
    for (int i = 1; i < index; i++) {
        if (arr[i] - arr[i-1] < min) min = arr[i] - arr[i-1];
    }
    return min;
}
