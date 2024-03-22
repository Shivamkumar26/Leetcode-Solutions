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
    ListNode* reverse(ListNode* h) {
        ListNode* c=h, *p=NULL;
        while(c) {
            ListNode* n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return 1;
        ListNode* s= head, *f=head;
        while(f && f->next) {
            s=s->next;
            f=f->next->next;
        }

        ListNode* n = reverse(s);
        while(n) {
            if(head->val != n->val) return 0;
            head = head->next;
            n=n->next;
        }
        return 1;
    }
};