/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add = 0;
        ListNode ans = ListNode(0), *p;
        p = &ans;
        
        while(l1 != NULL || l2 != NULL || add > 0) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + add;
            add = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        
        return ans.next;
    }
};