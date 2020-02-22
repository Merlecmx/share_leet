/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct queue {
    struct TreeNode* arr[10000];
    int front;
    int rear;
    int size;
}Queue;

void Initilize(Queue* Q){//初始化
    Q->front = -1;
    Q->rear = -1;
    Q->size = 0;
    memset(Q->arr, 0, sizeof(struct TreeNode*) * 10000);
}

void Push(Queue* Q, struct TreeNode* root){//入队
    Q->arr[++Q->rear] = root;
    (Q->size)++;
}

struct TreeNode* Pop(Queue* Q){//出队
    Q->size--;
    return Q->arr[++Q->front];
}

int findBottomLeftValue(struct TreeNode* root){
    Queue q;
    Initilize(&q);
    Push(&q, root);
    int res;
    while (q.size != 0) {
        int size = q.size;
        for (int i = 0; i < size; ++i) {
            struct TreeNode* node = Pop(&q);
            if (i == 0) res = node->val;//每层的第一个值
            if (node->left) Push(&q, node->left);
            if (node->right) Push(&q, node->right);
        }
    }
    return res;
}
