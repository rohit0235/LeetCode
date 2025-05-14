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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
              
              ListNode *dummy=new ListNode(-1);
              ListNode *curr=dummy;

              ListNode *temp1=l1;
              ListNode *temp2=l2;
              int carry=0;

              while (temp2 && temp1){

                  int f=temp1->val;
                  int s=temp2->val;
                  
                  int addition =f+s+carry;
                if (carry>0) carry--;
                  if (addition>9){
                    carry++;
                  }

                  int check=addition%10;
                  curr->next = new ListNode (check);
                  curr=curr->next;
                  temp1=temp1->next;
                  temp2=temp2->next;
 
              }

              while (temp2){

                  int s=temp2->val;
                  
                  int addition =s+carry;
                 if (carry>0) carry--;
                  if (addition>9){
                    carry++;
                  }

                  int check=addition%10;
                  curr->next = new ListNode (check);
                  curr=curr->next;
            
                  temp2=temp2->next;
 
              }

              while (temp1){

                  int f=temp1->val;
                  
                  int addition =f+carry;
                 if (carry>0) carry--;
                  if (addition>9){
                    carry++;
                  }

                  int check=addition%10;
                  curr->next = new ListNode (check);
                  curr=curr->next;
            
                  temp1=temp1->next;
 
              }
            
              if (carry>0){
                    curr->next =new ListNode(1);
                    curr=curr->next;

              }

              curr->next=NULL;

              return dummy->next;
    }
};