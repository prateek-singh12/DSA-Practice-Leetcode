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
    int n;

    TreeNode* solve(string s, int& i, int depth) {  //pass i by refernece bcz aftermaking left subtree it will come back to root
        if (i >= n) {
            return NULL;
        }
        int j = i;
        while (j < n && s[j] == '-') {
            j++;
        }
        int dash = j - i; //dash count
        if (dash != depth) { 
            return NULL;
        }
        i += dash; //updating i to current pos after j-i
        int num = 0;
        while (i < n && isdigit(s[i])) {
            num = (num * 10) + (s[i] - '0'); //two or three digit value
            i++;
        }

        TreeNode* root = new TreeNode(num);

        root->left = solve(s, i, depth + 1);
        root->right = solve(s, i, depth + 1);

        return root;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.length();
        int i = 0;
        int depth = 0;
        return solve(traversal, i, depth);
    }
};
