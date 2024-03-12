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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        ListNode* dummy = new ListNode(0);

        mp[0] = dummy;
        dummy->next = head;
        
        ListNode* temp = head;
        int sum = 0;

        while(temp) {
            sum += temp->val;
            if(mp.count(sum)) {
                ListNode* t2 = mp[sum]->next;
                int s2 = sum;
                while(t2 != temp) {
                    s2 += t2->val;
                    mp.erase(s2);
                    t2 = t2->next;
                }
               mp[sum]->next = temp->next;
            }
            else mp[sum] = temp;
            temp = temp->next;
        }
        return dummy->next;
    }
};
