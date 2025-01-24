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
    int pairSum(ListNode* head) {
            
          // 
          ListNode *slow=head;
          ListNode *fast=head;
          while (fast && fast->next) {
             slow=slow->next;
             fast=fast->next->next;
          }

          ListNode *mid=slow;

          ListNode *prev=NULL;
          ListNode *next;

          while (mid){
              next=mid->next;
              mid->next=prev;
              prev=mid;
              mid=next;
          }
        
          int maxi=0;
          ListNode *temp=head;
          while (prev){
               maxi=max(maxi,prev->val+temp->val);
             prev=prev->next;
             temp=temp->next;
          }

   return maxi;







            //   vector<int>data;
            //   while (head){
            //         data.push_back(head->val);
            //         head=head->next;
            //   }

            //   int maxi=INT_MIN;
            //   int n =data.size();
            //   for (int i=0;i<n;i++){
                    
            //         int sum=data[i]+data[n-i-1];
            //         maxi=max(maxi,sum);
                    
            //   }

            //   return maxi;

    }
};