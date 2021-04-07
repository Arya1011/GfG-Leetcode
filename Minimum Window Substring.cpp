
class Solution{
    public:
    string smallestWindow (string s, string p){
        // Your code here
        
        int len1=s.size();
        int len2=p.size();
        
        if(len1<len2){
            return "-1";
        }
        
        vector<int> hash_st(256,0);
        vector<int> hash_pat(256,0);
        
        
        for(int i=0;i<len2;i++){
            hash_pat[p[i]]++;
        }
        
        int start=0;
        int min_start=-1;
        int len=0;
        int min_len=INT_MAX;
        int count=0;
        for(int i=0;i<len1;i++)
        {
            hash_st[s[i]]++;
            //pattern should contain and string must have lessr amount
            if(hash_pat[s[i]]!=0 && hash_st[s[i]]<=hash_pat[s[i]])
            {
                count++;
            }
            
            //all charcaters found
            if(count==len2)
            {
                
                while(hash_st[s[start]]>hash_pat[s[start]] || hash_pat[s[start]]==0)
                {
                     //window restrict krne ka condition
                        hash_st[s[start]]--;
                         start++;
                }
            
            len=i-start+1;
            if(len<min_len)
            {
                min_len=min(min_len,len);
                min_start=start;
            }
                
                
            }
            
            
        }
        
        
        if(min_start==-1){
            return "-1";
        }
        
        return s.substr(min_start,min_len);
    }
};
