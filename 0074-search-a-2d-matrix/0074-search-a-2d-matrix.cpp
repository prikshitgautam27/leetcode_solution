class Solution {
public://idea is assume  a 1D row like [1, 3, 5, 7, 10, 11, 16, 20, 23, 30, 34, 60], use 
//row=mid/m to get row for midval to comparison ,similarly col value from col=mid%m;
//m is no of cols (fixed for every row)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0;
        int right=n*m-1;

        while(left<=right){
            int mid=left+(right-left)/2;
            int row=mid/m;//Division (/) gives the row number.

                //Modulo (%) gives the column number
            int col=mid%m;
            int midval=matrix[row][col];
            if(midval==target){
                return true;
            }
            else if(midval < target){
                left=mid+1;

            }
            else{
                right=mid-1;
            }
        }
        return false;
    }
};