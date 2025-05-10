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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
               
          int non=0;
         ListNode *temp=head;
         while (temp){
             non++;
             temp=temp->next;
         }

        //  cout<<non<<endl;
          if (non==1) return NULL;
         if (n==1){
             
                 ListNode *check=head;
               while (head->next->next!=NULL){
                       head=head->next;

               }
               head->next=NULL;
               return check;
         }
         else if (n==non){

               ListNode *check2=head->next;
               head=check2;
               return head;


         }

         else {
                
               int count=1;
               ListNode *temp=head;
               while (count<non-n){
                    count++;
                    head=head->next;

               }


               head->next=head->next->next;
               return temp;



         }


           


    }
};