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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
            
             if (root1==NULL && root2==NULL) return nullptr;

             if (root1==NULL ) return root2;
             if (root2==NULL ) return root1;

           queue<pair<TreeNode*,TreeNode*>>q;
           q.push({root1,root2});


           while (!q.empty()){
             
                   pair<TreeNode*,TreeNode*>top = q.front();
                   q.pop();
                       
                   if (!top.first || !top.second) continue;
                    top.first->val+=top.second->val;

                    if (!top.first->left){
                         top.first->left = top.second->left;
                    }
                    else{
                         q.push({top.first->left , top.second->left});
                    }
                    if (!top.first->right){
                         top.first->right = top.second->right;
                    }
                    else{
                         q.push({top.first->right , top.second->right});
                    }
 
           }

           return root1;

           
    }
};