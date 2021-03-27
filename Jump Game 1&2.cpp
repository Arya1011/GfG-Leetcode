//https://leetcode.com/problems/jump-game/


//Jump Game 1

//Backtracking O(2^n)
class Solution {
public:
    
    bool helper(int position,vector<int>nums)
    {
        
           if(position==nums.length()-1){
               return true;
           }
        
        
           int farthest= min(position+nums[position], nums.size()-1);
        
           
           for(int next=position+1;next<=farthest;next++){
               if(helper(next,nums)){
                   return true;
               }
           }
            return false;
    }
    
    
    bool canJump(vector<int>& nums) 
    {
           return helper(0,nums);    
    }
};


//Greedy Approach O(n)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if(nums.empty()){
            return true;
        }
        
        int lastPos=nums.size()-1;
        
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]+i>=lastPos){
                 lastPos=i;
            }
        }
        
        return lastPos==0;
        
    }
};



//Jump Game 2

//DP appraoch O(n^2)
class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> dp(n,0);
        
        if(n==1){
            return 0;
        }
        
        if(n==0 || nums[0]==0){
            return -1;
        }
        //dp[i] means min jumps to reach index i
        for(int pos=1;pos<n;pos++){
            dp[pos]=INT_MAX;
            for(int j=0;j<pos;j++){
                if(nums[j]+j>=pos && dp[j]!=INT_MAX){
                    dp[pos]=min(dp[j]+1,dp[pos]);
                    break;
                }
            }
        }
        return dp[n-1];
    }
};


//Greedy Solution O(n)
class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        
        if(n==1){
            return 0;
        }
        
        if(n==0 || arr[0]==0){
            return -1;
        }
        
         int steps=arr[0];
         int max_reach=arr[0];
         int jumps=1;
         for(int i=1;i<n;i++){
             if(i==n-1){
                 return jumps;
             }
             //check if we have a greater rwach found till now
             max_reach=max(max_reach,i+arr[i]);
             steps--;
             if(steps==0)
             {
                 //that means we could have reached till here only
                 if(i>=max_reach)
                 {
                     return -1;
                 }
                 jumps++;
                 steps=max_reach-i;
             }
         }
        return jumps;
    }
};

