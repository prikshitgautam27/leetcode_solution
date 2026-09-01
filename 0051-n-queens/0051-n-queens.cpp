class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n, string(n,'.'));
        vector<int>col(n,0),diag(2*n,0),antidiag(2*n,0);
        dfs(0,n ,board,col,diag,antidiag,res);

        return res;
    }

    void dfs(int row, int n,vector<string>&board,vector<int>&col,vector<int>&diag,vector<int>&antidiag, vector<vector<string>>&res ){

        if(row==n){
            res.push_back(board);
        }

        for(int c=0;c<n;c++){

            if(col[c] || diag[row+c] || antidiag[row-c+n]) continue;
            //Loop through all columns in the current row.

// If column c or diagonals are already occupied → skip.
            board[row][c]='Q';
            col[c]= diag[row+c] =antidiag[row-c+n]=1;
            dfs(row+1, n,board, col,diag,antidiag,res);
            board[row][c]='.';
            col[c]=diag[row+c]=antidiag[row-c+n]=0;

        }
    }
};