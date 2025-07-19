class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);

        for (int i = 1; i<folder.size(); i++) {
            if(!folder[i].starts_with(ans.back() + '/')){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};