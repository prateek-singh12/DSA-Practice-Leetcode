class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; 
        long long odd = n / 2;        

        long long goodeven = modPow(5, even, MOD);
        long long goododd = modPow(4, odd, MOD);

        return (goodeven * goododd) % MOD;
    }
};
