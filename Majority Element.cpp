//https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        long long n=nums.size();
        long long count1=0,count2=0;
        long long first=LLONG_MAX;
        long long second=LLONG_MAX;
        
        for(int i=0;i<n;i++){

        
            if(first==nums[i]){

             count1++;
            
            }
            
            else if(second==nums[i]){

              count2++;
            
            }
            
            
            else if(count1==0){
                count1++;
                first=nums[i];
            }
            
            else if(count2==0){
              count2++;
              second=nums[i];
            }
            
            else{

             count1--;
             count2--;
            
            }
            
        
        }
        
        count1=count2=0;
        for(int i=0;i<n;i++){

            if(nums[i]==first) count1++;
            if(nums[i]==second)count2++;
        
        }
        
        if(count1>n/3) ans.push_back(first);
        if(count2>n/3) ans.push_back(second);
        
        return ans;
        
    }
};
