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


// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         //MIRRORING BINARY TREE
//         if(root==NULL) return root;
//         TreeNode* temp=root->left;
//         root->left=root->right;
//         root->right=temp;

//         invertTree(root->left);
//         invertTree(root->right);

//         return root;

//     }
// };


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            // swap children
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);

            swap(node->left, node->right);
        }
        return root;
    }
};


