//https://leetcode.com/problems/longest-string-chain/

class Solution {
public:
    
  
    
    int dfs(string w,unordered_set<string> &S,unordered_map<string,int>&mp)
    {
        if(mp.find(w)!=mp.end()){
            return mp[w];
        }
        int n=w.size();
        int max_len=1;      
        for(int i=0;i<n;i++){
            string newString=w.substr(0,i) + w.substr(i+1);
            
            //if exists
            if(S.find(newString)!=S.end())
            {
                int curr_len=1+dfs(newString,S,mp);
                max_len=max(max_len,curr_len);
            }
        }
        
        mp[w]=max_len;
        return max_len;
    }
    
    
    
    int longestStrChain(vector<string>& words) {
        
        
        int ans=INT_MIN;
        unordered_set<string> S(words.begin(),words.end());
        unordered_map<string,int> mp;
        for(auto &w:words)
        {
            ans=max(ans,dfs(w,S,mp));
        }
        return ans;
        
    }
};
