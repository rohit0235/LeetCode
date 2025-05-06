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
    ListNode* rotateRight(ListNode* head, int k) {
            
           ListNode *temp=head;
           ListNode *temp2=head;
           ListNode *temp3=head;
           int n=1;
           if (head==NULL) return NULL;
           while (temp3->next!=NULL){
               n++;
               temp3=temp3->next;
           }
           int index=1;
           k=k%n;
           if (k==0) return head;
           while (temp!=NULL && index<n-k){
                index++;
                temp=temp->next;
           }    
            
           temp3->next=head;
           head=temp->next;
           temp->next=NULL;

           return head;

        

    }

};