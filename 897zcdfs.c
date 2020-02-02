/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* head;
void midsort(struct TreeNode *root);
struct TreeNode* increasingBST(struct TreeNode* root){
    struct TreeNode* res = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    head = res;
    midsort(root);
    head->left = NULL;
    return res;
}

void midsort(struct TreeNode *root) {
    if (root == NULL) return;
    midsort(root->left);
    root->left = NULL;
    head->right = root->val;
    head = root;
    midsort(root->right);
}
