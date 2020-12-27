
//https://www.geeksforgeeks.org/coin-change-dp-7/
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
        //code here.
        
        vector<vector<long long int>>dp(n+1,vector<long long int>(m,0));
        
        for(int i=0;i<m;i++){
            dp[0][i]=1;
        }
        
        for(long long int i=1;i<=n;i++){
            for(long long int j=0;j<m;j++){
                //include
                long long int x=i>=S[j]?dp[i-S[j]][j]:0;
                
                //exclude
                long long int y=j>=1?dp[i][j-1]:0;
                
                dp[i][j]=x+y;
            }
        }
        
        
        return dp[n][m-1];
        
        
    }
};
