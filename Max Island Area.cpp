//Max Area of Island
class Solution {
public:
    
    int ans=0;
    
    
    
    void dfs(vector<vector<int>>&grid,int i,int j,int &count,int rows,int cols){
        if(i>=rows || j>=cols || i<0 || j<0 || grid[i][j]==0){
            return;
        }
        
        count++;
        grid[i][j]=0;
        dfs(grid,i+1,j,count,rows,cols);
        dfs(grid,i,j+1,count,rows,cols);
        dfs(grid,i,j-1,count,rows,cols);
        dfs(grid,i-1,j,count,rows,cols);
        return;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]){
                     int count=0;
                     dfs(grid,i,j,count,rows,cols);
                     ans=max(ans,count);
                }
            }
        }
        return ans;
    }
};
