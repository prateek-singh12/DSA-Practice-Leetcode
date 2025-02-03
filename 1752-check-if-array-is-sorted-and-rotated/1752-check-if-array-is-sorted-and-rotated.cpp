class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) 
            if (nums[i] > nums[(i+1)%n] && ++count > 1) return false;
        return true;
    }
};

// [2,2,2] ✅ (no inversions).
// [5,1,2,3,4] ✅ (1 inversion).
// [3,4,5,1,6] ❌ (2 inversions: 5>1 and 6>3).
// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         int n = nums.size();
//         int cnt=0;

//         for(int i=0;i<n;i++){
//             if(nums[i]>nums[(i+1)%n]) cnt++;
//         }
//         if(cnt>1)return false;
//         else return true;

//         //return false;
//     }
// };