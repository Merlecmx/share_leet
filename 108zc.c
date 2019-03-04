struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;
    int mid;
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    mid = numsSize/2;
    root->val = nums[mid];
    root->left = sortedArrayToBST(nums, mid);
    root->right = sortedArrayToBST(&nums[mid+1], numsSize-mid-1);
    return root;
}
