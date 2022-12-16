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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode* l3 = new ListNode(-1);
        ListNode* temp = l3;
        int carry = 0;
        while(l1 || l2) {
            int num = carry;
            if(l1) {
                num += l1->val;
                l1 = l1->next;
            } if(l2) {
                num += l2->val;
                l2 = l2->next;
            }
            carry = num / 10;
            num %= 10;
            ListNode* nod = new ListNode(num);
            temp->next = nod;
            temp = temp->next;
        }
        if(carry != 0) {
            ListNode* nod = new ListNode(carry);
            temp->next = nod;
        }
        return l3->next;
    }
};

/**

543
564
------
018

**/