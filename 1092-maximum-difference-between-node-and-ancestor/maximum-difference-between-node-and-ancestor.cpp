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
     
    int ans = 0;

    void solve(TreeNode *root, int maxi , int mini){
          if(!root) return ;

        if(maxi !=INT_MIN)  ans = max(ans ,abs(maxi - root->val) );
           if(mini !=INT_MAX)  ans = max(ans ,abs(mini - root->val) );

        //    cout<<maxi<<" "<<mini<<endl;
        //   cout<<ans<<endl;
          solve(root->left, max(maxi , root->val ), min(mini, root->val));
          solve(root->right, max(maxi , root->val ), min(mini, root->val));
    }
 
    int maxAncestorDiff(TreeNode* root) {
        solve(root,INT_MIN,INT_MAX);
        return ans;
    }
};