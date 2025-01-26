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

    void preorder(TreeNode *root,int level,vector<int>&ans){
         
        if (root==NULL) return ;
        
        if (level>ans.size()){
            ans.push_back(root->val);
        }
       preorder(root->right,level+1,ans);
       preorder(root->left,level+1,ans);

    }
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        preorder(root,1,ans);

        // using bfs
        // if (root==NULL) return {};
        // queue<TreeNode*>q;
        // q.push(root);
        // while (!q.empty()){
                
        //       int n =q.size();
        //       int right=0;
        //       while (n--){
        //              TreeNode*  temp=q.front();
        //            right=q.front()->val;
        //            q.pop();
        //           if (temp->left) q.push(temp->left);
        //           if (temp->right) q.push(temp->right);

        //       }
        //       ans.push_back(right);
                            
        // }

        return ans;

    }
};