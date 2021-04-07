

class Trie{
public:
    Trie*next[26];
    bool terminal;
    
    
    Trie()
    {
         terminal=false;
          for(int i=0;i<26;i++)
        {
        next[i]=NULL;
        }
    }
};



Trie*root;



void insert(string s)
{
    Trie*curr=root;
    for(int i=0;i<s.size();i++)
    {
        if(curr->next[s[i]-'a']==NULL){
            curr->next[s[i]-'a']=new Trie();
        }
        curr=curr->next[s[i]-'a'];    
    }
    curr->terminal=true;
}


int count(Trie*curr,int &idx)
{
    int children=0;
    for(int i=0;i<26;i++)
    {
        if(curr->next[i]!=NULL)
        {
            children++;
            idx=i;   
        }   
    }
    return children; 
}


string search(){
    
      Trie*curr=root;
      int idx=0;
       string prefix="";
      while(curr->terminal==false && count(curr,idx)==1){
          curr=curr->next[idx];
          prefix.push_back('a'+idx);
          
      }
    
   return prefix;


}





//O(length(longest prefix))-->Search
//O(max(length(strs[i]))-->Insertion
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        root=new Trie();
    
        //insert in trie
        for(int i=0;i<strs.size();i++)
        {
            insert(strs[i]);
        }
        
        
        string prefix=search();
        return prefix;
    }
};
