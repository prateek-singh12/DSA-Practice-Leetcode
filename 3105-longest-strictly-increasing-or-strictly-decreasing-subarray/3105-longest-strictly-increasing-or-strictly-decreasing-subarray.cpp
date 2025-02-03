class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1,dec=1,res=1;
        if(nums.size()==0){return 0;}
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                inc++;
                dec=1;
                res=max(inc,res);
            }
            if(nums[i]>nums[i+1]){
                dec++;
                inc=1;
                res=max(res,dec);
            }
            if(nums[i]==nums[i+1]){
                dec=1;
                inc=1;
            }

        } 
        return res;       
    }
};