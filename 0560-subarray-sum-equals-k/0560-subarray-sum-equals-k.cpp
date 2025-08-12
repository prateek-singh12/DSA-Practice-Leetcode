// class Solution {
// public:
//     int subarraySum(vector<int>& arr, int k) {
//     //we find out, that a subarray may also exist if this particular condition satisified, 
//     //(prefix[i] - k) should exist in our map, 
//     //If prefix[i] - prefix[j] = k where i > j 
//     //i.e if we are able to find (prefix[i] - k) is exist in our map, i.e prefix[j]
// 	//so, we can say that from index j + 1 to i, the sum of the elements is k,
//         int n = arr.size(); 
//         vector<int> prefix(n); // prefix array        
//         prefix[0] = arr[0];  //starting for loop from 1 so initialize for 0 index        
//         for(int i = 1; i < n; i++)
//         {
//             prefix[i] = arr[i] + prefix[i - 1];
//         }

//         unordered_map<int,int> mp;
//         int ans = 0;         
//         for(int i = 0; i < n; i++) 
//         {
//             if(prefix[i] == k) // if it already becomes equal to k
//                 ans++;
//             // find whether (prefix[i] - k) present in map or not
//             if(mp.find(prefix[i] - k) != mp.end())
//             {
//                 ans += mp[prefix[i] - k];
//             }
            
//             mp[prefix[i]]++; 
//         }
        
//         return ans; 
//     }
// };



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefix;
        prefix[0]=1;
        int cursum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
            
            
                count=count+prefix[cursum-k];
            
            prefix[cursum]++;
        }
        return count;
    }
};





