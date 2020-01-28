/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int InorderTraversal(struct TreeNode* root, int** temp, int min) {
    int flag;
    if (root->left) {
        min = InorderTraversal(root->left, temp, min);
    }
    if (*temp) {
        flag = root->val - **temp;
        if (flag < min) {
            min = flag;
        }
    }
    *temp = &root->val;
    if (root->right) {
        min = InorderTraversal(root->right, temp, min);
    }
    return min;
}

int minDiffInBST(struct TreeNode* root) {
    int *temp = NULL;
    if (root == NULL) return 0;
    int num = INT_MAX;
    int min = InorderTraversal(root, &temp, num);
    return min;
}
