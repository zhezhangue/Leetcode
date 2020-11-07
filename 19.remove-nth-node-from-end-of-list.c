/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// DID NOT FINISHED


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct listNode* p = NULL;
    struct ListNode* q = NULL;
    int count = n;
    while(q!=NULL && count!=0){
        q = q->next;
        count --;
    }
    if(q == NULL || n == 0)
    {
        p = head;
        head = head->next;
        free(p);
        return head;
    }
    if(q == NULL || n != 0)
    {
        return NULL;
    }
    else
    {
        q = q->next;
        while(q!=NULL)
        {
            p = p->next;
            q = q->next;
        }
        q = p->next;
        p = p->next->next;
        free(q);
        return head;
    }

}
// @lc code=end

