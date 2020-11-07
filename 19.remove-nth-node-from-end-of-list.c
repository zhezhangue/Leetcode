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

/*
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct listNode* p = NULL;
    struct ListNode* q = NULL;
    int count = n;
    // q takes n steps before p starts to move
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
        // p keeps walking until q reaches the end of the linked list(q == NULL)
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

}*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* p = head;
    struct ListNode* q = head;
    while(n > 0) {
        p = p->next;
        n--;
    }
    while(p && p->next) {
        p = p->next;
        q = q->next;
    }
    if(q != head || (q == head && p)) // 这时是删除q后面的
        q->next = q->next->next;
    if(q == head && !p) // 这时是删除q自己
        head = q->next;
    return head;
}

//作者：lexiaoyuan
//链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/19-shan-chu-lian-biao-de-dao-shu-di-nge-jie-dia-93/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// @lc code=end

