class Solution {
public:
    
    
    int helper(vector<vector<int>>&mat,int x,int y)
    {
        int count=0;
        
        int bound=mat[0].size();
        
        for(int i=x;i<mat.size();i++){
            for(int j=y;j<bound;j++){
                  if(mat[i][j])count++;
                 else bound=j;
            }
        }
        
        return count;
        
        
    }
    
    
    int numSubmat(vector<vector<int>>& mat) {
        
        int rows=mat.size();
        int cols=mat[0].size();
        
        int ans=0;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]){
                  ans+=helper(mat,i,j);  
                }
            }
        }
        
        return ans;
        
        
    }
};
