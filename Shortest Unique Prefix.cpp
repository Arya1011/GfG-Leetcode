#include<bits/stdc++.h>
using namespace std;

class Trie
{
   public:
       bool terminal;
       Trie* next[256];
       int freq;

  
      Trie(){
          terminal=false;
            for(int i=0;i<256;i++)
      {
           next[i]=NULL;
      }

      freq=1;

      }
};

Trie*root;

    void insert(Trie* root,string s)
      {
              int n=s.size();
              Trie*curr=root;
              for(int i=0;i<n;i++)
              {
                   if(curr->next[s[i]-'a']==NULL)
                   {
                       curr->next[s[i]-'a']=new Trie();
                   }
                   else
                   {
                          curr->next[s[i]-'a']->freq++;
                   }
                   curr=curr->next[s[i]-'a'];
              }
              return; 
      }


void prefix_util(Trie*root,char prefix[],int idx)
{
    if(root==NULL)
    {
        return;
    }

    //unique prefix found
    if(root->freq==1)
    {
         prefix[idx]='\0';
         cout<<prefix<<endl;
         return;
    }


     for(int i=0;i<256;i++)
     {
            if(root->next[i]!=NULL)
            {
                prefix[idx]='a'+i;
                prefix_util(root->next[i],prefix,idx+1);
            }
     }
}



void prefix(Trie*root)
{
    root->freq=0;
     char prefix[500];
     int idx=0;
     prefix_util(root,prefix,idx);   
}


int main()
  {
    root=new Trie();
    vector<string> words;
    int n;
    cin>>n;
    while(n--)
    {
        string w;
        cin>>w;
        words.push_back(w);
    }
    for(int i=0;i<words.size();i++)
    {
        insert(root,words[i]);
    }
    prefix(root);
  }
