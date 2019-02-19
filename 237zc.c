void deleteNode(struct ListNode* node)
{
    struct ListNode *temp = NULL;
    node -> val = node -> next -> val;
    temp = node -> next;
    node->next = temp->next;
    free(temp);
}
