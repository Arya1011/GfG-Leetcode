class Solution {
public:
    vector<int> constructArray(int n, int k) 
    {
           int l=1;
           int r=k+1;
           vector<int> ans(n);
           int i=0;
           while(i<k)
           {
              ans[i++]=l++;
               ans[i++]=r--;
           }
        
         if(l==r){
             ans[i++]=r;
         }
        
         while(i<n){
             ans[i]=i+1;
             i++;
             
         }
         
        return ans;
        
    }
};
