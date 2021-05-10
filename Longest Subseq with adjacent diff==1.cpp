// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        // code here
        
        
        int dp[N];
        memset(dp,0,sizeof(dp));
        
        
        for(int i=0;i<N;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(abs(A[j]-A[i])==1){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        
        int ans=INT_MIN;
        
        for(int i=0;i<N;i++){
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends
