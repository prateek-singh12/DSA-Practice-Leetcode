class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int odd=0, even=0;
        if(nums[0]%2==0) even++;
        else odd++;

        for(int i=1;i<nums.size();i++){
            
            if(nums[i]%2==0){
                even++;
                odd--;
            }
            else{
                odd++;
                even--;
            }
            if(odd>1 || even>1){ return false;}
        }
        return true;
        
    }
};