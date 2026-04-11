class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid[0].size();int count=0;
        int m=grid.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
return count ;
    }
    void dfs(vector<vector<char>>&grid,int i,int j){
            int n=grid[0].size(); 
        int m=grid.size();
if(i<0||i>=m||j<0||j>=n||grid[i][j]!='1') return ;
grid[i][j]='0';
dfs(grid,i+1,j);
dfs(grid,i-1,j);
dfs(grid,i,j-1);
dfs(grid,i,j+1);


    }
};