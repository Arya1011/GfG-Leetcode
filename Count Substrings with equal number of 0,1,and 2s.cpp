long long getSubstringWithEqual012(string str)
{
    //code here.
    
    long long cnt0=0,cnt1=0,cnt2=0;
    
    long long ans=0;
    
    unordered_map<string,int> mp;
    
    string pat=to_string(cnt2-cnt1)+" "+to_string(cnt1-cnt0);
    
    mp.insert({pat,1});
    
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='0')cnt0++;
        else if(str[i]=='1')cnt1++;
        else cnt2++;
        string tmp=to_string(cnt2-cnt1)+" "+to_string(cnt1-cnt0);
        if(mp.find(tmp)!=mp.end()){
            ans+=mp[tmp];
        }
        mp[tmp]+=1;
    }
    
    return ans;
}
