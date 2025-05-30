class Solution {
public:
    vector<int> findpath(vector<int>& edges, int node) {
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<int> result(n, INT_MAX);

        int dist = 0;
        while (node != -1 && !visited[node]) {
            result[node] = dist;
            visited[node] = true;
            node = edges[node];
            dist++;
        }
        return result;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1 = findpath(edges, node1);
        vector<int> dist2 = findpath(edges, node2);

        int minDist = INT_MAX, answer = -1;

        for (int i = 0; i < n; i++) {
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    answer = i;
                }
            }
        }
        return answer;
    }
};
