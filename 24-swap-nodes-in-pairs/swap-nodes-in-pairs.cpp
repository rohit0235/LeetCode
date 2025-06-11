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
    ListNode* swapPairs(ListNode* head) {

        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        // ListNode *prev=NULL;
        while (slow && slow->next!=NULL) {
                   
                   swap(slow->val,fast->val);
                if (slow->next)   slow=slow->next->next;
                 if (fast->next)  fast=fast->next->next;
                 
                    
        }



        return head;
    }
};