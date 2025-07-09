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
    bool isPalindrome(ListNode* head) {
        
             ListNode *slow =head;
             ListNode *fast =head;

             while (fast && fast->next){
                 slow=slow->next;
                 fast=fast->next->next;

             }
            
               ListNode     *prev =NULL;
             ListNode *curr = slow;

              ListNode * next ;

              while (curr ){
                 
                next = curr->next;
                curr->next =prev;
                prev=curr;
                curr=next;
                  
              }
           

            //   ListNode *temp =head;
            // while (slow){
                  
            //       if (slow->val!=temp->val ) return false;
            //       slow=slow->next;
            //       temp=temp->next;
            // }
         ListNode *temp3=head;
         while (prev!=NULL){
            
                if (temp3->val !=prev->val) {
                     return false;
                }

                prev=prev->next;
                temp3=temp3->next;
         }
         
         return true;

            


    }
};