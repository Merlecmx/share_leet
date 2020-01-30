/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//map
struct hash_data{
    int key;
    int data;
    struct hash_data * next;
};

 struct hash_table
{
    struct hash_data ** head;
    int hash_width;
};

//初始化
int hash_init(struct hash_table * table, int width){
    if (width <= 0) return -1;
    struct hash_data** tmp = (struct hash_data**)malloc(sizeof(struct hash_data *) * width);
    table->head = tmp;
    memset(table->head, 0, width * sizeof(struct hash_data*));
    if (table->head == NULL) return -1;
    table->hash_width = width;
    return 0;
}

//释放
void hash_free(struct hash_table table){
    if (table.head != NULL) {
        for (int i = 0; i < table.hash_width; i++) {
            struct hash_data* element_head = table.head[i];
            while (element_head != NULL) {
                struct hash_data* temp = element_head;
                element_head = element_head->next;
                free(temp);
            }
        }
        free(table.head);
        table.head = NULL;
    }
    table.hash_width = 0;
}

int hash_addr(struct hash_table table, int key){
    int addr = abs(key) % table.hash_width;
    return addr;
}

//增加
int hash_insert(struct hash_table table, int key, int value){
    struct hash_data* tmp = (struct hash_date*)malloc(sizeof(struct hash_data));
    if (tmp == NULL) return -1;
    tmp->key = key;
    tmp->data = value;
    int k = hash_addr(table, key);
    tmp->next = table.head[k];
    table.head[k] = tmp;
    return 0;
}

//查找
struct hash_data* hash_find(struct hash_table table, int key){
    int k = hash_addr(table, key);
    struct hash_data* element_head = table.head[k];
    while (element_head != NULL) {
        if (element_head->key == key) return element_head;
        element_head = element_head->next;
    }
    return NULL;
}

//依赖map实现
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * 2);
    * returnSize=0;
    struct hash_table table;
    hash_init(&table, 100);
    for (int i = 0; i < numsSize; i++) {
        hash_insert(table, nums[i], i);
    }

    for(int i = 0; i < numsSize; i++)
    {
        int value = target - nums[i];
        struct hash_data* data = hash_find(table, value);
        if (data != NULL && data->data != i) {
            res[1] = i;
            res[0] = data->data;
            * returnSize = 2;
        }
    }
    hash_free(table);
    return res;
}
