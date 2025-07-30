class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        //maximize the minimum distance -> binary search
        sort(position.begin(), position.end());
        
        int l = 1; 
        int r = position.back() - position[0];  // range

        // Binary Search
        while (l < r) {
            int mid = l + (r - l) / 2;
            int count = 1;
            int last = position[0];

            for (int i = 1; i < position.size(); i++) {
                if (position[i] - last >= mid) {
                    count++;
                    last = position[i];
                }
            }

            if (count < m) {
                r = mid; // not enough balls can be placed
            } else {
                l = mid + 1; // mid works, try larger
            }
        }

        return l;  // max distance that works
    }
};
