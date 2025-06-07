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
    ListNode* removeElements(ListNode* head, int val) {

             ListNode *newnode=new ListNode();
             ListNode *dummy=newnode;
             ListNode *temp=head;
             while (temp){

                   if (temp->val!=val){
                        ListNode *check=new ListNode(temp->val);
                        dummy->next=check;
                        dummy= dummy->next;
                   }
                   temp=temp->next;
             }
             dummy->next=NULL;
             return newnode->next;

    }
};