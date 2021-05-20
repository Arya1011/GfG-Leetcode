class NumMatrix {
public:
    //dp[i][j] means sum of submatrix from (0,0)->(i-1,j-1)
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) 
    {
            int rows=matrix.size();
            int cols=matrix[0].size();
            dp.resize(rows+1,vector<int>(cols+1,0));
            for(int i=1;i<dp.size();i++)
            {
                for(int j=1;j<dp[0].size();j++)
                {
                    //Reduce the value being added twice
                    dp[i][j]=dp[i-1][j]+dp[i][j-1]+matrix[i-1][j-1]-dp[i-1][j-1];
                }
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        row1++;
        col1++;
        row2++;
        col2++;
        return dp[row2][col2]-dp[row1-1][col2]-dp[row2][col1-1]+dp[row1-1][col1-1];
    }
};
