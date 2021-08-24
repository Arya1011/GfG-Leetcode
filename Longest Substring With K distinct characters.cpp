#include <bits/stdc++.h>
using namespace std;

int solve(string s,int k){
    int start=-1;
    int ans=0;
    int n=s.size();
    unordered_map<char,int> mp;
    int i=-1;
    int j=-1;
    while(true){
        bool f1=false;
        bool f2=false;
        while(i<n)
        {
            f1=true;
            i++;
            mp[s[i]]++;
            if(mp.size()<k){
                continue;
            }

            else if(mp.size()==k){
                if(i-j>ans){
                    ans=i-j;
                }
            }

            else{
                break;
            }
        }

        while(j<i){
            f2=true;
            j++;
            char ch=s[j];
            if(mp[s[j]]==1){
                mp.erase(s[j]);
            }
            else{
                mp[s[j]]--;
            }

            if(mp.size()>k){
                continue;
            }

            //once we balance the string we need to acquire more characters
            else if(mp.size()==k){
                if(i-j>ans){
                    ans=i-j;
                }
                break;
            }
        }

        if(f1==false && f2==false){
            break;
        }
    }
   return ans;
}


int main() {
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<solve(s,k)<<endl;
}
