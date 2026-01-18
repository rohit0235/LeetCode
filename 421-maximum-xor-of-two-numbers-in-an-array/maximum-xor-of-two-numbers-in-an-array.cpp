class Solution {
public:
    struct trieNode {
        trieNode* left;
        trieNode* right;

    };

    int findmaxxor(int num, trieNode* root) {

        trieNode* prawler = root;
      int maxxor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
      

            if (bit == 1) {

                if (prawler->left != NULL) {
                    maxxor += pow(2, i);
                    prawler = prawler->left;
                } else {
                    prawler = prawler->right;
                }

            } else {
                if (prawler->right != NULL) {
                    maxxor += pow(2, i);
                    prawler = prawler->right;
                } else {
                    prawler = prawler->left;
                }
            }
        }

        return maxxor;
    }

    void insert(trieNode* root, int& num) {

        trieNode* prawler = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (bit == 0) {

                if (prawler->left == NULL) {
                    prawler->left = new trieNode();
                }

                prawler = prawler->left;

            } else {
                if (prawler->right == NULL) {
                    prawler->right = new trieNode();
                }

                prawler = prawler->right;
            }
        }
    }


    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();

        trieNode* root = new trieNode();

        for (int i : nums) {
            insert(root, i);
        }

        int maxi = 0;
        for (int i = 0; i < n; i++) {

            int num = nums[i];

            int maxxor = findmaxxor(num, root);

            if (maxxor > maxi) {
                maxi = maxxor;
            }
        }

        return maxi;
    }
};