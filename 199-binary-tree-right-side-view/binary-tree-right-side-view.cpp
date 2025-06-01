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
    vector<int> rightSideView(TreeNode* root) {
            
            queue<TreeNode*>q;
            
            if (root==NULL) return {};
            vector<int>s;
            q.push(root);
            
            while(!q.empty()){
                   
                   int n =q.size();
                   vector<int>level;

                   for(int i=0;i<n;i++){

                          TreeNode* t= q.front();
                          level.push_back(t->val);
                          q.pop();
                          if (t->left) q.push(t->left);
                          if (t->right) q.push(t->right);
                   }

                    s.push_back(level.back());

            }

            return s;


    }
};