class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m= mat[0].size();

        vector<int>result;
int row=0,col=0;
int direction=1;

        while( row<n && col<m){
            result.push_back(mat[row][col]);
                if(direction==1){//upright
                if(col==m-1){
                    row++;
                    direction=-1;
                }
                else if(row==0){
                    col++ ;
                    direction=-1;
                }
                else{
                row--;
                col++;
                }
                }
                else{// down
                    if(row==n-1){
                        col++;
                        direction=1;
                    }
                    else if(col==0){
row++;
direction=1;
                    }
                   else{ row++;
                    col--;}
                }
        }

return result;
    }
};