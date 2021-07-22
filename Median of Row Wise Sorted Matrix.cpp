

int count(vector<int>&A,int mid)
{
      int l=0;
      int r=A.size()-1;
      while(l<=r)
      {
          int m=(l)+(r-l)/2;
          if(A[m]<=mid){
              l=m+1;
          }
          else{
              r=m-1;
          }
      }
  return l;
}

int Solution::findMedian(vector<vector<int> > &A) {

       int lo=1;
       int hi=1e9;
       int n=A.size();
       int m=A[0].size();
       while(lo<=hi){
           int mid=(lo)+(hi-lo)/2;
           int cnt=0;
           for(int i=0;i<n;i++){
               cnt+=count(A[i],mid);
           }
 
           if(cnt<=(n*m)/2) lo=mid+1;
           else hi=mid-1;
       }
    return lo;
}
