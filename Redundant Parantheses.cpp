#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool solve()
{
    
    string s;
    getline(cin,s);
    stack<char> st;

    for(int i=0;i<s.size();i++)
    {
 
            if(s[i]==')')
            {
                 char top=st.top();
                 bool flag=true;
                 while(!st.empty() && st.top()!='(')
                 {
                      if(top=='*' || top=='+' || top=='-' || top=='/'){
                            flag=false;
                      }
                      st.pop();
                     top=st.top();
                 }
                 if(flag==true){
                     return true;
                 }
                 st.pop();
            }
            else{
                st.push(s[i]);
            }
    }
 return false;
}







int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(solve()){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

