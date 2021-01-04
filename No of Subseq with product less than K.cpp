



//Number of subsequences with product less than k 

#include<bits/stdc++.h>
using namespace std;


void solve(){
     
    //dp[i][j] denotes product <=i using j elements


    vector<int> arr={1,2,3,4};
    int k=10;
    int n=arr.size();
    int dp[k+1][n+1];

    memset(dp,0,sizeof(dp));


    for(int i=1;i<=k;i++){
        for(int j=1;j<=arr.size();j++){
              dp[i][j]=dp[i][j-1];
              if(arr[j-1]<=i && arr[j-1]>0){
                    dp[i][j]+=1+dp[i/arr[j-1]][j-1];
              }
        }
    }
   cout<<dp[k][n];
}

int main(){
    solve();
}
