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
    ListNode* oddEvenList(ListNode* head) {
       
        if(!head || !head->next) return head;
        
        ListNode* evenhead = head->next, * oddhead = head;
        ListNode* evenp = head->next, * oddp = head;

        while(evenp && evenp->next) {

            oddp->next = oddp->next->next;
            evenp->next = evenp->next->next;
            
            evenp = evenp->next;

            oddp = oddp->next;
        }

        oddp->next = evenhead;
        return oddhead;
    }
};