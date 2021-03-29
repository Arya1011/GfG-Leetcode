

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<int> profit(n);
        profit[n-1]=0;
        int max_so_far=prices[n-1];
        //transaction from ith to n-1th day
        for(int i=n-2;i>=0;i--)
        {
            profit[i]=max(profit[i+1],max_so_far-prices[i]);
            max_so_far=max(prices[i],max_so_far);
        }
        int min_so_far=prices[0];
        //transaction from 0th to ith day
        for(int i=1;i<n;i++){
            profit[i]=max(profit[i-1],profit[i]+(prices[i]-min_so_far));
            min_so_far=min(prices[i],min_so_far);
        }
        return profit[n-1];
    }
};
