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
    vector<vector<int>> levelOrder(TreeNode* root) {
            if (root==NULL) return {};     
            vector<vector<int>>res;
            queue<TreeNode*>q;
            q.push(root);
            
            while (!q.empty()){

                    int n =q.size();
                    vector<int>s;
                    for(int i=0;i<n;i++){
                     TreeNode* tops= q.front();
                    s.push_back(tops->val);  
                        q.pop();
                        if (tops->left) q.push(tops->left);
                     if (tops->right) q.push(tops->right);
                       
                    }

                    res.push_back(s);



            }
           
           return res;

    }
};