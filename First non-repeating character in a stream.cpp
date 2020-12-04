
//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0#

#include<bits/stdc++.h>
using namespace std;


void solve(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
         queue<char>q;
         unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            char ch;
            cin>>ch;
            mp[ch]++;
            q.push(ch);
            
            while(!q.empty()){
                
                //repeated
                if(mp[q.front()]>1){
                    q.pop();
                }
                
                //not repeated
                else{
                    cout<<q.front()<<" ";
                    break;
                }
            }
            
            if(q.empty()){
                cout<<-1<<" ";
            }
        }
        cout<<endl;
    }
}


int main() {
	//code
	
	
	solve();
	
	
	return 0;
}
