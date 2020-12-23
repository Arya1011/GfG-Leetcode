//https://leetcode.com/problems/next-permutation/

class Solution {
public:
    
    
    void rev(vector<int>&nums,int index){
        
          vector<int>temp;
          for(int i=index;i<nums.size();i++){
              temp.push_back(nums[i]);
          }
        
        reverse(temp.begin(),temp.end());
        
        for(int i=0,j=index;i<temp.size() && j<nums.size();i++,j++){
            nums[j]=temp[i];
        }
        
    }
    
    void nextPermutation(vector<int>& nums) {
       
          int n=nums.size();
          int i=n-2;
        
          
          while(i>=0){
              if(nums[i]<nums[i+1]){
                  break;
              }
              i--;
          }
        
         if(i>=0){
              int j=n-1;
              while(j>=0 && nums[j]<=nums[i]){
                  j--;
              }
             swap(nums[i],nums[j]);
             rev(nums,i+1);
         }
        else{
            reverse(nums.begin(),nums.end());
        }
    }
};
