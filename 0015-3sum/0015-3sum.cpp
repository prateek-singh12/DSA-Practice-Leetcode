class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int target=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]+nums[i]==target){
                    ans.push_back({nums[right] , nums[left] , nums[i]});
                    left++;
                    right--;
                    while(nums[left] == nums[left-1] && left < right)
                        left++;
                    while(nums[right] == nums[right+1] && left < right)
                        right--;
                }
                else if(nums[left]+nums[right]+nums[i]>target){
                    right--;
                }
                else if(nums[left]+nums[right]+nums[i]<target){
                    left++;
                }
            }
        }
        return ans;    
    }
};
