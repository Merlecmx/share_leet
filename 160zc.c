struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    struct ListNode *a = headA;
    struct ListNode *b = headB;
    struct ListNode *temp = NULL;
    int len_a = 0;
    int len_b = 0;
    while(a)
    {
        if(a->next)
        {
            a = a->next;
        }else
        {
            break;
        }
        len_a++;
    }
    while(b)
    {
        if(b->next)
        {
            b = b->next;
        }else
        {
            break;
        }
        len_b++;
    }
    if(len_a > len_b)
    {
        int count;
        count = len_a - len_b;
        while(count--)
        {
            headA = headA->next;
        }
    }else
    {
        int count;
        count = len_b - len_a;
        while(count--)
        {
            headB = headB->next;
        }
    }
    while(headA && headB)
    {
        if(headA==headB)
        {
            temp = headA;
            break;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return temp;
}
