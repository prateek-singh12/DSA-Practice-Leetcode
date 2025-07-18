
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<long long> leftSum(2 * n + 1, 0);
        vector<long long> rightSum(2 * n + 1, 0);

        priority_queue<int> leftHeap;
        long long leftTotal = 0;

        for (int i = 0; i < 2 * n; ++i) {
            leftHeap.push(nums[i]);
            leftTotal += nums[i];
            if (leftHeap.size() > n) {
                leftTotal -= leftHeap.top();
                leftHeap.pop();
            }
            if (leftHeap.size() == n) {
                leftSum[i] = leftTotal;
            }
        }

        priority_queue<int, vector<int>, greater<int>> rightHeap;
        long long rightTotal = 0;

        for (int i = 3*n-1; i >= n; --i) {
            rightHeap.push(nums[i]);
            rightTotal += nums[i];
            if (rightHeap.size() > n) {
                rightTotal -= rightHeap.top();
                rightHeap.pop();
            }
            if (rightHeap.size() == n) {
                rightSum[i] = rightTotal;
            }
        }
        
        long long answer = LLONG_MAX;
        for (int i = n-1; i < 2*n; ++i) {
            answer = min(answer, leftSum[i] - rightSum[i+1]);
        }
        return answer;
    }
};
