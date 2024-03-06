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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-5001);
        dummy->next = head;
        
        ListNode* c = head, *prev = dummy;
        while(c) {
            if(prev->val <= c->val) {
                prev = c;
                c = c->next;
            }
            else {
                prev->next = c->next;
                ListNode* trav = dummy;
                while(trav->next && trav->next->val < c->val) {
                    trav = trav->next;
                }
                ListNode* n = trav->next;
                trav->next = c;
                c->next = n;
                c = prev->next; 
            }
        }
        return dummy->next;
    }
};