class Solution {
public:
    int usingDijkstraAlgorithm(int src, int dest, int k, unordered_map<int, list<pair<int, int>>> &adjList, int n) {
        vector<int> minStops(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        minStops[src] = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0];
            int city = curr[1];
            int stops = curr[2];

            if (city == dest) return cost;
            if (stops > k) continue;
            if (minStops[city] != INT_MAX && stops > minStops[city]) continue;
            minStops[city] = min(minStops[city], stops);

            for (auto nbr : adjList[city]) {
                int nbrCity = nbr.first;
                int nbrPrice = nbr.second;
                pq.push({cost + nbrPrice, nbrCity, stops + 1});
            }
        }

        return -1;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, list<pair<int, int>>> adjList;
        for (auto &flight : flights) {
            adjList[flight[0]].push_back({flight[1], flight[2]});
        }
        return usingDijkstraAlgorithm(src, dst, k, adjList, n);
    }
};
