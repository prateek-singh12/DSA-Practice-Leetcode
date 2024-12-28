// class Solution {
// public:
//     int findMaxConsecutiveOnes(vector<int>& nums) {
//         int ans=0;
//         int temp=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==1){temp++;
//                         continue;} -- testcase 1 fails as bcz it is not updating the maximum value (ans) after the loop finishe
//             ans=max(ans,temp);
//             temp=0;
//         }
//         return ans;
        
//     }
// };

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int temp = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                temp++;
            } else {
                ans = max(ans, temp);
                temp = 0;
            }
        }
        ans = max(ans, temp);
        return ans;
    }
};
