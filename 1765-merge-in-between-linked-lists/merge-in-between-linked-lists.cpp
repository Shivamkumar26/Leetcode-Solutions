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
        ListNode* l2head = list2;
        ListNode* l2tail = list2;
        while(l2tail->next) {
            l2tail = l2tail->next;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = list1;
        ListNode* lt = dummy;
        int l=-1;
        while(l+1 != a) {
            lt = lt->next;
            l++;
        }
        cout << lt->val << " ";
        ListNode* rt = lt;
        while(l <= b) {
            rt = rt->next;
            l++;
        }
        cout << rt->val << " \n";
        lt->next = l2head;
        l2tail->next = rt;
        return dummy->next;
    }
};