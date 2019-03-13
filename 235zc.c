struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == p || root == q) return root;
    if (root->val > p->val && root->val < q->val) return root;
    if (root->val < p->val && root->val > q->val) return root;
    if (root->val > p->val) {
        return lowestCommonAncestor(root->left,p,q);
    } else {
        return lowestCommonAncestor(root->right, p,q);
    }
}
