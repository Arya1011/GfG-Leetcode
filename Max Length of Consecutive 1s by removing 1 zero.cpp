#include<bits/stdc++.h>
using namespace std;

void solve(string text)
{  
    int n=text.size();
    int l=0,r=0;

    int cnt0=0;
     int max_idx=-1;
    int last_zero_idx=-1;
    int ans=INT_MIN;
    while(r<n){
 
        if(text[i]=='0'){
            cnt0++;
            last_zero_idx=r;
        }

        if(cnt0==2)
        {
               while(arr[l]){
                   l++;
               }
       
               l++;
               cnt0=1;
        }

        if(ans<r-l+1){
             ans=r-l+1;
             max_idx=last_zero_idx;
        }
        r++;
    }

   


}

int main(){
    string a,b;
    solve(a);
}
