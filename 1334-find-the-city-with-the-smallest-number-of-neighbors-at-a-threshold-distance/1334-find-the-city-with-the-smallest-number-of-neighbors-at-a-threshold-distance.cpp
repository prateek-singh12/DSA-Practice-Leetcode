class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>grid(n, vector<int>(n, INT_MAX)); 

        for(auto i:edges){
            grid[i[0]][i[1]]=i[2];
            grid[i[1]][i[0]]=i[2];
            //unconnected vertex will have grid value INT_MAX
        }
        // Distance from a city to itself is 0
        for (int i = 0; i < n; i++) grid[i][i] = 0;

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    
                    if(grid[i][via]!=INT_MAX && grid[via][j]!=INT_MAX){
                        grid[i][j]=min(grid[i][j], grid[i][via]+grid[via][j]);
                    }
                    
                }
            }
        }
        vector<int> distance(n,0);  // Count reachable cities within threshold
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]<=distanceThreshold  && i!=j){
                    distance[i]++;
                }
            }
        }
        
        int minCount = distance[0];
        int result = 0;
        for (int i = 1; i < n; i++) {
            if (distance[i] <= minCount) {
                minCount = distance[i];
                result = i;
            }
        }

        return result;
        
    }
};