class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double res=INT_MIN;
        int cursum=0;
        int i=0,j=0;
        while(j<n){
            cursum+=nums[j];

            if(j-i+1==k){
                res = max(res, (doubl)cursum);
                cursum-=nums[i];
                i++;
            }
            j++;
        }
        return res/k;
        
    }
};