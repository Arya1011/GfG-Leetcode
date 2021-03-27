//https://leetcode.com/problems/jump-game/




//Greedy Approach
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
