#include <bits/stdc++.h>
using namespace std;

void solve(string s,int k)
{
      unordered_map<char,int> mp;
      int n=s.size();
      int i=-1;
      int j=-1;
      int ans=0;
      while(true){
           while(i<n-1)
      {
          i++;
          char ch=s[i];
          mp[ch]++;
          if(mp.size()<=k)
          {
              ans+=(i-j);
          }
          else
          {
              break;
          }
      }
 
     if(i==s.size()-1 && mp.size()<=k)
     {
         break;
     }
 
     //release
     while(j<i)
     {
          j++;
          char ch=s[j];
          if(mp[ch]==1)
          {
              mp.erase(ch);
          }
          else
          {
              mp[ch]--;
          }

          if(mp.size()>k)
          {
              continue;
          }
          else
          {
              ans+=(i-j);
              break;
          }
     }
}
cout<<ans<<endl;
}

int main() {
    string s;
    cin>>s;
    int k;cin>>k;
    solve(s,k);
}
