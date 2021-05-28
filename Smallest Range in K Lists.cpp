
typedef pair<int,pair<int,int>> custom;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        priority_queue<custom,vector<custom>,greater<custom>> pq;
        int n=nums.size();
        int mx=INT_MIN,mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
             pq.push({nums[i][0],{i,0}});
             mx=max(mx,nums[i][0]);
        }
        
        mn=pq.top().first;
        
        int a=mn;
        int b=mx;
        
        while(!pq.empty())
        {
              custom curr=pq.top();
              pq.pop();
             
              int x= curr.second.first;
              int y=curr.second.second;
            
              if(y+1<nums[x].size())
              {
                  pq.push({nums[x][y+1],{x,y+1}});
                  mn=pq.top().first;
                  mx=max(mx,nums[x][y+1]);    
                  if(mx-mn<b-a){
                      a=mn;
                      b=mx;
                  }
              }
            
              else{
                  break;
              }
        }
         
        
        
        return {a,b};
    
        
    }
};
