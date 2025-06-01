class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long count = 0;

        for (int a = 0; a <= min(n, limit); ++a) {
            int remaining = n - a;

            // b + c = remaining
            // and 0 <= b, c <= limit

            int min_b = max(0, remaining - limit);
            int max_b = min(limit, remaining);

            if (min_b <= max_b) {
                count +=(max_b - min_b + 1);
            }
        }

        return count;
    }
};
