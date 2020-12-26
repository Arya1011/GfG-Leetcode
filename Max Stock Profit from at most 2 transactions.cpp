//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
          int n=prices.size();
          vector<int> profit(n);
           profit[n-1]=0;
           int max_so_far=prices[n-1];
          //From i->(n-1)th day what is ax profit possible from a single transaction
          for(int i=n-2;i>=0;i--){
              profit[i]=max(profit[i+1],max_so_far-prices[i]);
              max_so_far=max(max_so_far,prices[i]);
          }
        
          int min_so_far=prices[0];
         //From 0->(i)th day what is max profit possible considering selling after ith day
         for(int i=1;i<n;i++){
             profit[i]=max(profit[i-1],prices[i]-min_so_far+profit[i]);
              min_so_far=min(min_so_far,prices[i]);
         }
          return profit[n-1];
    }
};
