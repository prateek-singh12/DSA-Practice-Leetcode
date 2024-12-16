class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        
        int n = nums.size();
        vector<int> ans(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pri;
        for(int i=0;i<n;i++){
            pri.push({nums[i],i});
        }
        //sorted queue pri
        for(int i=0;i<k;i++)
        {
            pair<int,int> temp = pri.top();
            int item = temp.first;                // Explicitly access the first element
            int index = temp.second;              // Explicitly access the second element
            pri.pop();
            item *= mul;
            pri.push({item, index});
        }
    
        while(!pri.empty()){
            pair<int,int> temp2 = pri.top();
            int item = temp2.first;                
            int index = temp2.second; 
            pri.pop();
            ans[index] = item;
        }
        return ans;
    }
};