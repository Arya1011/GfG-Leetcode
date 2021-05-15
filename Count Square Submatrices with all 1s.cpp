class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        int dp[m][n];
        
        memset(dp,0,sizeof(dp));
        
        int res=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]){
                    dp[i][j]=1;
                    if(i>0 && j>0){
                         dp[i][j]+=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                    }
                    res+=dp[i][j];
                }
            }
        }
        return res;
    }
};
