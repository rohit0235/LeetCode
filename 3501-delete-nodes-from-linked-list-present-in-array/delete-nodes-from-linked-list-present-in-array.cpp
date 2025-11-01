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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
           ListNode* ans = new ListNode(-1);
           ListNode *check =ans;
           unordered_map<int,int>mp;
           for(auto num:nums)mp[num]++;

           ListNode *temp = head;
           while (temp){
              if (!mp.count(temp->val)){
                    check->next = new ListNode(temp->val);
                    check = check ->next;
              }
              temp = temp->next;
           }
           check->next = NULL;
           return ans ->next;
    }
};