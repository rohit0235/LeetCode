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
        if (head==NULL) return true;

        ListNode *slow=head;
        ListNode *fast=head;

        while (fast!=NULL &&  fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        
    

         ListNode *prev=NULL;
         ListNode *curr=slow;
          ListNode *next;

         while (curr!=NULL){
                
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
         }
         
       ListNode *temp3=head;
         while (prev!=NULL){
                // cout<<temp3->val<<" "<<prev->val;
                if (temp3->val !=prev->val) {
                     return false;
                }

                prev=prev->next;
                temp3=temp3->next;
         }
         
         return true;



        // vector<int>s;
        // ListNode *temp=head;
        // while (temp){
        //      s.push_back(temp->val);
        //      temp=temp->next;
        // }
        // // for(int i:s)cout<<i<<" ";
        // int i=0;
        // int j=s.size()-1;
        // while (i<j){
              
        //       if (s[i]!=s[j]) return false; 
        //       i++;
        //       j--;
        // }

        // return true;
        
    }
};