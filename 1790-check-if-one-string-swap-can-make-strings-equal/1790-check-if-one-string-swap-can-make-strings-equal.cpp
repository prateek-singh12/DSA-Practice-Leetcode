class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2){ return true;}
        vector<int> swap_position;
        int n = s1.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                count++;
                swap_position.push_back(i);
            }
        }
        if(count==2){
            int first=swap_position[0];
            int second=swap_position[1];
            if((s1[first]==s2[second]) && (s1[second]==s2[first])){
                return true;
            }
            return false;
        }
        return false;
    }
};