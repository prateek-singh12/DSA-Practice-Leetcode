class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //Subarray is a contiguous non-empty sequence CONTIGUOUS - THINK OF SLIDING WINDOW 
        int n=nums.size();
        int i=0,j=0,sum=0;
        int minlength=INT_MAX; //answer
        for(int k=0;k<n;k++){
            sum=sum+nums[j];
            while(sum>=target){ //then decrease window size WHILE LOOP
                minlength=min(minlength,j-i+1); //update ans
                sum=sum-nums[i]; //trying to decreasde window size by i++
                i++;
            }
            j++;
        }
        return minlength == INT_MAX ? 0 : minlength;  //IF no subarray, return 0      
    }
};