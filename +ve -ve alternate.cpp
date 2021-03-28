#include <bits/stdc++.h>
using namespace std;


void solve(vector<int>&arr){


  //put all negative elements to the end
  int n=arr.size();
  int i=0,j=n-1;


  
  while(i<j){
    while(i<=n-1 && arr[i]>0){
        i++;

  }
  
   while(j>=0 && arr[j]<0){

       j--;

   }

   if(i<j){
       swap(arr[i],arr[j]);
   }
  }


  int k=0;

  while(k<n && i<n){
      swap(arr[k],arr[i]);
      k+=2;
      i+=1;
  }

}


int main() {
     
      vector<int> arr{2,3,-4,-1,6,-9};
      solve(arr);
      for(auto i:arr){
          cout<<i<<" ";
      }
}
