

class Trie
{
    public:
      Trie*next[26];
      bool terminal;
    
      Trie()
      {
          for(int i=0;i<26;i++){
              next[i]=NULL;
          }
          
          terminal=false;
      }
    
    void insert(Trie*root,string word)
    {
         for(auto ch:word)
         {
             if(!root->next[ch-'a'])
             {
                 root->next[ch-'a']=new Trie();
             }
             root=root->next[ch-'a'];
         }
        root->terminal=true;
    }
    
};



bool helper(Trie*root,string&prefix,vector<string>&words)
{
       if(root->terminal)
       {
           words.push_back(prefix);
       }
    
       if(words.size()==3){
           return true;
       }
    
       for(int i=0;i<26;i++)
       {
           if(root->next[i]!=NULL)
           {
               prefix+=(char)(i+'a');    
               if(helper(root->next[i],prefix,words))
               {
                   return true;
               }
               prefix.pop_back();
           }
       }
    return false;
}



class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        vector<vector<string>> sugg(searchWord.size());
        Trie*root=new Trie();
        for(auto s:products){
            root->insert(root,s);
        }
        string prefix="";
        for(int i=0;i<searchWord.size();i++)
        {
                if(root->next[searchWord[i]-'a'])
                {
                     root=root->next[searchWord[i]-'a'];    
                }
            
                else
                {
                    break;
                }
            
               prefix=searchWord.substr(0,i+1);
               helper(root,prefix,sugg[i]);
        }
        return sugg; 
    }
};
