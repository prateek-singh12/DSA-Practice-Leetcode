class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int,double>>>adj;
        vector<double> result(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v= edges[i][1];
            double w=succProb[i];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<double,int>> pq;
        pq.push({1,start_node}); //max heap
        result[start_node]=1; //100% probability

        while(!pq.empty()){
            auto node=pq.top();
            int currnode=node.second;
            double currprob=node.first;
            pq.pop();

            for(auto &temp: adj[currnode]){
                double adjprob=temp.second;
                int adjnode=temp.first;
                if(result[adjnode] < currprob*adjprob){
                    result[adjnode] = currprob*adjprob;
                    pq.push({ result[adjnode],adjnode});
                }
            }
        }
        return result[end_node];
 
    }
};