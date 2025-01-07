class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for(int i=0;i<n;i++){
            bool flag = 0;
            for(int j=0;j<n;j++){
                if(j!=i){
                    int len = words[i].size();
                    for(int k=0;k+len <= words[j].size();k++){
                        if(words[j].substr(k,len) == words[i]){
                            ans.push_back(words[i]);
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag)break;
            }
        }
        return ans;
    }
};