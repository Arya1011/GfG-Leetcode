https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3546/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        
        deque<int> dq;
        int i;
        //First k elements
        for(i=0;i<k;i++){
           while(!dq.empty() && nums[i]>nums[dq.back()]){
                dq.pop_back();
           }
            dq.push_back(i);
        }
        
        for(;i<nums.size();i++){
            ans.push_back(nums[dq.front()]);
            //Delete elements which are not part of the window
            while(!dq.empty() && dq.front()<=i-k){
                 dq.pop_front();
            }
            
            //Delete elements which cannot be the largest
            while(!dq.empty() && nums[i]>nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
       
        //For the last element
        if(nums[dq.front()]>nums[dq.back()]){
                 ans.push_back(nums[dq.front()]);  
        }
        
        else{
            ans.push_back(nums[dq.back()]);
        }
        return ans;
        
    }
};
