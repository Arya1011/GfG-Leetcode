



#include<bits/stdc++.h>
#define MAX 100000001
using namespace std;

vector<int>*sieve(){

      bool isPrime[MAX];

      for(int i=0;i<MAX;i++){
          isPrime[i]=true;
      }

      for(int i=2;i*i<MAX;i++){
          if(!isPrime[i]){
              continue;
          }

          for(int j=i*i;j<MAX;j+=i){
              isPrime[j]=false;
          }
      }
      vector<int>*primes=new vector<int>();
      primes->push_back(2);
      for(int i=3;i<MAX;i+=2){
          if(isPrime[i]){
              primes->push_back(i);
          }
      }
      return primes;
}


void solve(vector<int>*&primes,int l,int r){

          bool isPrime[r-l+1];

          for(int i=0;i<=r-l;i++){
              isPrime[i]=true;
          }

          for(int i=0;primes->at(i) *(long long) primes->at(i)<=r;i++)
          {
                 int curr_prime=primes->at(i);

                 long long int base=(l/(curr_prime))*curr_prime;

                 if(base<l){
                     base+=curr_prime;
                 }

                 for(long long int j=base;j<=r;j+=curr_prime)
                 {
                         isPrime[j-l]=false;
                 }

                 if(base==curr_prime){
                     isPrime[base-l]=true;
                 }
          }

          for(int i=0;i<=r-l;i++)
          {
              if(isPrime[i])
              {
                  cout<<i+l<<" ";
              }
          }
}


int main()
{
    vector<int>*primes=sieve();
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        solve(primes,l,r);
    }
    return 0;
}
