/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head -> next == NULL) return head;
        ListNode* pre = new ListNode(0); pre -> next = head;
        ListNode *c0 = pre, *c1 = pre -> next, *c2 = pre -> next -> next;
        while (c2 != NULL)
        {
            if (c1 -> val != c2 -> val) {fw(c0); fw(c1); fw(c2);}
            else {
                while (c2 -> next != NULL && c2 -> val == c2 -> next -> val) c2 = c2 -> next;
                while (c1 -> next != c2) {ListNode* c3 = c1 -> next; c1 -> next = c3 -> next; delete c3;}
                c0 -> next = c2 -> next; delete c1; delete c2;
                c1 = c0 -> next; c2 = c1 ? c1 -> next : NULL;
            }
        }
        return pre -> next;
    }
private:
    void fw(ListNode*& p) {p = p -> next;}
};

