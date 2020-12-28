

//https://leetcode.com/problems/reach-a-number/

class Solution {
public:
    int reachNumber(int target) {
        
        if(target<0){
            target=-target;
        }
        
        int moves=0;
        
        int sum=0;
        
        while(true){
            
            moves++;
            sum+=moves;
            
            if(sum==target){
                return moves;
            }
            
            else if(sum>target && (sum-target)%2==0){
                return moves;
            }
            
            
        }
        
        return 0;
    }
};
