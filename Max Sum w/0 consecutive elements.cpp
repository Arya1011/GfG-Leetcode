



//Max sum such that no consecutive elements

#include<bits/stdc++.h>
using namespace std;


void solve(){
    vector<int>arr={5, 5, 10, 100, 10, 5};

    vector<int> sum(arr.size());

    sum[0]=arr[0];

    sum[1]=max(sum[0],arr[1]);

    for(int i=2;i<arr.size();i++){
         sum[i]=max(sum[i-1],sum[i-2]+arr[i]);
    }

    cout<<sum[arr.size()-1];
}

int main(){
    solve();
}
