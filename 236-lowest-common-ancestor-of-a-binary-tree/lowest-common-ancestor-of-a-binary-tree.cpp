/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if (root==NULL) return NULL;

         if (root==p || root==q) return root;
        // dfs traversal
         TreeNode *checkleft=lowestCommonAncestor(root->left,p,q);
         TreeNode *checkright=lowestCommonAncestor(root->right,p,q);
         
         // check whether we have right and left value if yes 

         if (checkleft!=NULL && checkright!=NULL)  return root;

         if (checkleft!=NULL) return checkleft;
        
           return checkright;
    }
};