struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *l,*pt,*p,*q;
    p = l1;
    q = l2;
    l = (struct ListNode*)malloc(sizeof(struct ListNode));
    pt = l;
    l->next = NULL;
    while(p && q)
    {
        if(p->val <= q->val)
        {
            pt->next = p;
            pt = p;
            p = p->next;
        }
        else{
            pt->next = q;
            pt = q;
            q = q->next;
        }
    }
    pt->next = p ? p : q;
    return l->next;
}
