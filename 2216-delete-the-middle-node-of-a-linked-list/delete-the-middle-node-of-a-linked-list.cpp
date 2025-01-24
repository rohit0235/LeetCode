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
    ListNode* deleteMiddle(ListNode* head) {
          if (head==NULL || !head->next) return NULL;
        
        ListNode* slow=head;
      ListNode* fast=head;
         
        while (fast && fast->next){
             slow=slow->next;
             fast=fast->next->next ;

        }
      
        ListNode *temp=head;
        while (temp){
            if (temp->next==slow){
                  temp->next=slow->next;
            }
            
                temp=temp->next;
      
        }

        return head;


    }
};