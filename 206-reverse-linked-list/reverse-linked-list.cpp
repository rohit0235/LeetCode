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
    ListNode* reverseList(ListNode* head) {
        
           ListNode* prev=NULL;
           ListNode* curr=head;
           ListNode* sec;

           while (curr!=NULL){
                  
                        
                        sec=curr->next;
                        curr->next=prev;
                        prev=curr;
                        curr=sec;
                        
           }

           return prev;














        // ListNode *prev = NULL;
        // ListNode *curr=head;
        // ListNode *ne;

        // while (curr!=NULL){
        //     ne=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=ne;
   
        // }

        // return prev;
         









    }
};