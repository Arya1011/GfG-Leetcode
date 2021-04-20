
//O(n)
void preprocess(const string B,vector<int>&reset)
{
          int m=B.size();
          int len=0;
          int i=1;
          while(i<m){
              if(B[i]==B[len]){
                  len++;
                  reset[i]=len;
                  i++;
              }
              else{
                  if(len!=0){
                      len=reset[len-1];
                  }
                  
                  else{
                      reset[i]=0;
                      i++;
                  }
              }
          }
}

int Solution::strStr(const string A, const string B) 
{
          int n=A.size();
          int m=B.size();
          //KMP algorithm
          
          vector<int> reset(m);
          reset[0]=0;
          
          preprocess(B,reset);
          int i=0;
          int j=0;
          
          //O(n-m+1)
          while(i<n){
              if(A[i]==B[j]){
                  i++;
                  j++;
              }
              
              if(j==m){
                  
                  int ans= i-j;
                  j=reset[j-1];
                  return ans;
              }
              
              else if(i<n && A[i]!=B[j]){
                  if(j!=0){
                      j=reset[j-1];
                  }
                  
                  else{
                      i++;
                  }
              }
              
          }
      return -1;
}
