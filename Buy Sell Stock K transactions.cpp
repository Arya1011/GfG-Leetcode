
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
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
