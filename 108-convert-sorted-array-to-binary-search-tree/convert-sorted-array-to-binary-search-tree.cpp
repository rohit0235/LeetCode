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
    
    TreeNode *solve(vector<int>& nums, int start , int end, int n){
          
          if (start>end) return NULL;

          int mid = (start+end)/2;
           
          TreeNode *root = new TreeNode(nums[mid]);

         root->left = solve(nums, start,mid-1,n);
         root->right = solve(nums,mid+1,end,n);


         return root;


    }
 
    TreeNode* sortedArrayToBST(vector<int>& nums) {
           
            int n=nums.size();

            return solve(nums, 0,n-1,n);
    }
};