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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int A = a, B = b;
        ListNode* start2 = list2;
        ListNode* end2 = list2;
        
        while(list2->next) list2 = list2->next;
        end2 = list2;
        
        ListNode* curr = new ListNode(-1);
        curr->next = list1;
        
        while(a--) curr = curr->next;
        ListNode* end1 = curr->next;
        
        curr->next = start2;
        // case if we have to remove single node
        if(A==B) {
            end2->next = end1->next;
            return list1;
        }
        while(b-- != A) end1 = end1->next;
        end2->next = end1->next;
        return list1;
        
    }
};