
class Solution {
public:
    unordered_map<string,vector<string>> mp;
    vector<string> wordBreak(string s, vector<string>& dict) 
    {
        
         if(mp.find(s)!=mp.end())
         {
             return mp[s];
         }
         vector<string> ans;
        for(auto w:dict)
        {
            if(s.substr(0,w.length())==w)
            {
                if(s.length()==w.length())
                {
                    ans.push_back(w);        
                }
                
                else
                {
                    vector<string> temp=wordBreak(s.substr(w.length()),dict);
                    string st="";
                    for(auto t:temp)
                    {
                        ans.push_back(w+" "+t);
                    }    
                    
                }
            }
        }
        return mp[s]=ans;
    }
};
