class Solution {
public:
    ListNode* rotateRight(ListNode* Head, int k)
	{
        if (Head == NULL) return Head; //!
        
		int n = 1;
		ListNode* Tail = Head;
		while (Tail -> next != NULL) {Tail = Tail -> next; n++;}
		
		k = n - k%n;
		Tail -> next = Head;
		ListNode* Newtail = Head;
		for (int i = 1; i < k; i++) Newtail = Newtail -> next;
		ListNode* Newhead = Newtail -> next;
		Newtail -> next = NULL;
		
		return Newhead;
    }
private:
    ListNode* Newnode(int x) {return new ListNode(x);}
};

