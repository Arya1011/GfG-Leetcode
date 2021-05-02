#include<bits/stdc++.h>
using namespace std;
void solve(){
    
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        stack<char> st;
        int i=0;
        int n=s.size();
        int open=0;
        int closed=0;
        while(i<n){
            
            if(s[i]=='{'){
                st.push(s[i]);
            }
            
            if(s[i]=='}'){
                if(st.empty()){
                    closed++;
                }
                
                else{
                    st.pop();
                }
            }
            
            i++;
        }
        
        while(!st.empty()){
            open++;
            st.pop();
        }
        
        //cout<<open<<" "<<closed<<'\n';
        
        if((open+closed)%2==1){
            cout<<-1<<endl;
        }
        
        else{
             cout<<ceil(float(open)/2.0)+ceil(float(closed)/2.0)<<endl;
        }
       
        
    }
}



int main() {
	//code
	
	
	solve();
	
	return 0;
}
