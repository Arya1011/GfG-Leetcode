

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
{
        int n=nums.size();
        int dp[n+1];
        dp[0]=INT_MIN;
        for(int i=1;i<=n;i++)
        {
             dp[i]=INT_MAX;
        }
        
        
        //dp[i] denotes element at which LIS of length i ends
        for(int i=0;i<n;i++){
            int idx=upper_bound(dp,dp+n+1,nums[i])-dp;
            cout<<nums[i]<<" "<<idx<<endl;
            if(dp[idx-1]<nums[i] && nums[i]<dp[idx]){
                 dp[idx]=nums[i];
            }
        }
   
     int lis=INT_MIN;
     for(int i=1;i<=n;i++){
         if(i>lis && dp[i]!=INT_MAX){
             lis=i;
         }
     }    
        
        return lis;
    }
};
