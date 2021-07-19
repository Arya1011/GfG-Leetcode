class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                int front=j+1;
                int back=n-1;
                int sum=target-(nums[i]+nums[j]);
                while(front<back){
                    
                    
                    if(nums[back]+nums[front]==sum){
                        
                        vector<int> temp;
                         temp.push_back(nums[i]);
                         temp.push_back(nums[j]);
                         temp.push_back(nums[front]);
                         temp.push_back(nums[back]);
                        
                        while(front<back && nums[front]==temp[2]){
                            front++;
                        }
                        
                        while(front<back && nums[back]==temp[3]){
                            back--;
                        }
                        
                        ans.push_back(temp);
                    }
                    
                    else if(nums[back]+nums[front]>sum){

                         back--;
                    
                    
                    }
                    
                    else{
                        front++;
                    }
                    
                    
                    
                }
                
                while(i+1<n && nums[i]==nums[i+1]){
                    i++;
                }
                
                while(j+1<n && nums[j]==nums[j+1]){
                    j++;
                }
            }
            
        }
        
        return ans;
        
    }
};
