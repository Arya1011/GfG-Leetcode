class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        
        int rows=matrix.size();
        int cols=matrix[0].size();
        
        
        for(int i=0;i<rows;i++){
            for(int j=1;j<cols;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        
        unordered_map<int,int>mp;
        int ans=0;
        for(int startCol=0;startCol<cols;startCol++){
            for(int currCol=startCol;currCol<cols;currCol++){
                mp.clear();
                mp[0]=1;
                int sum=0;
                for(int r=0;r<rows;r++){
                    sum+=matrix[r][currCol]-(startCol>0?matrix[r][startCol-1]:0);
                    ans+=mp.find(sum-target)!=mp.end()?mp[sum-target]:0;
                    mp[sum]++;
                }
                
                
            }
        }
        
        return ans;
        
        
    }
};
