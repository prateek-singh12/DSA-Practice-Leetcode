class Solution {
    const int MOD = 1e9 + 7;          
    vector<long long> fact, invFact;  
    long long modPow(long long base, long long exp) {
        long long result = 1;
        while(exp > 0) {
            if(exp & 1)             
                result = (result * base) % MOD;
            base = (base * base) % MOD;   
            exp >>= 1;                    
        }
        return result;
    }

    long long modInverse(long long x) {
        return modPow(x, MOD - 2);
    }

    void precomputeFactorials(int maxN) {
        fact.resize(maxN + 1);
        invFact.resize(maxN + 1);

        fact[0] = 1;
        for(int i = 1; i <= maxN; i++) {
            fact[i] = (fact[i-1] * i) % MOD;   
        }

        invFact[maxN] = modInverse(fact[maxN]);  
        for(int i = maxN - 1; i >= 0; i--) {
            invFact[i] = (invFact[i+1] * (i+1)) % MOD;
        }
    }

    long long nCr(int n, int r) {
        if(r > n || r < 0) return 0;
        return (fact[n] * ((invFact[r] * invFact[n - r]) % MOD)) % MOD;
    }

public:
    
    int countGoodArrays(int n, int m, int k) {
        precomputeFactorials(n);         
        long long res = m;
        res = (res * nCr(n - 1, k)) % MOD;                   
        res = (res * modPow(m - 1, n - 1 - k)) % MOD;         
        return (int)res;
    }
};