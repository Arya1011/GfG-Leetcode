

class Solution
{
  public:
    int helper(vector<int>& heights) 
    {
        stack<int> s;
        int i=0;
        int n=heights.size();
        int max_area=0;
   
        //Approach is to consider each bar as the smallest bar while calculating the area
        
        while(i<n)
        {
            //If current bar is the larger than stack top means we havent reached right bounding condition for a                previously larget bar(this smaller bar is the boundary till whcih we can consider area with the                  s.top() as the smallest bar)
            if(s.empty() || heights[s.top()]<heights[i]){
                s.push(i);
                i++;
                continue;
            }
            
            else{
                
                int x=s.top();
                s.pop();
                
                // [2,1,5,6,3] if stack is not empty then the popped bar i considered as min height bar and its left and right bounds have a total width of i(current index)-s.top()(previous index)-1(the bar itself)
                
                //if stack is empty then we simply multiply with i ,eg: 1 height bar will remain in the stack till the end so thw width of rectangle considering 1 as min height bar will be the entire histogram width itself which is i.
                
                int area=heights[x] *(s.empty()?i:i-s.top()-1);
                max_area=max(max_area,area);
            }
        }
        
        //Process the remaining bars
        
        while(!s.empty()){
            int x=s.top();
            s.pop();
            int area=heights[x]*(s.empty()?i:i-s.top()-1);
            max_area=max(max_area,area);
        }
        
        return max_area;
    }

  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
          int area;
          int max_area=INT_MIN;
          vector<int> v;
          for(int i=0;i<m;i++)
          {
              v.push_back(M[0][i]);
          }
          area=helper(v);
          max_area=max(area,max_area);
          
          for(int i=1;i<n;i++){
              for(int j=0;j<m;j++){
                  if(M[i][j]==0){
                      v[j]=0;
                  }
                  
                  else{
                      v[j]=v[j]+M[i][j];
                  }
              }
              
              area=helper(v);
              max_area=max(max_area,area);
          }
        return max_area;
    }
};
