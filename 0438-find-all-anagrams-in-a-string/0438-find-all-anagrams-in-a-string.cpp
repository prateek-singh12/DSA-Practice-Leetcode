class Solution {
public:
    bool allZero(vector<int>& counter) {
        for (int i : counter) {
            if (i != 0)
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string txt, string p) {
        int n = txt.size();
        vector<int> counter(26, 0);

        for (int i = 0; i < p.length(); i++) {
            char ch = p[i];
            counter[ch - 'a']++;
        }

        int i = 0, j = 0;
        vector<int> result;
        int k = p.length();

        while (j < n) {
            counter[txt[j] - 'a']--;

            if (j - i + 1 == k) {
                if (allZero(counter)) {
                    result.push_back(i);
                }
                counter[txt[i] - 'a']++;
                i++;
            }
            j++;
        }
        
        return result;
    }
};
