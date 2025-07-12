class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        if (firstPlayer > secondPlayer) swap(firstPlayer, secondPlayer);

        unordered_map<string, pair<int, int>> memo;

        auto encode = [](const vector<int>& v) -> string {
            string s;
            for (int x : v) {
                s += to_string(x) + ",";
            }
            return s;
        };

        function<pair<int, int>(vector<int>, int)> dfs = [&](vector<int> players, int round) -> pair<int, int> {
            string key = encode(players);
            if (memo.count(key)) return memo[key];

            int sz = players.size();
            for (int i = 0; i < sz / 2; ++i) {
                int a = players[i], b = players[sz - 1 - i];
                if ((a == firstPlayer && b == secondPlayer) || (a == secondPlayer && b == firstPlayer)) {
                    return {round, round};
                }
            }

            int mid = sz / 2;
            vector<vector<int>> next_rounds;

            vector<int> winners;
            function<void(int)> backtrack = [&](int idx) {
                if (idx >= sz / 2) {
                    vector<int> next = winners;
                    if (sz % 2 == 1) next.push_back(players[mid]);
                    sort(next.begin(), next.end());
                    next_rounds.push_back(next);
                    return;
                }
                int a = players[idx], b = players[sz - 1 - idx];
                if (a == firstPlayer || a == secondPlayer) {
                    winners.push_back(a);
                    backtrack(idx + 1);
                    winners.pop_back();
                } else if (b == firstPlayer || b == secondPlayer) {
                    winners.push_back(b);
                    backtrack(idx + 1);
                    winners.pop_back();
                } else {
                    winners.push_back(a);
                    backtrack(idx + 1);
                    winners.pop_back();
                    winners.push_back(b);
                    backtrack(idx + 1);
                    winners.pop_back();
                }
            };

            backtrack(0);

            int min_round = 100, max_round = 0;
            for (auto& next : next_rounds) {
                auto res = dfs(next, round + 1);
                min_round = min(min_round, res.first);
                max_round = max(max_round, res.second);
            }
            return memo[key] = {min_round, max_round};
        };

        vector<int> players(n);
        for (int i = 0; i < n; ++i) players[i] = i + 1;
        auto res = dfs(players, 1);
        return {res.first, res.second};
    }
};
