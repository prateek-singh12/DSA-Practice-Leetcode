class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> C(n);
        int count=0;
        unordered_map<int , int> mp;
        for(int i=0;i<n;i++){
            mp[A[i]]++;  //array contains all integers from 1 to n exactly once(permutation)
            if(mp[A[i]]==2){
                count++;
                C[i]=count;
            }
            mp[B[i]]++;
            if(mp[B[i]]==2){
                count++;
                C[i]=count;
            }
        }
        return C;
    }
};