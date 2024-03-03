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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* s = NULL;
        ListNode* f = head;
        
        ListNode* h = head;
        while(n--) {
            f = f->next;
        }
        s = head;
        if(f==NULL) return head->next;
        while(f->next) {
            f = f->next;
            s = s->next;
        }
        if(s->next) s->next = s->next->next;
        // if(s == NULL) return h->next;
        return h;
    }
};