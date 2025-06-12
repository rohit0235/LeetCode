/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
            if (!head) return NULL;
            ListNode *slow=head;
            ListNode *fast=head->next;
            
            while (fast &&  fast->next){
            if (slow==fast){
                         return true;
                   } 
                   slow=slow->next;
                   fast=fast->next->next;

       
                   
            }
            return false;


            //  set<ListNode*>st;

            //  ListNode *temp=head;
            //  while (temp){
                   
            //        if (!st.insert(temp).second){
            //               return true;
            //        }
            //        else{
            //             st.insert(temp);
            //        }
                   
            //        temp=temp->next;                  
            //  }

            //  return false;


    }
};