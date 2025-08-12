// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int left = 0;
//         int right = nums.size() - 1;
//         while (left < right) {
//             int mid = left + (right - left) / 2;

//             // Count how many numbers are less than or equal to 'mid'
//             int count = 0;
//             for (int num : nums) {
//                 if (num <= mid) {
//                     count++;
//                 }
//             }

//             // If the count is more than 'mid', then the duplicate is in the left half
//             if (count > mid) {
//                 right = mid;
//             } else {
//                 left = mid + 1; 
//             }
//         }
//         return left;
//     }
// };


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        // Move once before entering while
        slow = nums[slow];
        fast = nums[nums[fast]];

        // Phase 1: Detect cycle
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // Phase 2: Find cycle start
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
