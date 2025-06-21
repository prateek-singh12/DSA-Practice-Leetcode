class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char c : word) freq[c]++;

        vector<int> counts;
        for (auto& [ch, f] : freq) counts.push_back(f);

        sort(counts.begin(), counts.end());
        int n = counts.size();
        int res = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int deletions = 0;
            int base = counts[i];

            for (int j = i + 1; j < n; ++j) {
                if (counts[j] > base + k)
                    deletions += counts[j] - (base + k);
            }

            for (int j = 0; j < i; ++j) {
                deletions += counts[j];
            }

            res = min(res, deletions);
        }
        return res;
    }
};
