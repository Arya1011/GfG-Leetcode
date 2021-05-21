class Solution {
public:
    
    int helper(vector<int>&sums,int k){
        
        int n=sums.size();
        
        set<int> cache;
        
        cache.insert(0);
        
        int max_sum=INT_MIN;
        
        int curr_sum=0;
        
        
        for(int i=0;i<n;i++){
            
            curr_sum+=sums[i];
            
            auto it=cache.lower_bound(curr_sum-k);
            
            if(it!=cache.end()){
                max_sum=max(max_sum,curr_sum-*it);
            }
            
            cache.insert(curr_sum);
            
        }
        
        return max_sum;
        
    }
    
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int rows=matrix.size();
        int cols=matrix[0].size();
        
        int res=INT_MIN;
        
        for(int l=0;l<cols;l++)
        {
            
            vector<int> sum(rows);
            
            for(int r=l;r<cols;r++){
                
                
                
                
                for(int i=0;i<rows;i++)
                {

                    sum[i]+=matrix[i][r];    
                }
                //once sum is computed for current rectangle
                
                int curr_max=helper(sum,k);
                
                res=max(curr_max,res);
                
                
            }
            
            
        }
        
        
        return res;
        
    }
};
