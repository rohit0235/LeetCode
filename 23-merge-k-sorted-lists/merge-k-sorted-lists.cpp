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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
             
        if (lists.empty()) return nullptr;

        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<lists.size();i++){
                    
                     ListNode *temp  =lists[i];
                     while (temp){
                         pq.push(temp->val);
                         temp=temp->next;
                     }
              
        }


        ListNode *res = new ListNode(-1);

        ListNode *curr = res;

        while (!pq.empty()){
                     
                     ListNode *f = new ListNode(pq.top());
                     pq.pop();
                     curr->next = f;
                     curr=curr->next;

        }

        return res->next;




    }
};