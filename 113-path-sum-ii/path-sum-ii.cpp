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
vector<vector<int>>ans;
 
    void solve(TreeNode* root, int targetSum,vector<int>&temp, int sum=0){

           if(!root) return ;
            temp.push_back(root->val);
            sum+=root->val;
           if(root->left==NULL && root->right==NULL){
            //    int t = accumulate(temp.begin(),temp.end(),0);
               if(sum==targetSum) ans.push_back(temp);
 
           }
     else {
            solve(root->left, targetSum, temp, sum);
            solve(root->right, targetSum, temp, sum);
        }
             temp.pop_back();
      
    }
   
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int>temp;
        solve(root, targetSum , temp);

        return ans;

    }
};