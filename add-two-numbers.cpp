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
        ListNode* result = new ListNode(l1->val + l2->val);
        int carry = result->val / 10;;
        result->val = result->val % 10;
        l1 = l1->next;
        l2 = l2->next;
        
        ListNode* temp = result;
        while(l1 != NULL && l2 != NULL)
        {
            temp->next = new ListNode(l1->val + l2->val + carry);
            temp = temp->next;
            carry = temp->val / 10;
            temp->val = temp->val % 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL)
        {
            temp->next = new ListNode(l1->val + carry);
            temp = temp->next;
            carry = temp->val / 10;
            temp->val = temp->val % 10;
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            temp->next = new ListNode(l2->val + carry);
            temp = temp->next;
            carry = temp->val / 10;
            temp->val = temp->val % 10;
            l2 = l2->next;
        }
        if(carry != 0)
        {
            temp->next = new ListNode(carry);
        }
        return result;
    }
};
