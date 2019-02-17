struct ListNode* reverseList(struct ListNode* head)
{
    if(!head)
        return NULL;
   struct ListNode *p = head;
   struct ListNode *q = head;
    while(head->next)
    {
        p = head->next;
        head->next = p->next;
        p->next = q;
        q = p;
    }
    return q;
}
