class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        //Fact1: if arr[i] is div by arr[i+1] then total parts: arr[i]/arr[i+1]
        //else if not div, then parts in which it ahs to be broken is: (arr[i]/arr[i+1])+1
        //totsl repscement operations= parts-1
        //fact 2- in which two part it will be broken: nums[i]/parts
        //fact 3- peeche se start karna h
        int size=nums.size();
        long long ops=0;
        for(int i=size-2;i>=0;i--){
            if(nums[i]<nums[i+1]){continue;}
            int parts=nums[i]/nums[i+1];
            if(nums[i]%nums[i+1]!=0){parts++;}
            ops+=(parts-1);
            nums[i]=nums[i]/parts;
        }
        return ops;

        
    }
};