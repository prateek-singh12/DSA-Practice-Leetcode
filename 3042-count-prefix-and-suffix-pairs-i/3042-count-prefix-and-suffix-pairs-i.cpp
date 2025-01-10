class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        //brute
        for (int i = 0; i < n; i++) {
            string s1 = words[i];

            for (int j = i + 1; j < n; j++) {
                string s2 = words[j];
                if (s2.length() < s1.length()) //then skip
                    continue;

                
                string pre = s2.substr(0, s1.length());
                string suf = s2.substr(s2.length() - s1.length());  // Extracts characters starting at index s2-s1 to the end

                
                if (pre == s1 && suf == s1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};