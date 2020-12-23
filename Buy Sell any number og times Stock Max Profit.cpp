
//https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1

class Solution{
public:
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        
        vector<vector<int>> ans;
        
        
        int i=0;
        
        
        while(i<n)
        {
            //Local minima
            while(i<n-1 && A[i+1]<=A[i]){
                i++;
            }
            
            
             if(i==n-1){
                break;
            }
            
            int buy=i++;
            
            //cant have a sell day
           
            
            //Local maxima
            while(i<n && A[i]>=A[i-1]){
                i++;
            }
            
            int sell=i-1;
            
            ans.push_back({buy,sell});
        }
        
        
        return ans;
    }
};
