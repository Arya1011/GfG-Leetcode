//https://leetcode.com/problems/subarray-sums-divisible-by-k/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int curr_sum=0;
        
        int ans=0;
        
        unordered_map<int,int>mp;
        
        mp[0]=1;
        
        for(int i=0;i<nums.size();i++){

        
            curr_sum+=nums[i];
            curr_sum%=k;
            curr_sum=(curr_sum+k)%k;
            mp[curr_sum]++;
        }
        
        for(auto it:mp){
            if(it.second>=2){
                int m=it.second;
                ans+=((m)*(m-1))/2;
            }
        }
        return ans;
    }
};
