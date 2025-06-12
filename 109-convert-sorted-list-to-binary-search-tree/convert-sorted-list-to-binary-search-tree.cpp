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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

   TreeNode *ltob(vector<int>&check, int start , int end ){
       
           if (start>end) return NULL;

           int mid = start+(end-start)/2;
              if((end - start)%2 != 0) mid = mid+1;
           TreeNode *root= new TreeNode(check[mid]);

           root->left = ltob(check, start,mid-1);
           root->right = ltob(check,mid+1,end);
          return root;
   }


    TreeNode* sortedListToBST(ListNode* head) {
            
            if (head==NULL) return NULL;
            ListNode *temp =head;
            vector<int>check;
            while (temp){
                 check.push_back(temp->val);
                 temp=temp->next;
            }
            int length =check.size();
            return ltob(check,0,length-1);
    }
};