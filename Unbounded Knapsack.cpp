
//https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1#
class Solution
{
	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        long long int dp[N+1][W+1];
        
        int weights[N];
        
        for(int i=0;i<N;i++){
            weights[i]=i+1;
        }


       for(int i=0;i<=N;i++){
           for(int j=0;j<=W;j++){
               if(i==0){
                   dp[i][j]=INT_MAX;
                
               }
               
               else if(j==0){
                   dp[i][j]=0;
    
               }
               
               
               else if(weights[i-1]<=j && cost[i-1]!=-1){
                   dp[i][j]=min(dp[i-1][j],dp[i][j-weights[i-1]]+cost[i-1]);
               }
               
               else{
                   dp[i][j]=dp[i-1][j];
               }
           }
       }        
        
        
        if(dp[N][W]==INT_MAX){
            return -1;
        }
        
        return dp[N][W];
        
	} 
};
