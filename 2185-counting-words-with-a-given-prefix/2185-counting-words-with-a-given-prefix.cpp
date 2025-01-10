class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int n = pref.size();
        for (auto w : words) {
            if (pref == w.substr(0, n)) {
                count++;
            }
        }
        return count;
    }
};