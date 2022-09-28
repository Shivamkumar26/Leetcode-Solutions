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
        ListNode* beforeHead = new ListNode();
        beforeHead->next = head;
        
        ListNode* temp = beforeHead;
        ListNode* slow = beforeHead;
        ListNode* fast = beforeHead;
        int i=0;
        
        while(i++<n) fast = fast->next;
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        return beforeHead->next;
    }
};