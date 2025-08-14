// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int result=0;
//         //S1=ki*n1+x
//         //S2=ki*n2+x   then s2-21 is divisble by k (same remainder of sum of both subarrays)
//         //to keep track of remainder -> map <remainder,count_of_remaonder>
//         int n=nums.size();
//         unordered_map <int,int> mp;
//         int sum=0; mp[0]=1;//inititially 0 so that 0%k=1 will be stored in mp
//         for (int i=0;i<n;i++){
//             sum=sum+nums[i];
//             int rem=sum % k;
//             if(rem<0){ rem=rem + k;}  //ex 7n-3 equals 7(n-1)+4
//             if(mp.find(rem)!=mp.end()){
//                 result=result+mp[rem];
//             }
//             mp[rem]++; //update frequency of remainder
//         }
//         return result;
//     }
// };

// // 2️⃣ Ab Hash table ka istemaal hoga iss modulas ko track karne ke liye. Hum ek frequency table bana lenge K (Divisor) size ki, kyuki K se divide hone par k tarah ke modulas hi possible hain. Oth position ko hum pehle se hi 1 ki frequency dedenge, kyuki sum = 0, toh k se divide hoga hi.
// // 3️⃣ Ab jab bhi kabhi koi modulas repeat hoga, hum check karenge ki table mai ye kitni baar aaya, aur uss value ko result mai add kardenge. Iska baad iss modulas ki position pe + 1 kardenge. Aur iss jabke jod ko final result ke naam se return kar denge.



class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>modcount;
        modcount[0]=1;
        int cursum=0;
        int ans=0;
        for(int num:nums){
            cursum+=num;
            int currmod=cursum % k;
            if(currmod<0){ currmod=currmod+k;} 
            //or int currmod = ((cursum % k) + k) % k;
            if(modcount.find(currmod)!=modcount.end()){
                ans+=modcount[currmod];
            }
            modcount[currmod]++;
        }
        return ans;
    }
};
