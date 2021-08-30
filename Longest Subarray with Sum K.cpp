#include<bits/stdc++.h>
using namespace std;



void solve()
{
    vector<int>arr{ 10, 5, 2, 7, 1, 9 };
    int k=15;
    unordered_map<int,int> mp;
    int curr_sum=0;
    int max_len=INT_MIN;
    int s,e;

    for(int i=0;i<arr.size();i++){
        curr_sum+=arr[i];


        if(curr_sum==k && max_len==INT_MIN){
             s=0;
             e=i;
             max_len=i+1;
        }

        if(mp.find(curr_sum)==mp.end()){
            mp[curr_sum]=i;
        }

        if(mp.find(curr_sum-k)!=mp.end()){
            if(max_len<i-mp[curr_sum-k]){
                max_len=i-mp[curr_sum-k];
                s=mp[curr_sum-k]+1;
                e=i;
            }
        }
    }


    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";
    }



}



int main(){
    
     solve();
    


}
