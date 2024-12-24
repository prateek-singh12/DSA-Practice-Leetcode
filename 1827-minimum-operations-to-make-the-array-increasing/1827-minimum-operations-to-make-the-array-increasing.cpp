class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size=nums.size();
        int ans=0;
        for(int i=0;i<size-1;i++){
            if(nums[i]<nums[i+1]){continue;}
            int incrementBY=nums[i]-nums[i+1]+1;
            nums[i+1]=nums[i]+1; //updating values
            ans+=incrementBY;
            
        }
        return ans;
    }
};