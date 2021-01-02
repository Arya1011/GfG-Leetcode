//https://practice.geeksforgeeks.org/problems/game-with-string/0#

#include <bits/stdc++.h>
using namespace std;


void solve(){
    int t;
    scanf("%d",&t);
    unordered_map<char,int> mp;
    while(t--){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        int k;
        scanf("%d",&k);
        
        for(auto ch:s)
        {
             mp[ch]++;
        }
        
       priority_queue<int>pq;
        
        for(auto it:mp){
            pq.push(it.second);
        }
        
        
         while(k--)
         {
             int t=pq.top();
             pq.pop();
             t--;
             if(t){
                 pq.push(t);
             }
         }  
        
        int ans=0;
        
        while(!pq.empty())
        {
            int freq=pq.top();
            ans+=freq*freq;
            pq.pop();
        }
        cout<<ans<<endl;
        mp.clear();
    }
}


int main() {
	//code
	
	solve();
	
	return 0;
}


