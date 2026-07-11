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
    int ans = 0;
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left_Ht = height(root->left);
        int right_Ht = height(root->right);

        ans = max(ans, left_Ht + right_Ht);  //curr_Diam of the root node
        return max(left_Ht, right_Ht) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};