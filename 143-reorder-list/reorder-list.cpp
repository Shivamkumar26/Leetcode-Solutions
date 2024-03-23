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

    /*
    
    1 2 3 5 4
    1 5 2 4 3
    
    */
    ListNode* reverse(ListNode* h) {
        ListNode*p = NULL, *c = h;
        while(c) {
            ListNode* n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* s=head, *f=head;
        while(f && f->next) {
            s=s->next;
            f=f->next->next;
        }

        ListNode* l2 = reverse(s);

        ListNode* p1 = head, *p2 = l2;
        while(p1 && p2) {
            ListNode* np1 = p1->next;
            ListNode* np2 = p2->next;
            p1->next = p2;
            p2->next = np1;
            p1 = np1;
            p2 = np2;
        }
        if(p1) p2 = p1, p1->next = NULL;
        if(p2) p1= p2, p2->next = NULL;
    }
};