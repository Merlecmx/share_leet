/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(struct TreeNode* root, char** bin_tree_paths, int* path, int* returnSize, int depth) {
    int i = 0;
    path[depth++] = root->val;
    if (root->left == NULL && root->right == NULL) {
        bin_tree_paths[*returnSize] = (char*)malloc(sizeof(char) * 100);
        bin_tree_paths[*returnSize][0] = 0;
        for (i = 0; i < depth - 1; i++) {
            sprintf(bin_tree_paths[*returnSize], "%s%d->", bin_tree_paths[*returnSize], path[i]);
        }
        sprintf(bin_tree_paths[*returnSize], "%s%d", bin_tree_paths[*returnSize], path[i]);
        (*returnSize)++;
        return;
    }
    if (root->left != NULL) {
        dfs(root->left, bin_tree_paths, path, returnSize, depth);
    }
    if (root->right != NULL) {
        dfs(root->right, bin_tree_paths,path, returnSize, depth);
    }
    return;
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    int path[100] = {0}, depth = 0;
    char** bin_tree_paths = (char**)malloc(sizeof(char*) * 100);
    if (root == NULL) return root;
    *returnSize = 0;
    dfs(root, bin_tree_paths, path, returnSize, depth);
    return bin_tree_paths;
}
