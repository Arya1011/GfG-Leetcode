

#include <bits/stdc++.h>
using namespace std;

bool func(string s1,string s2){
  
        string temp;

        temp=s1+s1;

        for(int i=0;i<s1.length();i++){
             if(s2==temp.substr(i,s2.length())){
                 return true;
             }
        }
return false;

}


int main() {
    
    string s1;
    getline(cin,s1);

    string s2;

    getline(cin,s2);

    if(func(s1,s2)){
        cout<<"Yes"<<endl;
    }

    else{
        cout<<"No"<<endl;
    }
    
    
    }
