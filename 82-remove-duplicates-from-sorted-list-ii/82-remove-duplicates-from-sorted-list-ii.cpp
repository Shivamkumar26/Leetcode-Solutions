/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* prevhead = new ListNode(-101);
        ListNode* p = prevhead;
        ListNode* c = head;
        ListNode* n = head->next;
        
        prevhead->next = head;
        while(c && n) {
            if(c->val == n->val) {
                while(n && c->val == n->val) n = n->next;
                c = n;
                p->next = c;
                if(n) n = n->next;
            }
            else if(c->val != p->val && c->val != n->val) {
                p = c;
                c = n;
                n = n->next;
            }
        }
        return prevhead->next;
    }
    
    // use pen paper think of all tc first
    // 1 1 1 2 3 4 5 5 6 6 7 8 8 8 8 8 
    
};