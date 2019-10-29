//¿Õ¼ä¸´ÔÓ¶ÈO(1) 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, const int k) {
        int n = 0;
        for (ListNode* cur = head; cur != NULL; cur = cur -> next) n++;
        ListNode* pre = new ListNode(0); pre -> next = head; //ÉÚ±ø 
        
        ListNode* prev = pre;
        while (n >= k)
        {
        	ListNode* l = prev -> next;
        	ListNode* r = prev;
        	for (int i = 0; i < k; i++) r = r -> next;
        	
        	prev -> next = r;
			ListNode *c1 = l, *c2 = l -> next;
			l -> next = r -> next;
        	while (c1 != r)
			{
				ListNode* c3 = c2 ? c2 -> next : NULL;
				c2 -> next = c1;
				c1 = c2; c2 = c3; 
			}
			
            n -= k; prev = l;
        }
        
        return pre -> next;
    }
};

