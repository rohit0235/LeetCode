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
    int getDecimalValue(ListNode* head) {
            
            ListNode *temp = head;
            int c = 0;
            while (temp){
                 c++;  

                   temp =temp->next;
                     
            }

             temp = head;
                int ans =0;
             while (temp){ 
                    
                   c--;
               if (temp->val==1)  ans +=pow(2,c);
                   temp =temp->next;
             }
   return ans;

    }
};