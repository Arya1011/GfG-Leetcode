
//O(nlogk)

class compare{
  public:
    bool operator()(pair<string,int>p1,pair<string,int>p2){
          
         
           if(p1.second==p2.second){
               return p1.first<p2.first;
           }
        
         return p1.second>p2.second;
    }
    
    
};


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        
        map<string,int> mp;
        
        for(auto word:words){
            mp[word]++;
        }
        
        priority_queue<pair<string,int>,vector<pair<string,int>>,compare> pq;
        
        
        for(auto it:mp){
            pq.push(it);
            while(pq.size()>k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
