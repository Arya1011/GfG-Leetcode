
//https://www.geeksforgeeks.org/minimum-removals-array-make-max-min-k/

#include<bits/stdc++.h>
using namespace std;


int dp[100][100];


//O(n^2)
// int helper(vector<int>&arr,int i,int j,int k){
//     if(i>=j){
//         return 0;
//     }

//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }

//     if((arr[j]-arr[i])<=k){
//         return 0;
//     }

//     if((arr[j]-arr[i])>=k){
//         dp[i][j]=1+min(helper(arr,i+1,j,k),helper(arr,i,j-1,k));
//     }

//     return dp[i][j];

// }


int b_search(vector<int>&arr,int i,int n,int k,int key)
{
   int mid;
   int s=i+1;
   int e=n-1;
   int idx=-1;
   while(s<e)
   {
        mid=(s+e)/2;
        if(arr[mid]-arr[key]<=k)
        {
             idx=mid;
             s=mid+1;
        }
        else
        {
            e=mid;
        }
   }
return idx;
}


//O(nlogn)
int helper(vector<int>&arr,int s,int e,int k)
{
       int i,j;
       int n=arr.size();
       int ans=n-1;

       for(i=0;i<n;i++)
       {
           j=b_search(arr,i,n,k,arr[i]);
           if(j!=-1)
           {
                  ans=min(ans,(n-(j-i+1)));
           }
       }
   return ans;
}

void solve()
{
     vector<int> arr{1, 3, 4, 9, 10,11, 12, 17, 20};
      sort(arr.begin(),arr.end());
      int k=4;
     int n=arr.size();
     cout<<helper(arr,0,n-1,k);
}

int main(){
     memset(dp,-1,sizeof(dp));
    solve();
}
