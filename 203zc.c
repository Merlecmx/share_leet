struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode *p = head;
    struct ListNode *temp = NULL;
    if(head == NULL)
        return NULL;
    while(p->next)
    {
        if(p->next->val == val)
        {
            temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        else
        {
            p = p->next;
        }
    }
    if(head->val == val)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
    return head;
}
