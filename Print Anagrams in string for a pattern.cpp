#include<bits/stdc++.h>
using namespace std;

void solve(string text,string pat)
{  
    int n=text.size();
    int m=pat.size();
     unordered_multiset<char> window;
     unordered_multiset<char> pattern;
     for(auto ch:pat)
     {
         pattern.insert(ch);
     }
     int  i;
     for(i=0;i<n;i++)
     {
         if(i<m)
         {
             window.insert(text[i]);
         }

         else
         {
             if(window==pattern)
             {
                 cout<<text.substr(i-m,m)<<" "<<endl;
             }
             auto it=window.find(text[i-m]);
             if(it!=window.end())
             {
                 window.erase(it);
             }
             window.insert(text[i]);
         }
     }

     if(window==pattern){
         cout<<text.substr(i-m,m)<<" ";
     }
}

int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    solve(a,b);
}
