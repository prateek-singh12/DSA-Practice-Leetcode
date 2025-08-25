class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int cancover=0;
        for(int i=0;i<n;i++){
            if(cancover>=n-1) return true;

            cancover=max(cancover, i+nums[i]);
        }
        return false;
    }
};