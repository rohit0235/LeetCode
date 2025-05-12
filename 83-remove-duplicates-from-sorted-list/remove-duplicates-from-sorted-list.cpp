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
    ListNode* deleteDuplicates(ListNode* head) {
            
             
             ListNode *temp=head;

             while (temp!=NULL){
                   
                    while (temp->next !=NULL && temp->val == temp->next->val){
                            
                          if (temp->next->next!=NULL) temp->next=temp->next->next;
                          else temp->next=NULL;

                    }


                   temp=temp->next;

             }

             return head;

    }
};