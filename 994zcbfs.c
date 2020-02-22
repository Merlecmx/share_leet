typedef struct queue{
    int arr[1000];
    int front;
    int rear;
    int size;
}Queue;

void Initilize(Queue* q){
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    memset(q->arr, 0, sizeof(int) * 1000);
}

void Push(Queue* q, int n){
    q->size++;
    q->arr[++q->rear] = n;
}

int Pop(Queue* q){
    q->size--;
    return q->arr[++q->front];
}

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    if(grid == NULL || gridSize == 0 || gridColSize == NULL) {
        return -1;
    }
    int dr[4] = {-1, 0, 1, 0};//用来换行换列
    int dc[4] = {0, -1, 0, 1};
//将所有的坏橘子放入队列
    Queue q;
    Initilize(&q);
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            if (grid[i][j] == 2) {
                int code = i * (*gridColSize) + j;
                Push(&q, code);
            }
        }
    }
//出队一个坏橘子，找到坏橘子周围的好橘子入队
    int time = 0;
    while (q.size != 0) {
        int flag = false;
        int size = q.size;
        for (int i = 0; i < size; ++i) {
            int code = Pop(&q);
            int r = code / (*gridColSize), c = code % (*gridColSize);
            for (int j = 0; j < 4; ++j) {//循环找到坏橘子周围橘子的下标
                int nr = r + dr[j], nc = c + dc[j];
                if (0 <= nr && nr < gridSize && 0 <= nc && nc < *gridColSize && grid[nr][nc] == 1) {//有好橘子，变坏入队
                    grid[nr][nc] = 2;
                    int ncode = nr * (*gridColSize) + nc;
                    Push(&q, ncode);
                    flag = true;
                }
            }
        }
        if (flag) {
            time++;
        }
    }
//查看有没有无法变坏的橘子
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < (*gridColSize); ++j) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return time;
}
