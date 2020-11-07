/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//WE NEED MORE STORAGE LESS DEPENDENT ALGORITHM

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    // initialization
    struct ListNode *p = l1, *q= l2, *head = l1, *h;
    int num1 = 0, num2 = 0;

    if(!p&&!q) return NULL;
    while(p || q){
        // the first step
        if(p==l1&&q==l2){
            head = (struct ListNode*)malloc(sizeof(struct ListNode));
            h = head;
        }
        else{
            h->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            h = h->next;
        }
        //comparision in the loop
        num1 = p == NULL ? 101 : p->val;
        num2 = q == NULL ? 101 : q->val;
        if(num1<num2){
            h->val = num1;
            p = p->next;
        }
        else{
            h->val = num2;
            q = q->next;
        }
    }
    h->next = NULL;
    return head;
}
// @lc code=end

