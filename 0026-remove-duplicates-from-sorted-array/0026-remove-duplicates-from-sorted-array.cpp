// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int i=0;
//         while(i<nums.size()-1){
//             if(nums[i+1]==nums[i]){
//                 nums.erase(nums.begin()+(i+1));
//             }
//             else
//                 i++;
//         }
//         return nums.size();
//     }
// };

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         if(nums.size() == 0) return 0;
//         int res = 1;
//         for(int i = 1; i < nums.size(); i++){
//             if(nums[i] != nums[i - 1]){
//                 nums[res] = nums[i];
//                 res++;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){return nums.size();}

        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[j-1]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};