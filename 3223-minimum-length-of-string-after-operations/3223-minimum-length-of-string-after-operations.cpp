class Solution {
public:
    int minimumLength(string s) {
        int n= s.size();
        // if(n<=3){return n;}
        int ans=0;
        vector<int> freq(26,0);
        for(auto ch: s){
            freq[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]%2==0 && freq[i]>0){  //if freq[i] is even and non zero
                ans+=2;
            } // dont take freq[i]=0 case
            else if(freq[i]>0){
                ans+=1;  //if freq[i] is odd
            } 
        }
        return ans;
    }
};