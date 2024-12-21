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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int currentLevel = 0;
        
        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            vector<TreeNode*> levelNodes(levelSize);
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = nodeQueue.front();
                levelNodes[i] = currentNode;
                nodeQueue.pop();
                
                if (currentNode->left) {
                    nodeQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    nodeQueue.push(currentNode->right);
                }
            }
            
            if (currentLevel % 2 == 1) {
                int l = 0, r = levelSize - 1;
                
                while (l <= r) {
                    TreeNode* leftNode = levelNodes[l];
                    TreeNode* rightNode = levelNodes[r];
                    swap(leftNode->val, rightNode->val); //ptr to next level unchanged
                    l++;
                    r--;
                }
            }
            
            currentLevel++;
        }
        
        return root;
    }
};
