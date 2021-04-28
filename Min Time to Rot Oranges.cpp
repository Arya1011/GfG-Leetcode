
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool check(vector<vector<int>>&grid,int i,int j)
    {
        return (i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1);
    }

    int orangesRotting(vector<vector<int>>& grid) 
    {
        // Code here
        queue<pair<int,int>> q;
        int rows=grid.size();
        int cols=grid[0].size();
        //push rotten oranges in queue
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    //already considered these cells so mark it as visited
                    grid[i][j]=3;
                }
            }
        }
        int t=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto p=q.front();
                int i=p.first;
                int j=p.second;
                q.pop();
                if(check(grid,i+1,j))
                {
                        q.push({i+1,j});
                        grid[i+1][j]=3;
                }
                
                if(check(grid,i,j+1))
                {
                    q.push({i,j+1});
                    grid[i][j+1]=3;
                }
                
                if(check(grid,i,j-1))
                {
                    q.push({i,j-1});
                    grid[i][j-1]=3;
                }
                
                if(check(grid,i-1,j))
                {
                
                       q.push({i-1,j});
                       grid[i-1][j]=3;            
                }
            }
            t++;
        }
        
       for(int i=0;i<rows;i++){
           for(int j=0;j<cols;j++){
               if(grid[i][j]==1){
                   return -1;
               }
           }
       } 
        return t-1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
