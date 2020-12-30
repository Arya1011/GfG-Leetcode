

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n=nums.size();
        
        int s=0;
        int e=n-1;
        
        while(s<e){
            
            int mid=(s+e)/2;
            
            if(s==e){
                return s;
            }
            
            
             if(nums[mid]>nums[mid+1]){
                e=mid;
            }
            
            else{
                s=mid+1;
            }
            
        }
        
        return s;
        
    }
};
