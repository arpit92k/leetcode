/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    map<ListNode*, bool> visited;
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* n1 = head;
        while(n1)
        {
            if(visited.find(n1) != visited.end())
            {
                break;
            }
            visited[n1]= true;
            n1 = n1->next;
        }
        return n1;
    }
};
