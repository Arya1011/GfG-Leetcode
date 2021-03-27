//https://leetcode.com/problems/jump-game/


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
