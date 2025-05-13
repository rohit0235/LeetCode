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
    ListNode* partition(ListNode* head, int x) {


        ListNode *result=new ListNode(-1);
        
        ListNode *temp=head;   
        ListNode *curr=result;   

        while (temp){
                          
               if (temp->val<x){
                    
                    curr->next =new ListNode (temp->val);
                    curr=curr->next;
               }
               
                temp=temp->next;

        }
        temp=head;
        while (temp){
                          
               if (temp->val>=x){
                    
                    curr->next =new ListNode (temp->val);
                    curr=curr->next;
               }
               
                temp=temp->next;

        }
        

        curr->next =NULL;
        return result->next;





    }
};