/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p1 = l1, *p2 = l2, *tmp, *more;
    int plus = 0, digit = 0, count = 0, sum = 0;

    // make two linked list the same length
    int len1 = 0, len2 = 0;
    while(p1!=0){
        len1++;
        p1 = p1->next;
    }
    while(p2!=0){
        len2++;
        p2 = p2->next;
    }
    tmp = len1>len2 ? l2 : l1;
    count = len1>len2 ? len1-len2 : len2-len1;
    while(tmp->next!=NULL) 
        tmp = tmp->next;
    for(int i=0;i<count;i++){
        more = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->next = more;
        tmp = tmp->next;
        tmp->val = 0;
    }
    tmp->next = NULL;
    // start calculate
    p1 = l1;
    p2 = l2;
    while(p1!=NULL){
        sum = p1->val + p2->val + plus;
        plus = sum/10;
        digit = sum%10;
        printf("%d + %d  = %d....%d  \n",p1->val,p2->val,digit,plus);
        p1->val = digit;
        p1 = p1->next;
        p2 = p2->next;
    }
    if(plus==1){
        tmp = l1;
        while(tmp->next!=NULL) 
            tmp = tmp->next;
        more = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->next = more;
        tmp = tmp->next;
        tmp->val = 1;
        tmp->next = NULL;
    }
    else ;
    return l1;
}

// @lc code=end

