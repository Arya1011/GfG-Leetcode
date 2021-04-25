  bool check(vector<vector<int>>&grid,int i,int j)
    {
        return (i>=0 && i<grid.size() && j>=0 && j<grid[0].size());
    }


	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int rows=grid.size();
	    int cols=grid[0].size();
	    vector<vector<int>> ans(rows,vector<int>(cols,INT_MAX));
	    queue<pair<int,int>> q;
	    for(int i=0;i<rows;i++){
	        for(int j=0;j<cols;j++){
	            if(grid[i][j]==1){
	                q.push({i,j});
	                ans[i][j]=0;
	            }
	        }
	    }
	    vector<pair<int,int>> dirs{{-1,0},{1,0},{0,1},{0,-1}};
	    while(!q.empty())
	    {
	        int curr_x=q.front().first;
	        int curr_y=q.front().second;
	        q.pop();
	        for(int i=0;i<dirs.size();i++)
	        {
	             int x=curr_x+dirs[i].first;
	             int y=curr_y+dirs[i].second;
	             if(check(grid,x,y))
	             {
	                 if(ans[x][y]>ans[curr_x][curr_y]+1)
	                 {
	                  ans[x][y]=ans[curr_x][curr_y]+1;
	                  q.push({x,y});
	                 }
	             }
	        }
	    }
	return ans;
  }
