//https://www.geeksforgeeks.org/partition-set-k-subsets-equal-sum/
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
  
  
   bool helper_util(int a[],vector<int>&subsetSum,vector<bool>&seen,int subset,int n,int k,int currIdx,int lastIdx){
       
       
       //we have found a subset
       if(subsetSum[currIdx]==subset)
       {
           //means this is the last required subset
           if(currIdx==k-2){
               return true;
           }
           //call for remaining subsets
           return helper_util(a,subsetSum,seen,subset,n,k,currIdx+1,n-1);
       }
       
       //we will recurse on remaining elements
       for(int i=lastIdx;i>=0;i--)
       {
           if(seen[i]==true){
               continue;
           }
           int tmp=subsetSum[currIdx]+a[i];
           if(tmp<=subset){
               subsetSum[currIdx]+=a[i];
               seen[i]=true;
                //recurse on remaining part of the array
           bool next=helper_util(a,subsetSum,seen,subset,n,k,currIdx,i-1);
        
              if(next){
               return true;
           }
           
           subsetSum[currIdx]-=a[i];
           seen[i]=false;
           }
       }
       return false;
       
   }
  
  
   bool helper(int a[],int n,int k){
       
       if(k==1){
           return true;
       }
       
       if(n<k){
           return false;
       }
       
       int sum=0;
       
       for(int i=0;i<n;i++){
           sum+=a[i];
       }
       
       if(sum%k!=0){
           return false;
       }
       
       vector<bool>seen(n,false);
       vector<int> subsetSum(k,0);
       int subset=sum/k;
       
       
       //consider we have taken last element
       subsetSum[0]=a[n-1];
       seen[n-1]=true;
       //call for remaining elements
       return helper_util(a,subsetSum,seen,subset,n,k,0,n-1);
   }
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         
         return helper(a,n,k);
         
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends
