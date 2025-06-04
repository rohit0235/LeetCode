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
      vector<vector<int>>result;

      void  solve(TreeNode* root,vector<int>&path){
            if (root==NULL) return ;

            if (root->left==NULL && root->right==NULL) {
                   path.push_back(root->val);
                result.push_back(path); path.pop_back();
                return ;
            }
            path.push_back(root->val);
            solve(root->left,path);
            solve(root->right,path);
             path.pop_back();
            
             
      }
  

  
    int sumNumbers(TreeNode* root) {
           
           vector<int>path;

           solve(root,path);
             int sum=0;
           for(auto i:result){
                 int num=0;
                for (auto j:i){
                    num=num*10+j;
                }
                sum+=num;

                // cout<<endl;
           }
        
           return sum;

    }
};