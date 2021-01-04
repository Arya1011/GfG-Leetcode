class Solution {
public:
    int findLHS(vector<int>& nums) 
    { 
        //O(nlogn)
        sort(nums.begin(),nums.end());
        int prev_count=1;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int count=1;
            if(i>0 && nums[i]-1==nums[i-1]){
                
                    while(i<nums.size()-1 && nums[i]==nums[i+1]){
                        count++;
                        i++;
                    }
                
                ans=max(ans,prev_count+count);
                prev_count=count;
            }
            
            else{
                
                while(i<nums.size()-1 && nums[i]==nums[i+1]){
                    count++;
                    i++;
                }

                prev_count=count;
            }           
        }
        return ans;
    }
};


// class Solution {
// public:
//     int findLHS(vector<int>& nums) 
//     {
//         unordered_map<int,int> mp;
//         for(auto i:nums){
//             mp[i]++;
//         }
//         int ans=0;
//         for(auto it:mp){
           
//             if(mp.count(it.first-1)){
//                 ans=max(ans,it.second+mp[it.first-1]);
//             } 
                   
            
//         }
        
        
//         return ans;
        
//     }
// };
