class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());

        while(l<r){
            int mid= l+(r-l)/2;
            int curr=0;
            for(int num:nums){
                int quotient=num/mid;
                curr+=quotient;
                if(num%mid != 0){ curr=curr+1;} //ceiling
            }
            if(curr>=threshold){
                r=mid;

            }
            else l=mid+1;
        }
        return l;
    }
};