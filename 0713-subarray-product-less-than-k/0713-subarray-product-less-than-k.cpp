class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
         if (k <= 1) return 0;
        int n=nums.size();
        int curproduct=1;
        int ans=0;
        int i=0,j=0;
        while(j<n){
            curproduct*=nums[j];

            while(curproduct >= k){
                curproduct/=nums[i];
                i++;
            }
            

            ans+=(j-i+1); //number of subarrays ending at j
            j++;
        }
        return ans;
    }
};