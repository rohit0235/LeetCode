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
      
     int maxsum;
     int solve(TreeNode *root){
            
            if (root==NULL) return 0;

            int  l = solve(root->left);
            int  r = solve(root->right);
            
            int nichewalalenahai = root->val+l+r;
            int sirfekhilo = root->val + max(l,r);
            int sirfmai = root->val;

           maxsum =max({maxsum,nichewalalenahai,sirfekhilo,sirfmai});


           return max(sirfekhilo,sirfmai);

     }


    int maxPathSum(TreeNode* root) {
                  maxsum=INT_MIN;

                   solve(root);

                   return maxsum;
                   
    }
};