
class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();

        int maxOdd = 0;
        int minEven = n + 1; 
        unordered_map<int, int> mp;
        for (char &ch : s) {
            mp[ch - 'a']++;
        }

        for (auto const& [key, val] : mp) {

            if (val % 2 == 0) {
                minEven = min(minEven, val);
            } else {
                maxOdd = max(maxOdd, val);
            }
        }

        return maxOdd - minEven;
    }
};