/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int min;
void InorderTraversal(struct TreeNode* root, int** temp) {
    int flag;
    if (root->left != NULL) {
        InorderTraversal(root->left, temp);
    }
    if (*temp != NULL) {
        flag = root->val - **temp;
        if (flag < min) {
            min = flag;
        }
    }
    *temp = &root->val;
    if (root->right != NULL) {
        InorderTraversal(root->right, temp);
    }
}
int minDiffInBST(struct TreeNode* root){
    min = 1000;
    int *temp = NULL;
    if (root == NULL) return 0;
    InorderTraversal(root, &temp);
    return min;
}
