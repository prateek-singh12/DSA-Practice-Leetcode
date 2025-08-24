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
//     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//         if (!root1 && !root2) return nullptr;    // both empty
//         if (!root1) return root2;               // only root2 present
//         if (!root2) return root1;               // only root1 present

//         TreeNode* merged = new TreeNode(root1->val + root2->val);
//         merged->left = mergeTrees(root1->left, root2->left);
//         merged->right = mergeTrees(root1->right, root2->right);

//         return merged;
//     }
// };


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root1, root2});

        while (!q.empty()) {
            auto [n1, n2] = q.front(); q.pop();
            n1->val += n2->val;

            if (n1->left && n2->left) {
                q.push({n1->left, n2->left});
            } else if (!n1->left) {
                n1->left = n2->left;
            }

            if (n1->right && n2->right) {
                q.push({n1->right, n2->right});
            } else if (!n1->right) {
                n1->right = n2->right;
            }
        }
        return root1;
    }
};


