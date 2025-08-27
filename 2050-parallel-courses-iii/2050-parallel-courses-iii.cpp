class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n,0);
        for(auto i: relations){
            int u=i[0]-1;
            int v=i[1]-1;
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<int> maxtime(n,0);
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
                maxtime[i]=time[i];
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto ngbr: adj[node]){
                maxtime[ngbr]=max(maxtime[ngbr],maxtime[node]+time[ngbr]);
                indegree[ngbr]--;
                if(indegree[ngbr]==0){
                    q.push(ngbr);
                }
            }
        }
        return *max_element(maxtime.begin(),maxtime.end());
    }
};