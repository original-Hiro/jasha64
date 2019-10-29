/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//参照上周Reverse Nodes in K Group标程的思路，独立编写 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pre = new ListNode(0); pre -> next = head;
        ListNode* prev = pre;
        for (int i = 0; i < m-1; i++) prev = prev -> next;
        ListNode* l = prev -> next;
        ListNode* r = l;
        for (int i = m; i < n; i++) r = r -> next;
        
        prev -> next = r;
        ListNode *c1 = l, *c2 = l -> next;
        l -> next = r -> next;
        while (c1 != r)
        {
            ListNode* c3 = c2 ? c2 -> next : NULL;
            c2 -> next = c1;
            c1 = c2; c2 = c3;
        }
        
        return pre -> next;
    }
};

