class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
          
          if(n==1 && m==1){
            if(grid[0][0]==1){
                return 1;
            }
            return 0;
          }

        vector<vector<int>>vis(n,vector<int>(m,0));
    
int maxarea=0,count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==1 && vis[i][j]==0 ){
                    count=0;
                    dfs(i,j,grid,vis,maxarea,count);
                }
            }
        }
        return maxarea;
    }
 
 void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis,int &maxarea,int& count){

    vis[r][c]=1;
    count++;
                maxarea=max(maxarea,count);
 int n=grid.size();
        int m=grid[0].size();
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    for(int i=0;i<4;i++){
        int nr=r+delrow[i];
        int nc=c+delcol[i];

        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0){
            dfs(nr,nc,grid,vis,maxarea,count);

        }
    }
 }

};