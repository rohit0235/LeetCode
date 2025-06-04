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


      int  solve(TreeNode* root,int current){
            if (root==NULL) return 0 ;
     current=current*10+(root->val);
            if (root->left==NULL && root->right==NULL) {
                //    path.push_back(root->val);
                // result.push_back(path); path.pop_back();
                return current;
            }
            // path.push_back(root->val);
        
            
            int l=solve(root->left,current);
            int r =solve(root->right,current);
            //  path.pop_back();
            return l+r;
             
      }
  
    //   void  solve(TreeNode* root,vector<int>&path){
    //         if (root==NULL) return ;

    //         if (root->left==NULL && root->right==NULL) {
    //                path.push_back(root->val);
    //             result.push_back(path); path.pop_back();
    //             return ;
    //         }
    //         path.push_back(root->val);
    //         solve(root->left,path);
    //         solve(root->right,path);
    //          path.pop_back();
            
             
    //   }
  
  
    int sumNumbers(TreeNode* root) {
           
        //    vector<int>path;

         return   solve(root,0);
        //      int sum=0;
        //    for(auto i:result){
        //          int num=0;
        //         for (auto j:i){
        //             num=num*10+j;
        //         }
        //         sum+=num;

        //         // cout<<endl;
        //    }
        
           

    }
};