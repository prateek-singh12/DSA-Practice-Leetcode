class Solution {
public:
bool solve(string frnt,int k,string s){
    int count =0;
     int index = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == frnt[index]){
           index++;
           if( index == frnt.length()){
            index = 0;
            count++;
           }
           if(count  == k){
            return true;
           }
        }
    }
    return false;
}
    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string>q;
        q.push("");
        string ans = "";
        while(q.size() > 0){
           
        
                
            
                 for(char ch ='a';ch<='z';ch++){
                     string frnt = q.front();
                     frnt = frnt + ch;
                     if(solve(frnt,k,s)){
                         ans = frnt;
                        q.push(frnt);
                     }
                 }
                      q.pop();
            
        }
        return ans;
    }
};