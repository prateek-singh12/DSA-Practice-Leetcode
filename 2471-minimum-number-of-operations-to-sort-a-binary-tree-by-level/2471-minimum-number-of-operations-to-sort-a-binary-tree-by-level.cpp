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
    int calculateMinSwaps(vector<int>& arr) {
        int swaps = 0;
        vector<int> sortedArr(arr.begin(), arr.end());
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> valueIndexMap;
        int size = sortedArr.size();

        for (int i = 0; i < size; i++) {
            valueIndexMap[arr[i]] = i;
        }

        for (int i = 0; i < size; i++) {
            if (arr[i] != sortedArr[i]) {
                int correctIndex = valueIndexMap[sortedArr[i]];
                valueIndexMap[arr[i]] = correctIndex;
                swap(arr[i], arr[correctIndex]);
                swaps++;
            }
        }
        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> levelQueue;
        levelQueue.push(root);
        int totalOperations = 0;

        while (!levelQueue.empty()) {
            int currentLevelSize = levelQueue.size();
            vector<int> levelValues;

            for (int i = 0; i < currentLevelSize; i++) {
                TreeNode* currentNode = levelQueue.front();
                levelQueue.pop();
                levelValues.push_back(currentNode->val);

                if (currentNode->left) {
                    levelQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    levelQueue.push(currentNode->right);
                }
            }

            totalOperations += calculateMinSwaps(levelValues);
        }

        return totalOperations;
    }
};
