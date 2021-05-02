

#include<bits/stdc++.h>
using namespace std;



void helper(vector<int>&arr,vector<int>&curr_sel,int curr_sum,vector<int>&soln,int &min_diff,int selected,int sum,int idx,int n){


   if(idx==n){
       return;
   }

   if((n/2-selected)>(n-idx)){
       return;
   }


   //exclude

   helper(arr,curr_sel,curr_sum,soln,min_diff,selected,sum,idx+1,n);


   //inlcude


   selected++;
   curr_sel[idx]=1;
   curr_sum+=arr[idx];

   if(selected==n/2)
   {
       //check
       if(abs(sum/2-curr_sum)<min_diff){
           min_diff=abs(sum/2-curr_sum);
           //update soln array
           for(int i=0;i<n;i++){
               soln[i]=curr_sel[i];
           }
       }
   }

   else
   {
        helper(arr,curr_sel,curr_sum,soln,min_diff,selected,sum,idx+1,n);
   }
   curr_sel[idx]=-1;
   return;
}



void solve(){

     
     vector<int> arr{23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};

       int n=arr.size();
      vector<int> curr_sel(n,-1);
      vector<int> soln(n,-1);
      int selected=0;
      int min_diff=INT_MAX;

    


     int sum=0;

     for(int i=0;i<n;i++){
         sum+=arr[i];
     }

     int curr_sum=0;

       helper(arr,curr_sel,curr_sum,soln,min_diff,selected,sum,0,n);

       for(int i=0;i<n;i++){
           if(soln[i]!=-1){
               cout<<arr[i]<<" ";
           }
       }

       cout<<endl;

       for(int i=0;i<n;i++){
           if(soln[i]==-1){
               cout<<arr[i]<<" ";
           }
       }


}

int main()
{

     solve();


}

