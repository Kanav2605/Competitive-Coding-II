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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res; //list(store all correct zig values)
        if(root == NULL)return res;

        queue<TreeNode*>nodesQueue; //Queue to do traversal(level order)
        nodesQueue.push(root);
        bool LtoR = true;

        while(!nodesQueue.empty()) {
            int n = nodesQueue.size();
            vector<int>row(n);
            for(int i =0;i<n;i++) {
                TreeNode*node = nodesQueue.front();
                nodesQueue.pop();

                //find pos to fill node's value
                int index = (LtoR) ? i : (n-i-1);

                row[index] = node->val;
                if(node->left) {
                    nodesQueue.push(node->left);
                }
                if(node->right) {
                    nodesQueue.push(node->right);
                }
            }

            //after this level
            LtoR =! LtoR;
            res.push_back(row);
        }
        return res;
    }
};