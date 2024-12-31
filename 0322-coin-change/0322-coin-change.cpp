class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //greedy wont work , for ex : 1,5,6,9 and amt=11 (answer: 2)
        if (amount < 1) return 0;
        vector <int> minCoinsDP(amount+1);
        for (int i = 1; i <= amount; i++) {
            minCoinsDP[i] = INT_MAX;
            // Try each coin
            for (int coin : coins) { //ITERATE THROUGH ALL COINS PRESENT
                if (coin <= i && minCoinsDP[i - coin] != INT_MAX) {  //TO PREVENT OVERFLOW
                    minCoinsDP[i] = min(minCoinsDP[i], 1 + minCoinsDP[i - coin]);
                }
            }
        }

    if (minCoinsDP[amount] == INT_MAX) {
        return -1;
    }

    return minCoinsDP[amount];
    }
};