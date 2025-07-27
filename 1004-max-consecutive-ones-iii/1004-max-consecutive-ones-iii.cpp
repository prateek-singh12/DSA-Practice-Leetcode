class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int zerocount=0;
        int res=0;

        while(j<n){
            if(nums[j]==0){
                zerocount++;
            }
            while(zerocount>k){
                if(nums[i]==0) zerocount--;
                i++;
            }
            
            res=max(res,j-i+1);
            
            j++;
        }
        return res;
    }
};