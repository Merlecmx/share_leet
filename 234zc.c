bool isPalindrome(struct ListNode* head)
{
    struct ListNode *fast = head,*slow = head;
    while (fast != NULL)
    {
        if (fast->next == NULL)
        {
            break;
        }
        else if (fast->next->next == NULL)
        {
            fast = fast->next;
            break;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = slow->next;
    struct ListNode *prv = NULL;
    struct ListNode *now = slow;
    while (now != NULL)
    {
        struct ListNode *tmp = now->next;
        now->next = prv;
        prv = now;
        now = tmp;
    }
    slow = head;
    fast = prv;
    while (fast!=NULL && slow!=NULL)
    {
        if(slow->val != fast->val)
        {
            return false;
        }
        else
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return true;
}
