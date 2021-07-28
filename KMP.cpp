


//KMP Algorithm

#include<bits/stdc++.h>
using namespace std;

void preprocess(int*lps,string p,int m)
{
       int j=0;
       lps[0]=0;
       int i=1;
       while(i<m)
       {
            if(p[i]==p[j])
            {
                lps[i]=j+1;
                i++;
                j++;
            }
            else
            {
                if(j!=0)
                {
                    j=lps[j-1];
                }

                else
                {
                    lps[i]=0;
                    i++;
                }
            }
       }
}


void KMP(string s,string p)
{
      int n=s.size();
      int m=p.size();
      int lps[m];
      preprocess(lps,p,m);

      int i=0;
      int j=0;

      while(i<n){
          if(s[i]==p[j]){
              i++;
              j++;
          }

           //match found
           if(j==m){

                 cout<<"Pattern at index "<<(i-j)<<endl;
                 j=lps[j-1];

           }

          else if(i<n && p[j]!=s[i]){
              if(j==0){
                  i=i+1;
              }

              else{
                  j=lps[j-1];
              }
          }
      }



}


int main(){
    string s,p;
    cin>>s;
    cin>>p;

    KMP(s,p);

}
