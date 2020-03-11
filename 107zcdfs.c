/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct queue {
    struct TreeNode* qarr[10000];
    int front;
    int rear;
    int size;
}Queue;

void Initilize(Queue* Q){//初始化
    Q->front = -1;
    Q->rear = -1;
    Q->size = 0;
    memset(Q->qarr, 0, sizeof(struct TreeNode*) * 10000);
}

void Push(Queue* Q, struct TreeNode* root){//入队
    Q->qarr[++Q->rear] = root;
    (Q->size)++;
}

struct TreeNode* Pop(Queue* Q){//出队
    Q->size--;
    return Q->qarr[++Q->front];
}

int TreeDepth(struct TreeNode* root){//求树深度
    if (root == NULL) return 0;
    int left = TreeDepth(root->left);
    int right = TreeDepth(root->right);
    return left > right ? left + 1 : right + 1;
}
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
       if (root == NULL || returnSize == 0 || returnColumnSizes == 0) {
        *returnSize = 0;
        *returnColumnSizes = (int *)malloc(sizeof(int) * 1);
        (*returnColumnSizes)[0] = 0;
        return NULL;
    }
    Queue q;
    Initilize(&q);
    Push(&q, root);
    int depth = TreeDepth(root);
    int** res = (int**)malloc(sizeof(int*) * depth);
    *returnColumnSizes = (int*)malloc(sizeof(int) * depth);
    int cur_depth = 0;//此时树的层次
    while (q.size != 0) {//队列不为空
        int size = q.size;
        res[cur_depth] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[cur_depth] = size;
        int cur = 0;
        while (size--) {
            struct TreeNode* temp = Pop(&q);
            res[cur_depth][cur] = temp->val;//出队的数保存，并判断子树入队
            if (temp->left) Push(&q, temp->left);
            if (temp->right) Push(&q, temp->right);
            cur++;
        }
        cur_depth++;
    }
    *returnSize = depth;
    int i = 0, j = *returnSize - 1;
    while (i < j) {
        int temp = *(*returnColumnSizes + i);
        *(*returnColumnSizes + i) = *(*returnColumnSizes + j);
        *(*returnColumnSizes + j) = temp;
        int* tmp;
        tmp = res[i];
        res[i] = res[j];
        res[j] = tmp;
        i++;
        j--;
    }
    return res;
}
