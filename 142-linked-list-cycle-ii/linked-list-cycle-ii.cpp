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
    ListNode *detectCycle(ListNode *head) {
         
        //    if (head == nullptr || head->next == nullptr) {
        //     return nullptr;
        // }

    //    unordered_map<ListNode*,ListNode*>mp;

       ListNode *slow = head;
       ListNode *fast = head;

       while (fast && fast->next){
                 slow=slow->next;
               fast=fast->next->next;
                  if (slow == fast) {
                // Cycle detected!

                ListNode *temp = head;
                while (temp != slow) { 
                                   
                    temp = temp->next;
                    slow = slow->next;
                }
          
                return temp;
            }
      
                 
            
       }


       return nullptr;





    }
};