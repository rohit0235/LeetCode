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
    int widthOfBinaryTree(TreeNode* root) {
             if (root == nullptr) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        unsigned long long max_width = 0;

        while (!q.empty()) {
            unsigned long long level_size = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = q.back().second;
            max_width = max(max_width, right - left + 1);

            for (unsigned long long i = 0; i < level_size; ++i) {
                auto node_pair = q.front();
                q.pop();
                TreeNode* node = node_pair.first;
                unsigned long long index = node_pair.second;

                if (node->left) {
                    q.push({node->left, 2 * index + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * index + 2});
                }
            }
        }

        return max_width;
    }
};

// 0 -1 -3 
// 0  1  3 
//  0 -1 1
//  -1  -3  
// 