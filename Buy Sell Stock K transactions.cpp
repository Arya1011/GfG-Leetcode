
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
//O(n^2 *K)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
          int n=prices.size();
        if(n==1 || n==0 || k==0){
            return 0;
        }
        
        if(n==2){
           if(prices[n-1]>prices[0]){
               return prices[n-1]-prices[0];
           } 
            return 0;
        }
        
        vector<vector<int>> profit(k+1,vector<int>(n+1));
        
        for(int i=0;i<=n;i++){
            profit[0][i]=0;
        }
        
        for(int i=0;i<=k;i++){
            profit[i][0]=0;
        }
        
        //profit[t][i]=max(profit[t][i-1],prices[i]-prices[j]+profit[t-1][j])
        for(int i=1;i<=k;i++){
            for(int j=1;j<n;j++){
                 int possible=INT_MIN;
                 for(int m=0;m<j;m++){
                     possible=max(possible,prices[j]-prices[m]+profit[i-1][m]);
                 }
                profit[i][j]=max(profit[i][j-1],possible);
            }
        }
        
        return profit[k][n-1];
    }
};

//O(nk)
class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        
        if(N==0 || K==0 || N==1){
            return 0;
        }
        
        if(N==2){
            if(A[0]<A[1]){
                return A[1]-A[0];
                
            }
            
            else{
                return 0;
            }
        }
        
        vector<vector<int>> dp(K+1,vector<int>(N+1,0));
        
        
        for(int i=0;i<=K;i++){
            dp[i][0]=0;
        }
        
        for(int i=0;i<=N;i++){
            dp[0][i]=0;
        }        
        
        
        for(int i=1;i<=K;i++){
            int prev_diff=INT_MIN;
            for(int j=1;j<N;j++){
                prev_diff=max(prev_diff,dp[i-1][j-1]-A[j-1]);
                dp[i][j]=max(dp[i][j-1],prev_diff+A[j]);
            }
        }
        return dp[K][N-1];
    }
};
