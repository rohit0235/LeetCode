/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;

        if (root == p || root == q)
            return root;
        // dfs traversal
        TreeNode* checkleft = lowestCommonAncestor(root->left, p, q);
        TreeNode* checkright = lowestCommonAncestor(root->right, p, q);
        if (checkleft != NULL && checkright != NULL)
            return root;
        if (checkleft != NULL)
            return checkleft;
        return checkright;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        if (root == NULL)
            return root;

        TreeNode* leftest = root;
        TreeNode* rightest = NULL;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int n = q.size();
            vector<TreeNode*> temp;

            for (int i = 0; i < n; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (front->left) {
                    temp.push_back(front->left);
                    q.push(front->left);
                }

                if (front->right) {
                    temp.push_back(front->right);
                    q.push(front->right);
                }
            }
            // cout<<temp.size();
            if(temp.size()==0) continue;
            if (temp.size() ==1) {
                leftest = temp[0];
                rightest=NULL;
            } else {
                leftest = temp[0];
                rightest = temp.back();
            }
        }
         
        //  cout<<leftest->val;
        if(rightest==NULL) cout<<"find the ";
        //  return NULL;
        return lowestCommonAncestor(root,leftest, rightest);

    }
};