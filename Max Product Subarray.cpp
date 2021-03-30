class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max=nums[0];
        int curr_min=nums[0];
        int prev_max=nums[0];
        int prev_min=nums[0];
        int n=nums.size();
        int ans=nums[0];
        for(int i=1;i<n;i++){
            
            curr_max=max(nums[i],max(prev_min*nums[i],curr_max*nums[i]));
            curr_min=min(nums[i],min(prev_max*nums[i],curr_min*nums[i]));
            
            
            if(curr_max>ans){
                ans=curr_max;
            }
            
            prev_max=curr_max;
            prev_min=curr_min;
        }
            
      return ans;
            
    }
};
