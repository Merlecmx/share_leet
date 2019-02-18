struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode *p = head;
    struct ListNode *temp = NULL;
    while(p&&p->next)
    {
        if(p->val == p->next->val)
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
    return head;
}
