bool isInterleave(string A, string B, string C) 
{
    //Your code here
    int n=A.length();
    int m=B.length();
    //dp[i][j] denotes wheter substrings of length i and j in a and b resp are interleaving in substring of len i+j-1 in c 
    bool dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            //a is empty and b is empty
            if(i==0 && j==0){
                 dp[i][j]=true;
            }
            //a is empty
            else if(i==0){
                if(B[j-1]==C[i+j-1]){
                    dp[i][j]=dp[i][j-1];
                }
            }
            else if(j==0){
                if(A[i-1]==C[i+j-1]){
                    dp[i][j]=dp[i-1][j];
                }
            }
            
            else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1]){
                 dp[i][j]=dp[i-1][j];
            }
            else if(A[i-1]!=C[i+j-1] && B[j-1]==C[i+j-1]){
                dp[i][j]=dp[i][j-1];
            }
            else if(A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1]){
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            }
        }
    }
    return dp[n][m]; //if entire a string and b string are interleaving in c string
}
