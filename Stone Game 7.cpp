class Solution {
public:
    int stoneGameVII(vector<int>& stones) 
    {
        int n=stones.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int sum[n+1];
        memset(sum,0,sizeof(sum));
        for(int i=0;i<n;i++)
        {
            sum[i+1]=sum[i]+stones[i];
        }
        
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i<n-len+1;i++)
            {
                int j=i+len-1;       
                dp[i][j]=max(sum[j+1]-sum[i+1] - dp[i+1][j],sum[j]-sum[i]-dp[i][j-1]);
                
            }
        }
        return dp[0][n-1];
    }
};
