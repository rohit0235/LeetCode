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
    ListNode* deleteDuplicates(ListNode* head) {
        
             ListNode *newnode=new ListNode();
             ListNode *dummy=newnode;
             ListNode *temp=head;
             int prev =INT_MIN;
             while (temp){

                   if (temp->val!=prev){
                        ListNode *check=new ListNode(temp->val);
                        dummy->next=check;
                        dummy= dummy->next;
                       
                   } prev=temp->val;
                   temp=temp->next;
             }
             dummy->next=NULL;
             return newnode->next;
    }
};