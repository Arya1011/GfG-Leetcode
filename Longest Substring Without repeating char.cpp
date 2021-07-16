class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.size();
        unordered_map<char,int> mp;
        int ans=0;
        
        int left=0;
        int right=0;
        
        while(right<n){
            
            if(mp.find(s[right])!=mp.end()){
                //bring left pointer to one ahead of previous occurence
                left=max(mp[s[right]]+1,left);
            }
            
            mp[s[right]]=right;
            ans=max(ans,right-left+1);
            right++;
        }
        
        return ans;
        
    }
};
