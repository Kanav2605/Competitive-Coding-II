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

    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left_Ht = height(root->left);
        int right_Ht = height(root->right);
        return max(left_Ht, right_Ht) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int left_Diam = diameterOfBinaryTree(root->left);
        int right_Diam = diameterOfBinaryTree(root->right);
        int curr_Diam = height(root->left) + height(root->right);

        return max(curr_Diam, max(left_Diam , right_Diam));
    }
};