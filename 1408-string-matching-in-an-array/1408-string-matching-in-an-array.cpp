class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for(int i=0;i<n;i++){
            bool flag = 0;
            for(int j=0;j<n;j++){
                if(j!=i){
                    for(int k=0;k<words[j].size();k++){
                        string x;
                        for(int l=0;l+k<words[j].size();l++){
                            x.push_back(words[j][k+l]);
                            if(x == words[i]){
                                ans.push_back(words[i]);
                                flag = 1;
                                break;
                            }
                        }
                        if(flag)break;
                    }
                }
                if(flag)break;
            }
        }
        return ans;
    }
};