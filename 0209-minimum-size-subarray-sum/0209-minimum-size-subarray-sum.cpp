class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        int i=0,j=0,sum=0;
        int res=INT_MAX; //answer
        int currlength=0;

        while(j<n){

            

            sum += nums[j];  // expanding window

            while (sum >= target) {  // shrinking window
                res = min(res, j - i + 1);  // update answer
                sum -= nums[i];
                i++;
            }

            j++;
        }  
        if(res==INT_MAX) return 0;  //sum of all elements smaller than target
        return res; 
    }
};
