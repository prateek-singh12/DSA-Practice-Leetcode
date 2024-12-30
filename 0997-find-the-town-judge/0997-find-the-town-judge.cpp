class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        for(int i=0;i<trust.size()-1;i++){
            if(trust[i][1]==trust[i+1][1]){
                    continue;
            }
            return -1;
        }
        return trust[0][1];
    }
};