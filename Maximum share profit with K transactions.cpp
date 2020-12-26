

//https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-k-times/?ref=lbp




#include<bits/stdc++.h>
using namespace std;

//profit[t][i]=max(profit[t][i-1],prices[i]-prices[j]+profit[t-1][j])

int maxProfit(vector<int> prices,int k){
      int n=prices.size();
      vector<vector<int>> profit(k+1,vector<int>(n+1));

      //0 transactions case
      for(int i=0;i<=n;i++){
          profit[0][i]=0;
      }

      //if there is only 0th day available
      for(int i=0;i<=k;i++){
          profit[i][0]=0;
      }

      //i means transactions,j here means days
      for(int i=1;i<=k;i++){
            //prices array only available till (n-1)th index
          for(int j=1;j<n;j++){
              int possible=INT_MIN;
              for(int m=0;m<j;m++){
                  possible=max(possible,prices[j]-prices[m]+profit[i-1][m]);
              }
              profit[i][j]=max(profit[i][j-1],possible);
          }
      }

      return profit[k][n-1];

}


void solve(){
    vector<int> prices={100, 30, 15, 10, 8, 25, 80};
    int k=3;
    cout<<maxProfit(prices,k)<<endl;
}

int main(){
    solve();
}
