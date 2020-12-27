//https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int jumps=0;
        if(n==1){
            //zero jumps
            return true;
        }
        
        //this is my start and end
        pair<int,int> intervals{0,0};
        
        for(int i=0;i<n;i++){
            int can_reach=-1;
            jumps++;
            for(int j=intervals.first;j<=intervals.second;j++){
                can_reach=max(can_reach,j+nums[j]);
            }
            if(can_reach>=n-1){
                return true;
            }
            //update the starting point now
            intervals={intervals.second+1,can_reach};
            if(intervals.first>intervals.second){
                 return false;
            }
        }
        return false;
    }
};
