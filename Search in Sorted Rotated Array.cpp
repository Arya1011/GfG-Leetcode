https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3537/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n=nums.size();
        if(!n)return false;
        
        int left=0;
        int right=n-1;
        int mid;
        
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==nums[right]){
                right--;
            }
            else if(nums[mid]<nums[right]){
                 right=mid;
            }
            else if(nums[mid]>nums[right]){
                left=mid+1;
            }
        }
        
        //Least element present at mid position
        
        //Apply binary search on left and right sides
        
        int lo=0;
        int hi=mid-1;
        
        while(lo<=hi){
          int mid=(lo+hi)/2;
          if(nums[mid]<target){
              lo=mid+1;
          }
          
          else if(nums[mid]>target){

              hi=mid-1;
          }
            else{
                return true;
            }
        
        }
        
        lo=mid;
        hi=n-1;
        
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]>target){
                hi--;
            }
            else if(nums[mid]<target){
                lo++;
            }
            else{

             return true;
            
            }
        }
        
        return false;
        
    }
};
