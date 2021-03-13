

class Solution {
public:
    string reorganizeString(string S) 
    {
        int n=S.length();
        unordered_map<char,int> mp;
        for(auto ch:S){
            mp[ch]++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        //characters according to frequecy
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        string ans;
        pair<int,char> prev={0,'*'};
        while(!pq.empty())
        {
            pair<int,char> curr=pq.top();
            pq.pop();
            ans.push_back(curr.second);           
            if(prev.first>0){
                pq.push(prev);
            }
            curr.first--;
            prev=curr;            
        }
        
        if(ans.length()!=n)
        {
            return "";
        }
        return ans;
    }
};
