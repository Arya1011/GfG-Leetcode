
//https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1

class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
         const int MOD=1e9+7;
         
         vector<int>dp(n+1,0);
         
         dp[0]=1;
         dp[1]=1;
         
         for(long long int i=2;i<=n;i++){
             dp[i]=(dp[i-1]%MOD)+((dp[i-2]%MOD)*((i-1)%MOD))%MOD;
         }
        return dp[n]%MOD;
    }
};    
 
