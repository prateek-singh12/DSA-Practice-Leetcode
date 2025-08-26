class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto i: prerequisites){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
        }
        vector<int> indegree(numCourses,0);
        for(auto i: prerequisites){
            indegree[i[1]]++;
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> toposort;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            toposort.push_back(node);
            for(auto ngbr : adj[node]){
                indegree[ngbr]--;
                if(indegree[ngbr]==0){
                    q.push(ngbr);
                }
            }
        }
        if(toposort.size()==numCourses) return true;
        return false;

    }
};


// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

//         vector<vector<int>> adj(numCourses);
//         //adjacency list
//         for (auto i : prerequisites) {
//             adj[i[0]].push_back(i[1]);
//         }

//         vector<int> indegree(numCourses);
//         for(auto it:prerequisites){
//             indegree[it[1]]++;
//         }
//         // for (int i = 0; i < numCourses; i++) {
//         //     for (auto it : adj[i]) {
//         //         indegree[it]++;
//         //     }
//         // }

//         queue<int> q;
//         for(int i=0;i<numCourses;i++){
//             if(indegree[i]==0){
//                 q.push(i);
//             }
//         }
//         vector<int> toposort;
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             toposort.push_back(node);
//             for(auto it : adj[node]){
//                 indegree[it]--;
//                 if(indegree[it]==0){
//                     q.push(it);
//                 }
//             }
//         }
//         if(toposort.size()==numCourses){
//             return true;
//         }
//         return false;

        
//     }
// };