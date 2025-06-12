class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int diff=abs(nums[0]-nums[nums.size()-1]);
        for(int i=1;i<nums.size();i++){
            int currdiff=abs(nums[i]-nums[i-1]);
            diff=max(diff,currdiff);
        }
        return diff;
    }
};