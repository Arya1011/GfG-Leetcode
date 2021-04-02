 long long int  countPS(string str)
    {
      
      long long int n=str.size();
       long long int dp[n+1][n+1];
       long long int MOD=1e9+7;
       memset(dp,0,sizeof(dp));
       for(long long int i=0;i<n;i++){
           dp[i][i]=1;
       }
       //dp[i][j] denotes total number of palindromic subseq from index i to j
       for(long long int len=2;len<=n;len++){
           //starting index
           for(long long int i=0;i<n-len+1;i++){
               long long int j=i+len-1;
               if(str[i]==str[j]){
                   dp[i][j]=(1+dp[i+1][j]+dp[i][j-1])%MOD;
               }
               else{
                   dp[i][j]=(dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1])%MOD;
                   if(dp[i][j]<0){
                       dp[i][j]+=MOD;
                   }
               }
           }
       }
       
       
       return dp[0][n-1]%MOD;
      
    }
     
