class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();           // Number of rows
        int n = grid[0].size();        // Number of columns     

        queue<pair<int,int>> q;
        int totalone=0;
        int boundary_one_connected=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(i==0||j==0||i==m-1||j==n-1){
                        q.push({i,j});
                        grid[i][j] = -1;
                    }
                    totalone++;
                }
            }
        }
        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};

        while(!q.empty()){            
            int sz=q.size();   //s-1: q.size()
             //s2: store and update answer variable inside any one while loop
            while(sz--){  //whilw(sz--) under while
                auto[x,y]=q.front();
                q.pop();             //s4: pop and .front() inside inner while
                boundary_one_connected++;
                 for(auto [dx,dy]: dir){ //s-5 direction
                    int nx=x+dx;
                    int ny=y+dy;             
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){//s-6 constraints (3,2),(4,1)(5,1)(6,1)
                        grid[nx][ny] = -1; //s 7: mark visited //or grid[nx][ny] == 0 
                        q.push({nx,ny});    //push in to queue
                    }
                }

            }
        }
        return totalone-boundary_one_connected;
    }
};