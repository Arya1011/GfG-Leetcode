class Solution {
  public:
    int helper(int sum[],int n)
    {
        int ans=INT_MIN;
        int curr_sum=0;
        
        for(int i=0;i<n;i++){
            curr_sum+=sum[i];
             ans=max(ans,curr_sum);
            if(curr_sum<0){
                curr_sum=0;
            }
        }
        
        return ans;
        
    }
  
  
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        
        //2D Kadane's Algorithm
        int ans=INT_MIN;
        for(int sr=0;sr<R;sr++){
            int sum[C];
            memset(sum,0,sizeof(sum));
            for(int cr=sr;cr<R;cr++){
                for(int cc=0;cc<C;cc++){
                    sum[cc]+=M[cr][cc];
                }
                ans=max(ans,helper(sum,C));
            }
        }
        return ans;
    }
};
