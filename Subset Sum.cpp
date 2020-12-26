
//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

class Solution{
public:

    bool helper(int arr[],int N,int sum){
         bool dp[N+1][sum+1];
         for(int i=0;i<=N;i++){
             for(int j=0;j<=sum;j++){
                 if(i==0){
                     dp[i][j]=false;
                 }
                 else if(j==0){
                     dp[i][j]=true;
                 }
                 else if(arr[i-1]>j){
                     dp[i][j]=dp[i-1][j];
                 }else{
                     dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                 }
             }
         }
        
        return dp[N][sum];
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        
        if(sum%2!=0){
            return 0;
        }
        int s=sum/2;
        
        return helper(arr,N,s);
    }
};
