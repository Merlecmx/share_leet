int findSecondMinimumValue(struct TreeNode* root) {
    if (!root) return -1;
    int min1 = root->val,min2 = root->val;
    search(root,&min1,&min2);
    if (min1 < min2) return min2;
    return -1;
}
void search(struct TreeNode* root,int* a,int* b) {
    if (!root) return;
    if (root->val < *a) {
        *b = *a;
        *a = root->val;
    }
    if (root->val > *a) {
        if(*a == *b) {
            *b = root->val;
        } else if (root->val < *b) {
            *b = root->val;
        }
    }
    search(root->left,a,b);
    search(root->right,a,b);
}
