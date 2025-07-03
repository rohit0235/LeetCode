/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

 void solve(Node *root, vector<int>&temp){
      
           if (root==NULL) return ;

           for(Node *x:root->children){
                     solve(x,temp);
           }

           temp.push_back(root->val);
        //    solve(root->left, temp);
        //    solve(root->right, temp);
        //    temp.push_back(root->data);
      
 }
    vector<int> postorder(Node* root) {
        
                        vector<int>temp;

                         solve(root,temp);
                         return temp;
            
    }
};